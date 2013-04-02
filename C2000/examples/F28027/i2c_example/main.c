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

#include "f2802x_common/include/F2802x_I2c_defines.h"



extern void DSP28x_usDelay(Uint32 Count);

// Prototypes
interrupt void adc_isr(void);
interrupt void i2c_int1(void);


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


uint32_t isr_counter = 0;
uint16_t ConversionCount = 0;

uint16_t num_rec_slave_addr = 0; // Number of times i2c module has recognized it's own slave address(or 0x00 -- general call) on the bus
uint16_t num_bytes_moved_to_tx_shift = 0; // Number of bytes that have moved to the transmit shift register from the data transmit register (as counted by XRDY interrupt)



void init_i2c(){

	EALLOW;
	// Enable Clock routing to the I2C Module
	SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 1;
	EDIS;

	///////////////////////////////////////////////
	///////       GPIO Setup             //////////
	//////    SDA: GPIO28, SCLL GPIO29   //////////
	///////////////////////////////////////////////



	//Pull-ups are enabled here for ease of debugging. DISABLE pullups for production -- They are are on the master side!!!
	GPIO_setPullUp(myGpio,GPIO_Number_28, GPIO_PullUp_Disable);
	GPIO_setPullUp(myGpio,GPIO_Number_29, GPIO_PullUp_Disable);

	// Set qualifications type on SDA and SCL to async (digital signals from another micro don't need multiple validations)
	GPIO_setQualification(myGpio, GPIO_Number_28, GPIO_Qual_ASync);
	GPIO_setQualification(myGpio, GPIO_Number_29, GPIO_Qual_ASync);

	// Setup GPIO Modes
	GPIO_setMode(myGpio, GPIO_Number_28, GPIO_28_Mode_SDDA);
	GPIO_setMode(myGpio, GPIO_Number_29, GPIO_29_Mode_SCLA);

	///////////////////////////////////////////////
	//////////    Interrupt Setup    //////////////
	//////////////////////////////////////////////

	PIE_registerPieIntHandler(myPie, PIE_GroupNumber_8, PIE_SubGroupNumber_1, (intVec_t)&i2c_int1);
	PIE_enableInt(myPie, PIE_GroupNumber_8, PIE_InterruptSource_I2CA1);
	CPU_enableInt(myCpu,CPU_IntNumber_8);  // Enable the CPU interrupt that is responsible for this PIE group

	// Clear all status bits for the i2c module (reset)
	I2caRegs.I2CMDR.bit.IRS = 0;   // Technically this triggers a i2c reset




	// Enable i2c "addressed as slave" interrupt
	I2caRegs.I2CIER.bit.AAS = 1;

	// Enable the XRDYINT (Transmit read condition interrupt). Enabled so I can see if data is getting to the transmit shift register
	I2caRegs.I2CIER.bit.XRDY = 1;




	// Change Clock divider
	I2caRegs.I2CPSC.all = 2;       // Prescaler - set to 128 giving module clk of SYSCLKOUT/129 => 465kHz

	// More clock stuff here
	I2caRegs.I2CCLKL = 5;			// NOTE: must be non zero
	I2caRegs.I2CCLKH = 5;			// NOTE: must be non zero


	// Setup the i2c module in slave mode
	I2caRegs.I2CMDR.bit.MST = 0;

	// Setup the i2c module as a receiver (so now we are in slave-reciever mode)
	I2caRegs.I2CMDR.bit.TRX = 0;

	// 7BIT address mode
	I2caRegs.I2CMDR.bit.XA = 0;

	// 8bit data mode
	I2caRegs.I2CMDR.bit.BC = 0;


	I2caRegs.I2CIER.bit.RRDY = 1;   // Enable Receive Interrupt

	// Set i2c address of this module
	I2caRegs.I2COAR = 0x50;

	I2caRegs.I2CCNT = 4;	        // Get/send 4 bytes

	I2caRegs.I2CDXR = 0xF5; // Fill the transmission buffer



	// Re-Enable the Module now that configuration is done
	I2caRegs.I2CMDR.bit.IRS = 1;




}



inline void setup_handles(void){
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



inline void sys_init(){
	// Perform basic system initialization
		WDOG_disable(myWDog);
		CLK_enableAdcClock(myClk);
		(*Device_cal)();
	//	CLK_disableAdcClock(myClk);

		//Select the internal oscillator 1 as the clock source
		CLK_setOscSrc(myClk, CLK_OscSrc_Internal);

		// Setup the PLL for x12 /2 which will yield 50Mhz = 10Mhz * 10 / 2
		PLL_setup(myPll, PLL_Multiplier_12, PLL_DivideSelect_ClkIn_by_2);

		// Disable the PIE and all interrupts
		PIE_disable(myPie);
		PIE_disableAllInts(myPie);
		CPU_disableGlobalInts(myCpu);
		CPU_clearIntFlags(myCpu);

		// If running from flash copy RAM only functions to RAM
	#ifdef _FLASH
		memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

		setup_flash(myFlash);
	#endif


		// Setup a debug vector table and enable the PIE
		PIE_setDebugIntVectorTable(myPie);
		PIE_enable(myPie);

}



int main(void) {
	setup_handles();

	sys_init();

    init_i2c();


	// Enable global Interrupts and higher priority real-time debug events
	CPU_enableGlobalInts(myCpu);
	CPU_enableDebugInt(myCpu);

//

	while(1){
//		bob++;
	}



}


interrupt void i2c_int1(void){
	isr_counter++;
	Uint16 IntSource;

	IntSource = I2caRegs.I2CISRC.all;

	if( IntSource == I2C_AAS_ISRC){
		num_rec_slave_addr++;
	}

	if (IntSource == I2C_TX_ISRC){

		num_bytes_moved_to_tx_shift ++;
		I2caRegs.I2CSTR.bit.XRDY = 1; // Clear the XRDY interrupt (re-arm it) since it does not get auto-cleared by reading I2CISRC
		I2caRegs.I2CDXR = 0xF5; // Fill the transmission buffer
	}


	// Acknowledge this interrupt to receive more interrupts from group 8
	PIE_clearInt(myPie, PIE_GroupNumber_8);
}


