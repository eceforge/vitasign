//###########################################################################
// Description:
//! \addtogroup f2806x_example_list
//! <h1>ePWM Timer Interrupt From Flash (flash_f28069)</h1>
//!
//! This example runs the ePWM interrupt example from flash. ePwm1 Interrupt 
//! will run from RAM and puts the flash into sleep mode. ePwm2 Interrupt 
//! will run from RAM and puts the flash into standby mode. ePWM3 Interrupt
//! will run from FLASH. All timers have the same period. The timers are 
//! started sync'ed. An interrupt is taken on a zero event for each ePWM 
//! timer.GPIO34 is toggled while in the background loop.
//! Note:
//!   - ePWM1: takes an interrupt every event
//!   - ePWM2: takes an interrupt every 2nd event
//!   - ePWM3: takes an interrupt every 3rd event 
//! Thus the Interrupt count for ePWM1, ePWM4-ePWM6 should be equal
//! The interrupt count for ePWM2 should be about half that of ePWM1
//! and the interrupt count for ePWM3 should be about 1/3 that of ePWM1
//! 
//! Follow these steps to run the program.
//!   - Build the project
//!   - Flash the .out file into the device.
//!   - Set the hardware jumpers to boot to Flash (put position 1 and 2 of 
//!     SW2 on control Card to ON position).
//!   - Use the included GEL file to load the project, symbols
//!     defined within the project and the variables into the watch
//!     window.
//! 
//! Steps that were taken to convert the ePWM example from RAM
//! to Flash execution: 
//! - Change the linker cmd file to reflect the flash memory map.
//! - Make sure any initialized sections are mapped to Flash.
//!   In SDFlash utility this can be checked by the View->Coff/Hex
//!   status utility. Any section marked as "load" should be
//!   allocated to Flash.
//! - Make sure there is a branch instruction from the entry to Flash
//!   at 0x3F7FF6 to the beginning of code execution. This example
//!   uses the DSP0x_CodeStartBranch.asm file to accomplish this.
//! - Set boot mode Jumpers to "boot to Flash"
//! - For best performance from the flash, modify the waitstates
//!   and enable the flash pipeline as shown in this example.
//!   Note: any code that manipulates the flash waitstate and pipeline
//!   control must be run from RAM. Thus these functions are located
//!   in their own memory section called ramfuncs.
//! 
//! \b Watch \b Variables \n
//!  - EPwm1TimerIntCount
//!  - EPwm2TimerIntCount
//!  - EPwm3TimerIntCount
//
//###########################################################################
// $TI Release: F2806x C/C++ Header Files and Peripheral Examples V135 $
// $Release Date: Sep 8, 2012 $
//###########################################################################

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "string.h"



// Configure the period for each timer
#define PWM1_TIMER_TBPRD   18750



// Functions that will be run from RAM need to be assigned to
// a different section.  This section will then be mapped using
// the linker cmd file.
#pragma CODE_SECTION(epwm1_timer_isr, "ramfuncs");
#pragma CODE_SECTION(adc_isr, "ramfuncs");
#pragma CODE_SECTION(InitFlash, "ramfuncs");

// Prototype statements for functions found within this file.
interrupt void epwm1_timer_isr(void);
interrupt void adc_isr(void);
void InitEPwmTimer(void);
void init_adc(void);

// Global variables used in this example
Uint32  EPwm1TimerIntCount;
Uint32  LoopCount;

Uint16 Voltage1[100]; // Used to store the data from the ADC
Uint16 Voltage2[100];

Uint16 ConversionCount; // Used to count how many conversions the ADC has done (maxes out at 9 convesions then restarts)


// These are defined by the linker (see F2808.cmd)
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsLoadSize;

void main(void)
{

// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the F2806x_SysCtrl.c file.
   InitSysCtrl();

// Step 2. Initialize GPIO:
// This example function is found in the F2806x_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
// InitGpio();  // Skipped for this example

// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts
   DINT;

// Initialize the PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.
// This function is found in the F2806x_PieCtrl.c file.
   InitPieCtrl();

// Disable CPU interrupts and clear all CPU interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table, even if the interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in F2806x_DefaultIsr.c.
// This function is found in F2806x_PieVect.c.
   InitPieVectTable();


// Copy time critical code and Flash setup code to RAM
// This includes the following ISR functions: epwm1_timer_isr(), and InitFlash();
// The  RamfuncsLoadStart, RamfuncsLoadSize, and RamfuncsRunStart
// symbols are created by the linker. Refer to the F28069.cmd file.
   memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (Uint32)&RamfuncsLoadSize);

// Call Flash Initialization to setup flash waitstates
// This function must reside in RAM
   InitFlash();




// Step 4. Initialize all the Device Peripherals:
// This function is found in F2806x_InitPeripherals.c
// InitPeripherals();  // Not required for this example
   InitEPwmTimer();    // For this example, only initialize the ePWM Timers
   init_adc();

// Step 5. User specific code, enable interrupts:





   LoopCount = 0;


// Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global interrupt INTM
   ERTM;   // Enable Global realtime interrupt DBGM

// Step 6. IDLE loop. Just sit and loop forever (optional):
   EALLOW;
   GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0; // Set as gpio
   GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1; // Set as output
   EDIS;

   for(;;)
   {
       // This loop will be interrupted, so the overall
       // delay between pin toggles will be longer.

   }

}

void init_adc(){



	   InitAdc();  // Initialize the ADC (turns on ADC, turns on the ref and waits for it to stabilize...etc)


	   // Configure ADC
	   EALLOW; // Allow me to write to these protected Registers
	   AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 1;	// Enable non-overlap mode
	   AdcRegs.ADCCTL1.bit.INTPULSEPOS	= 1;	// ADCINT1 trips after AdcResults latch
	   AdcRegs.INTSEL1N2.bit.INT1E     = 1;	// Enabled ADCINT1
	   AdcRegs.INTSEL1N2.bit.INT1CONT  = 0;	// Disable ADCINT1 Continuous mode
	   AdcRegs.INTSEL1N2.bit.INT1SEL 	= 0;    // setup EOC0 to trigger ADCINT1 to fire
	   AdcRegs.ADCSOC0CTL.bit.CHSEL 	= 4;    // set SOC0 channel select to ADCINA4
	   AdcRegs.ADCSOC0CTL.bit.TRIGSEL 	= 5;    // set SOC0 start trigger on EPWM1A, due to round-robin SOC0 converts first then SOC1
	   AdcRegs.ADCSOC0CTL.bit.ACQPS 	= 6;	// set SOC0 S/H Window to 7 ADC Clock Cycles, (6 ACQPS plus 1)
	   EDIS; // Lock out all protected registers




	   // Remap the adc_isr to our own isr
	   EALLOW;  // This is needed to write to EALLOW protected register
	   PieVectTable.ADCINT1 = &adc_isr;
	   EDIS;    // This is needed to disable write to EALLOW protected registers


	   PieCtrlRegs.PIEIER1.bit.INTx1 = 1;	// Enable INT 1.1 in the PIE
	   IER |= M_INT1; 						// Enable CPU Interrupt 1 to allow PIE group 1 to make it to the CPU
	   // Don't Forget to enable global interrupts after call to this function, they are not enabled here in case this function is called before user is ready to enable all interrupts
	   // can be done like so:
	   // EINT;          						// Enable Global interrupt INTM

}


void InitEPwmTimer()
{
	// Initalize counters:
	   EPwm1TimerIntCount = 0;

   // Interrupts that are used in this example are re-mapped to
   // ISR functions found within this file.
      EALLOW;  // This is needed to write to EALLOW protected registers
      PieVectTable.EPWM1_INT = &epwm1_timer_isr;


   EDIS;    // This is needed to disable write to EALLOW protected registers
   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Stop all the TB clocks
   EDIS;

   InitEPwm1Gpio();

   // Setup pwm clock
   EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
   EPwm1Regs.TBCTL.bit.CLKDIV    = 5; // Divide by 32 ( binary 101 )


   // Setup Sync
   EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;  // Disable Sync output (no chaining, so not necssary)
   EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;	// Disable phase loading (since we aren't chaining pwms together)


   // Setup Counting Properties
   EPwm1Regs.TBPRD = PWM1_TIMER_TBPRD;
   EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;    // Count up
   EPwm1Regs.TBCTR = 0x0 ; // Clear the counter	in prep. for first count

   // Setup PWM to trigger ADC through SOC-A
   EPwm1Regs.ETSEL.bit.SOCAEN = 1; // Enable the SOC-A line to the ADC
   EPwm1Regs.ETSEL.bit.SOCASEL = 1; // Trigger the SOC on Counter Equal Zero event
   EPwm1Regs.ETPS.bit.SOCAPRD = 1; // Send trigger down SOC A every 1 times that Counter Equal zero event occurs (as opposed to every 2 or 3 times)

   // Enable CPU INT3 which is connected to EPWM1-3 INT:
      IER |= M_INT3;



   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;         // Start all the timers synced
   EDIS;

}

// This ISR MUST be executed from RAM as it will put the Flash into Sleep
// Interrupt routines uses in this example:
interrupt void epwm1_timer_isr(void)
{

   // Put the Flash to sleep
   EALLOW;
   FlashRegs.FPWR.bit.PWR = FLASH_SLEEP;
   EDIS;
   
   EPwm1TimerIntCount++;

   // Clear INT flag for this timer
   EPwm1Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void adc_isr(void){
	LoopCount++;
	GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;

	  Voltage1[ConversionCount] = AdcResult.ADCRESULT0;
	  Voltage2[ConversionCount] = AdcResult.ADCRESULT1;

	  // If 20 conversions have been logged, start over
	  if(ConversionCount == 99)
	  {
	     ConversionCount = 0;
	  }
	  else ConversionCount++;

	  AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;		//Clear ADCINT1 flag reinitialize for next SOC
	  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE
}

//===========================================================================
// No more.
//===========================================================================

