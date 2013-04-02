/*
 * main.c
 */
#define _DEBUG
#define _FLASH



#include "DSP28x_Project.h"     // DSP28x Header file

#include "f2802x_common/include/pll.h"
#include "f2802x_common/include/clk.h"
#include "f2802x_common/include/wdog.h"

#include "f2802x_common/include/flash.h"
#include "f2802x_common/include/gpio.h"
#include "f2802x_common/include/pie.h"
#include "f2802x_common/include/adc.h"
#include "f2802x_common/include/sci.h"

#include "heart_rate_official_cport.h"
#include "heart_rate_official_cport_rtwutil.h"

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


uint32_t isr_counter = 0;
uint16_t ConversionCount = 0;
// Hardcoded DC values we expect to read from the ADC
//int32_T Voltage1[1000] = {1219,1218,1198,1160,1160,1163,1163,1170,1172,1175,1172,1170,1172,1171,1173,1173,1177,1198,1212,1200,1194,1192,1169,1153,1153,1153,1156,1162,1155,1133,1244,1796,2345,1729,500,414,977,1164,1162,1158,1171,1189,1198,1203,1203,1203,1207,1219,1235,1250,1263,1271,1278,1287,1298,1313,1337,1361,1371,1370,1359,1326,1271,1206,1142,1097,1080,1078,1084,1099,1122,1139,1148,1152,1151,1146,1139,1139,1148,1154,1155,1153,1150,1147,1146,1146,1142,1136,1134,1137,1141,1145,1149,1153,1156,1158,1158,1158,1158,1158,1158,1158,1160,1164,1171,1176,1177,1176,1173,1169,1166,1167,1170,1175,1181,1182,1177,1174,1171,1170,1172,1176,1178,1177,1180,1207,1222,1208,1203,1196,1174,1159,1160,1165,1168,1170,1159,1146,1376,2080,2417,1402,335,585,1093,1174,1156,1159,1175,1191,1200,1207,1208,1208,1211,1220,1236,1250,1261,1272,1283,1295,1307,1324,1344,1360,1361,1351,1335,1305,1260,1205,1150,1107,1084,1082,1090,1101,1117,1132,1144,1149,1151,1151,1148,1150,1156,1158,1154,1147,1143,1145,1151,1150,1145,1146,1150,1155,1156,1156,1157,1160,1165,1164,1162,1162,1163,1168,1171,1174,1175,1172,1169,1168,1170,1174,1178,1180,1179,1179,1181,1182,1179,1180,1185,1187,1191,1213,1231,1216,1207,1202,1175,1161,1170,1177,1180,1178,1167,1148,1279,1850,2355,1657,456,454,1008,1179,1184,1174,1185,1201,1208,1215,1220,1223,1228,1235,1245,1256,1269,1286,1301,1312,1331,1359,1385,1405,1410,1395,1372,1337,1274,1201,1141,1105,1092,1094,1106,1118,1128,1135,1138,1142,1146,1149,1154,1160,1165,1160,1151,1147,1145,1150,1152,1147,1150,1160,1165,1165,1160,1156,1153,1148,1141,1138,1143,1150,1155,1160,1164,1168,1164,1158,1155,1155,1157,1161,1164,1160,1159,1181,1204,1194,1183,1181,1163,1142,1140,1147,1155,1159,1153,1133,1150,1456,2064,2055,950,293,746,1128,1185,1174,1174,1196,1206,1210,1211,1212,1220,1230,1241,1253,1264,1278,1293,1308,1321,1341,1371,1399,1414,1410,1391,1354,1293,1218,1150,1105,1082,1077,1080,1089,1104,1123,1135,1141,1146,1145,1142,1145,1151,1156,1156,1153,1149,1145,1141,1139,1138,1136,1138,1148,1159,1165,1169,1166,1158,1153,1157,1160,1157,1156,1163,1172,1178,1176,1171,1171,1173,1176,1169,1161,1182,1214,1211,1198,1196,1179,1158,1154,1156,1155,1155,1154,1139,1144,1459,2189,2318,1133,248,657,1113,1167,1152,1156,1180,1197,1205,1206,1206,1213,1222,1233,1244,1257,1279,1300,1312,1322,1335,1356,1376,1385,1378,1358,1328,1284,1223,1159,1112,1086,1075,1074,1079,1093,1112,1127,1139,1149,1155,1155,1153,1159,1163,1159,1152,1146,1145,1152,1153,1149,1149,1153,1156,1156,1156,1156,1156,1156,1156,1158,1163,1166,1169,1168,1166,1169,1175,1174,1172,1172,1174,1178,1182,1185,1183,1183,1202,1222,1213,1202,1197,1181,1161,1157,1163,1166,1167,1165,1149,1178,1557,2229,2089,846,284,804,1147,1180,1171,1178,1202,1210,1219,1225,1228,1236,1244,1251,1260,1271,1284,1297,1310,1325,1348,1378,1404,1417,1414,1389,1346,1281,1205,1141,1102,1083,1081,1090,1101,1115,1129,1133,1131,1133,1136,1141,1148,1154,1154,1150,1148,1146,1142,1136,1135,1142,1150,1154,1157,1158,1154,1151,1152,1157,1160,1160,1160,1160,1160,1163,1168,1171,1174,1174,1170,1168,1172,1173,1170,1179,1205,1217,1201,1190,1181,1158,1148,1149,1149,1155,1161,1156,1138,1221,1671,2167,1675,537,416,959,1170,1191,1178,1184,1201,1207,1214,1214,1218,1229,1239,1247,1252,1260,1272,1288,1304,1326,1353,1380,1401,1408,1396,1366,1319,1251,1176,1119,1087,1074,1074,1081,1090,1102,1114,1125,1132,1132,1130,1136,1146,1152,1151,1148,1144,1140,1139,1140,1144,1144,1141,1141,1143,1147,1153,1155,1152,1149,1145,1141,1140,1146,1154,1157,1156,1154,1153,1160,1168,1170,1165,1157,1154,1157,1162,1165,1169,1173,1176,1178,1172,1163,1174,1201,1205,1194,1191,1180,1160,1152,1157,1161,1164,1167,1151,1139,1387,2088,2369,1331,315,600,1099,1167,1147,1157,1177,1192,1198,1199,1199,1207,1220,1226,1231,1238,1252,1268,1283,1299,1317,1336,1355,1372,1381,1377,1355,1315,1257,1193,1141,1106,1090,1086,1087,1097,1109,1123,1139,1153,1159,1156,1153,1154,1156,1160,1160,1158,1154,1150,1147,1147,1149,1152,1153,1152,1153,1155,1159,1162,1160,1157,1153,1153,1156,1160,1163,1167,1171,1175,1178,1177,1174,1175,1175,1175,1175,1175,1175,1175,1178,1183,1182,1179,1178,1180,1184,1188,1191,1189,1183,1194,1220,1221,1204,1198,1189,1171,1166,1174,1174,1172,1169,1159,1159,1381,1968,2149,1179,349,690,1120,1191,1185,1187,1209,1219,1221,1225,1225,1227,1236,1246,1257,1269,1280,1291,1303,1316,1339,1368,1395,1416,1422,1411,1379,1327,1253,1179,1131,1102,1089,1089,1094,1100,1108,1116,1123,1131,1137,1140,1141,1143,1147,1153,1153,1145,1138,1132,1128,1127,1134,1142,1144,1143,1145,1151,1150,1144,1141,1141,1148,1156,1162,1165,1164,1164,1161,1158,1157,1158,1161,1166,1169,1173,1174,1173,1173,1173,1173,1173,1173,1173,1173,1177,1198,1222,1215,1202,1192,1173,1156,1153,1160,1169,1169,1163,1147,1178,1557,2224,2087,857,286,804,1152,1170,1166,1191,1200,1198,1217,1212,1203,1214,1219,1221,1230,1256,1284,1287,1304,1325,1331,1342,1377,1433,1404,1325,1322,1283,1199,1163,1136,1127,1100,1051,1103,1140,1099,1102,1114,1137,1154,1125,1128,1147,1163,1164,1149,1140,1146,1156,1155,1134,1122,1148,1150,1149,1152,1149,1152,1158,1166,1153,1146};

#pragma DATA_SECTION(sally, ".big_stuff");
int sally = 20;
int32_t Voltage1[3] = {0, 2, 4};

void setup_flash(FLASH_Handle flashHandle);

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
	PWM_setPeriod(myPwm1, 37500);                           // Setup period of timer(pwm)
	PWM_disableCounterLoad(myPwm1);                       // Disable phase loading
	PWM_setPhase(myPwm1, 0x0000);                         // Phase is 0
	PWM_setCount(myPwm1, 0x0000);                         // Clear counter
	PWM_setHighSpeedClkDiv(myPwm1, PWM_HspClkDiv_by_1);   // Clock ratio to SYSCLKOUT
	PWM_setClkDiv(myPwm1, PWM_ClkDiv_by_16);			  // Another multiplicative clk divider
	PWM_setCmpA(myPwm1, 5);                               // Set comparator value -- No longer used
	
	// Setup PWM to trigger the ADC through SOC-A
	PWM_enableSocAPulse(myPwm1);
	PWM_setSocAPulseSrc(myPwm1, PWM_SocPulseSrc_CounterEqualZero);
	PWM_setSocAPeriod(myPwm1, PWM_SocPeriod_FirstEvent);

	
	CLK_enableTbClockSync(myClk);                         // Release the TBCLK (and hence start the counter)
	

}

void sys_init(){
	// Perform basic system initialization
		WDOG_disable(myWDog);
		CLK_enableAdcClock(myClk);
		(*Device_cal)();
	//	CLK_disableAdcClock(myClk);

		//Select the internal oscillator 1 as the clock source
		CLK_setOscSrc(myClk, CLK_OscSrc_Internal);

		// Setup the PLL for x12 /2 which will yield 50Mhz = 10Mhz * 10 / 2
		PLL_setup(myPll, PLL_Multiplier_10, PLL_DivideSelect_ClkIn_by_2);

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

		// Register interrupt handlers in the PIE vector table
		PIE_registerPieIntHandler(myPie, PIE_GroupNumber_10, PIE_SubGroupNumber_1, (intVec_t)&adc_isr);

}

void setup_flash(FLASH_Handle flashHandle){
	FLASH_enablePipelineMode(flashHandle);
    //Set the Paged Waitstate for the Flash
    FLASH_setNumPagedReadWaitStates(flashHandle, FLASH_NumPagedWaitStates_2);
//   FlashRegs.FBANKWAIT.bit.PAGEWAIT = 2;

    //Set the Random Waitstate for the Flash
    FLASH_setNumRandomReadWaitStates(flashHandle, FLASH_NumRandomWaitStates_2);
//   FlashRegs.FBANKWAIT.bit.RANDWAIT = 2;

    //Set the Waitstate for the OTP
    FLASH_setOtpWaitStates(flashHandle, FLASH_NumOtpWaitStates_2);
//   FlashRegs.FOTPWAIT.bit.OTPWAIT = 2;


    //                CAUTION
    //ONLY THE DEFAULT VALUE FOR THESE 2 REGISTERS SHOULD BE USED
//   FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;
    FLASH_setStandbyWaitCount(flashHandle, 0x01FF);
//   FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;
    FLASH_setActiveWaitCount(flashHandle, 0x01FF);


    //Force a pipeline flush to ensure that the write to
    //the last register configured occurs before returning.

    asm(" RPT #7 || NOP");
}


int main(void) {
	setup_handles();

	sys_init();

	// Setup Signaling GPIO
    GPIO_setPullUp(myGpio, GPIO_Number_0, GPIO_PullUp_Disable);
    GPIO_setMode(myGpio, GPIO_Number_0, GPIO_0_Mode_GeneralPurpose);
    GPIO_setDirection(myGpio, GPIO_Number_0, GPIO_Direction_Output);
    GPIO_setLow(myGpio, GPIO_Number_0);



    uint32_t bob = 0;
    bob++;
	init_adc();
	InitPwm();


	// Enable global Interrupts and higher priority real-time debug events
	CPU_enableGlobalInts(myCpu);
	CPU_enableDebugInt(myCpu);

	Voltage1[0] = 10;
	Voltage1[1] = 20;
	sally = 50;


	uint32_T heart_rate=0, last_hr_delta=0;
	int i;
	// Converts the DC values to fixed point values
//	for(i = 0; i < 1000; i++) {
//		Voltage1[i] = mul_u32_u32_u32_sat(Voltage1[i], div_repeat_u32_sat_near(3379, 4096, 10U)); // 3379 is 3.3 is fixed point
//	}
	if(ConversionCount==999){
//		heart_rate_official_cport(Voltage1, 100, 0.15, 0.3, 0.2, 2, 0.7, 15, 0, 0, &heart_rate, &last_hr_delta);
		/*
		void heart_rate_official_cport(int32_T data, uint32_T fs, uint32_T threshold_1,
		  uint32_T threshold_2, uint32_T threshold_3, uint32_T pos_deviance_threshold,
		  uint32_T neg_deviance_threshold, uint32_T sample_time, uint32_T shouldOutput,
		  uint32_T prev_hr_delta, uint32_T *heart_rate, uint32_T *last_hr_delta)
		*/
	}



	while(1){
		bob++;
	}



}


interrupt void adc_isr(void){

	isr_counter++;

    GPIO_toggle(myGpio, GPIO_Number_0);
	// If 10 conversions have been logged, start over
//    if(ConversionCount < 999)
//    {
//    	Voltage1[ConversionCount] = ADC_readResult(myAdc, ADC_ResultNumber_0);
//    	ConversionCount++;
//    }


	// Clear INT flag for this timer
	ADC_clearIntFlag(myAdc, ADC_IntNumber_1);

	// Acknowledge this interrupt to receive more interrupts from group 10
	PIE_clearInt(myPie, PIE_GroupNumber_10);
}
