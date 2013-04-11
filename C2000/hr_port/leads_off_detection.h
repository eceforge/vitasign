/*
 * leads_off_detection.h
 *
 *  Created on: Apr 9, 2013
 *      Author: adrian
 */

#ifndef LEADS_OFF_DETECTION_H_
#define LEADS_OFF_DETECTION_H_

interrupt void leads_off_isr1(void);
interrupt void leads_off_isr2(void);

uint8_T leads_off_alarm = 0; // Will be set to 1 or 2 if leads get pulled
int leads_off_isr_counter = 0; // Keeps track of how many times we have gone into the leads off isr
extern int32_T heart_rate_avg;

void InitLeadsOffDetection(void){
	// Setup GPIO 0 and 1 to inputs
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;

	// Setup GPIO to have large qualifications
	GpioCtrlRegs.GPACTRL.bit.QUALPRD0 = 0xFF; // Set GPIO0-7 to max qualification

	// Setup GPIOs to have even larger qualifications
	GpioCtrlRegs.GPAQSEL1.bit.GPIO1 = 2; // Set to be 6 windows of length set by GPACTRL
	GpioCtrlRegs.GPAQSEL1.bit.GPIO2 = 2; // Same for GPIO2

	// Setup GPIO 0 and 1 to run as interrupt triggers
	GpioIntRegs.GPIOXINT1SEL.all = 1; // GPIO0 triggers XINT1
	GpioIntRegs.GPIOXINT2SEL.all = 2; // GPIO1 triggers XINT2

	// Configure the interrupt requirements
	XIntruptRegs.XINT1CR.all = 3; // AKA 0b11 -- Trigger Xint1 on both raising and falling edges of GPIO
	XIntruptRegs.XINT2CR.all = 3; // AKA 0b11 -- Trigger Xint2 on both raising and falling edges of GPIO





	PieCtrlRegs.PIEIER1.bit.INTx5 = 1; // Enable XINT2 in PIE
	PieCtrlRegs.PIEIER1.bit.INTx4 = 1; // Enable XINT1 in PIE

	PieVectTable.XINT1 = &leads_off_isr1; // Register Interrupt for XINT1 with the PIE handler
	PieVectTable.XINT2 = &leads_off_isr1; // Register Interrupt for XINT2 with the PIE handler
	IER |= M_INT1; // Enable group 1 interrupts


	EDIS;

}

/*
 *
 * This interrupt should trigger EITHER when leads go off OR when they come back on again.
 */
interrupt void leads_off_isr1(void){
	GpioDataRegs.GPBSET.bit.GPIO34 = 1; // Turn off the GPIO 34 LED


	leads_off_alarm = 0; // Release the lock, both leads are back on now

	leads_off_isr_counter++;
	DELAY_US(2000);
	int lead_1_status = GpioDataRegs.GPADAT.bit.GPIO1;
	int lead_2_status = GpioDataRegs.GPADAT.bit.GPIO2;
	if( lead_1_status == 1 || lead_2_status == 1){ // Only when leads have gone off
		leads_off_alarm = 1;
//		heart_rate_avg = 75776; // Prevent future toggles bpm=74
		heart_rate_avg = 2048;
	}



	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

interrupt void leads_off_isr2(void){
	GpioDataRegs.GPBSET.bit.GPIO34 = 1; // Turn off the GPIO 34 LED

	leads_off_alarm = 2;
	heart_rate_avg = -2; // fill the buffer with error code

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}



#endif /* LEADS_OFF_DETECTION_H_ */
