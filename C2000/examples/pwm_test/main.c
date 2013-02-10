/*
 * main.c
 */
#define _DEBUG
//#define _FLASH

#include "DSP28x_Project.h"     // DSP28x Header file

#include "f2802x_common/include/pll.h"
#include "f2802x_common/include/clk.h"
#include "f2802x_common/include/wdog.h"

#include "f2802x_common/include/flash.h"
#include "f2802x_common/include/gpio.h"
#include "f2802x_common/include/pie.h"
#include "f2802x_common/include/adc.h"
#include "f2802x_common/include/sci.h"

extern void DSP28x_usDelay(Uint32 Count);

// Prototypes
interrupt void adc_isr(void);


// you probably need these
CPU_Handle myCpu;
PLL_Handle myPll;
WDOG_Handle myWDog;
CLK_Handle myClk;

// these are optional
ADC_Handle myAdc;
FLASH_Handle myFlash;
GPIO_Handle myGpio;
PIE_Handle myPie;
SCI_Handle mySci;
PWM_Handle myPwm1;

uint32_t bob = 0;
uint32_t isr_counter = 0;
uint16_t ConversionCount = 0;
uint16_t Voltage1[10];

void setup_handles(void){
	myClk = CLK_init((void *)CLK_BASE_ADDR, sizeof(CLK_Obj));
	myPll = PLL_init((void *)PLL_BASE_ADDR, sizeof(PLL_Obj));
	myWDog = WDOG_init((void *)WDOG_BASE_ADDR, sizeof(WDOG_Obj));
	myCpu = CPU_init((void *)NULL, sizeof(CPU_Obj));

	myFlash = FLASH_init((void *)FLASH_BASE_ADDR, sizeof(FLASH_Obj));
	myGpio = GPIO_init((void *)GPIO_BASE_ADDR, sizeof(GPIO_Obj));
	myPie = PIE_init((void *)PIE_BASE_ADDR, sizeof(PIE_Obj));
	mySci = SCI_init((void *)SCIA_BASE_ADDR, sizeof(SCI_Obj));
	myAdc = ADC_init((void *)ADC_BASE_ADDR, sizeof(ADC_Obj));
	myPwm1 = PWM_init((void *)PWM_ePWM1_BASE_ADDR, sizeof(PWM_Obj));

}


void init_adc(){
	/*
		With Bandgap enabled outputs will be:
		input<=0   => 	Digital Value = 0
		0<input<3.3v   => Digital Value = 4096[(Input-VREFLO)/3.3v]
		input>=VREFHI	=> Digital Value = 4095
	*/
	ADC_enableBandGap(myAdc);	// Setup internal ref voltage 0v-3v
	ADC_enableRefBuffers(myAdc);	// I'm not sure what this does. Examples do it.
	ADC_powerUp(myAdc);
	ADC_enable(myAdc);
	ADC_setVoltRefSrc(myAdc, ADC_VoltageRefSrc_Int);
	// Enable ADCINT1 in PIE, if not enabled int flag will stay high until cleared by SW
	PIE_enableAdcInt(myPie, ADC_IntNumber_1);
	// Enable CPU interrupt 1 (must match the PIE group(not subgroup) number)
	CPU_enableInt(myCpu, CPU_IntNumber_10);

	// These are usually set before this by system init, but just in case we also do it here:

	// Enable Global Interrupts (Allows PIE int to get to the CPU)
	CPU_enableGlobalInts(myCpu);
	// Enable Realtime Global INT debug
	CPU_enableDebugInt(myCpu);

	ADC_setIntPulseGenMode(myAdc, ADC_IntPulseGenMode_Prior);               //ADCINT1 trips after AdcResults latch
	ADC_enableInt(myAdc, ADC_IntNumber_1);                                  //Enabled ADCINT1
	ADC_setIntMode(myAdc, ADC_IntNumber_1, ADC_IntMode_ClearFlag);          //Disable ADCINT1 Continuous mode
//	ADC_setIntSrc(myAdc, ADC_IntNumber_1, ADC_IntSrc_EOC0);                 //setup EOC2 to trigger ADCINT1 to fire
	ADC_setSocChanNumber (myAdc, ADC_SocNumber_0, ADC_SocChanNumber_A4);    //set SOC0 channel select to ADCINA4
	// Setup ADC to take input from the ePWM1 
	ADC_setSocTrigSrc(myAdc, ADC_SocNumber_0, ADC_SocTrigSrc_EPWM1_ADCSOCA);    //set SOC0 start trigger on EPWM1A
	ADC_setSocSampleWindow(myAdc, ADC_SocNumber_0, ADC_SocSampleWindow_7_cycles);   //set SOC0 S/H Window to 7 ADC Clock Cycles, (6 ACQPS plus 1)
	

	
}


void InitPwm(){

	CLK_enablePwmClock(myClk,PWM_Number_1);
	
	// Setup Time Base Clock (TBCLK)
	PWM_setCounterMode(myPwm1, PWM_CounterMode_Up);       // Set to count up
	PWM_setPeriod(myPwm1, 6200);                           // Setup period of timer(pwm)
	PWM_disableCounterLoad(myPwm1);                       // Disable phase loading
	PWM_setPhase(myPwm1, 0x0000);                         // Phase is 0
	PWM_setCount(myPwm1, 0x0000);                         // Clear counter
	PWM_setHighSpeedClkDiv(myPwm1, PWM_HspClkDiv_by_1);   // Clock ratio to SYSCLKOUT
	PWM_setClkDiv(myPwm1, PWM_ClkDiv_by_32);			  // Another multiplicative clk divider
	PWM_setCmpA(myPwm1, 5);                               // Set comparator value
	
	// Setup PWM to trigger the ADC through SOC-A
	PWM_enableSocAPulse(myPwm1);
	PWM_setSocAPulseSrc(myPwm1, PWM_SocPulseSrc_CounterEqualZero);
	PWM_setSocAPeriod(myPwm1, PWM_SocPeriod_FirstEvent);

	
	CLK_enableTbClockSync(myClk);                         // Release the TBCLK (and hence start the counter)
	

}

int main(void) {
	setup_handles();
	// Perform basic system initialization
	WDOG_disable(myWDog);
	CLK_enableAdcClock(myClk);
	(*Device_cal)();
//	CLK_disableAdcClock(myClk);

	//Select the internal oscillator 1 as the clock source
	CLK_setOscSrc(myClk, CLK_OscSrc_Internal);

	// Setup the PLL for x10 /2 which will yield 50Mhz = 10Mhz * 10 / 2
	PLL_setup(myPll, PLL_Multiplier_10, PLL_DivideSelect_ClkIn_by_2);

	// Disable the PIE and all interrupts
	PIE_disable(myPie);
	PIE_disableAllInts(myPie);
	CPU_disableGlobalInts(myCpu);
	CPU_clearIntFlags(myCpu);

	// If running from flash copy RAM only functions to RAM
#ifdef _FLASH
	memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
#endif

	// Setup a debug vector table and enable the PIE
	PIE_setDebugIntVectorTable(myPie);
	PIE_enable(myPie);

	// Register interrupt handlers in the PIE vector table
	PIE_registerPieIntHandler(myPie, PIE_GroupNumber_10, PIE_SubGroupNumber_1, (intVec_t)&adc_isr);

	// Setup Signaling GPIO
    GPIO_setPullUp(myGpio, GPIO_Number_0, GPIO_PullUp_Disable);
    GPIO_setMode(myGpio, GPIO_Number_0, GPIO_0_Mode_GeneralPurpose);
    GPIO_setDirection(myGpio, GPIO_Number_0, GPIO_Direction_Output);

	init_adc();
	InitPwm();


	// Enable global Interrupts and higher priority real-time debug events
	CPU_enableGlobalInts(myCpu);
	CPU_enableDebugInt(myCpu);

	while(1){
		bob++;
	}



}


interrupt void adc_isr(void){

	isr_counter++;
	Voltage1[ConversionCount] = ADC_readResult(myAdc, ADC_ResultNumber_0);
    GPIO_toggle(myGpio, GPIO_Number_0);
	// If 10 conversions have been logged, start over
    if(ConversionCount == 9)
    {
        ConversionCount = 0;
    }
    else ConversionCount++;

	// Clear INT flag for this timer
	ADC_clearIntFlag(myAdc, ADC_IntNumber_1);

	// Acknowledge this interrupt to receive more interrupts from group 10
	PIE_clearInt(myPie, PIE_GroupNumber_10);
}
