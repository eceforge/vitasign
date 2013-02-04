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
interrupt void epwm1_isr(void);


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

void InitPwm(){

	CLK_enablePwmClock(myClk,PWM_Number_1);
	
	// Setup Time Base Clock (TBCLK)
	PWM_setCounterMode(myPwm1, PWM_CounterMode_Up);       // Set to count up
	PWM_setPeriod(myPwm1, 2000);                             // Setup period of timer(pwm)
	PWM_disableCounterLoad(myPwm1);                       // Disable phase loading
	PWM_setPhase(myPwm1, 0x0000);                         // Phase is 0
	PWM_setCount(myPwm1, 0x0000);                         // Clear counter
	PWM_setHighSpeedClkDiv(myPwm1, PWM_HspClkDiv_by_2);   // Clock ratio to SYSCLKOUT
	PWM_setClkDiv(myPwm1, PWM_ClkDiv_by_2);
	PWM_setCmpA(myPwm1, 5);                               // Set comparator value
	
	PWM_setIntMode(myPwm1, PWM_IntMode_CounterEqualZero); // Select INT on Zero event
	PWM_enableInt(myPwm1);                                // Enable INT
	PWM_setIntPeriod(myPwm1, PWM_IntPeriod_FirstEvent);   // Generate INT on 1st event
	CLK_enableTbClockSync(myClk);                         // Release the TBCLK
	

}

int main(void) {
	setup_handles();
	// Perform basic system initialization
	WDOG_disable(myWDog);
	CLK_enableAdcClock(myClk);
	(*Device_cal)();
	CLK_disableAdcClock(myClk);

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
	PIE_registerPieIntHandler(myPie, PIE_GroupNumber_3, PIE_SubGroupNumber_1, (intVec_t)&epwm1_isr);

	InitPwm();

	// Enable CPU INT3 which is connected to EPWM1-6 INT
    CPU_enableInt(myCpu, CPU_IntNumber_3);

    // Enable EPWM INTn in the PIE: Group 3 interrupt 1-6
    PIE_enablePwmInt(myPie, PWM_Number_1);

	// Enable global Interrupts and higher priority real-time debug events
	CPU_enableGlobalInts(myCpu);
	CPU_enableDebugInt(myCpu);

	while(1){
		bob++;
	}



}


interrupt void epwm1_isr(void){

	isr_counter++;

	// Clear INT flag for this timer
	PWM_clearIntFlag(myPwm1);

	// Acknowledge this interrupt to receive more interrupts from group 3
	PIE_clearInt(myPie, PIE_GroupNumber_3);
}
