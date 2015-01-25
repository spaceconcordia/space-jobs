#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include "shakespeare.h"
#include </home/samsara/CONSAT1/space-lib/utls/include/i2c-device.h>
#include "../inc/read-pwr-ad7998.h"
#define LOG_DIR "/home/logs/"
#define PROCESS_NAME "telemetryPWR_AD7998"
#define PROCESS_PATH "AD7998x23PATH"
#define LOG_PATH "/home/logs"
uint8_t process_id = CS1_PWR_AD7998;
const string process = cs1_systems[process_id];

using namespace I2CDevice;
using namespace std;

char readBuff[100];

int main()
{
	int exitStatus=0;
	char* pPath = getenv(PROCESS_PATH);

 	/****  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage1_raw : channel 2 - battery thermistor1 voltage ****/
	readDevice(pPath, "/in_voltage1_raw");
	/************************************************************************************************************/

	/****  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage3_raw : channel 4 - battery thermistor2 voltage ****/
	readDevice(pPath, "/in_voltage3_raw");
	/************************************************************************************************************/

	/****  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage5_raw : channel 6 - solar panel1_3 voltage divider ****/
	readDevice(pPath, "/in_voltage6_raw");
	/***************************************************************************************************************/

	/****  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage7_raw : channel 8 - solar panel2_4 voltage divider ****/
	readDevice(pPath, "/in_voltage7_raw");
	/***************************************************************************************************************/

  return exitStatus;
}

int readDevice (char* pPath, const char* deviceName) {
	char result[100];
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,deviceName);
	I2CRead(result,readBuff);
	short int temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	return CS1_SUCCESS;
}






/*
	// main function variables
	int exitStatus=0;

	// variables needed to call shakespeare log function
	FILE* tgtLog;
	//  Priority logPriority = NOTICE;
	string processName,logMsgVal;
	processName = "telemetryPwrAd7998";
	//logMsgVal = "Test log payload string";

	// *** note: for now we assume the ad799x driver has already been instantiated
	// *** power ad799x is hardwired to:
	//  bus: i2c-1
	//  address: 0x23
	// The data values can be read from the dev system if the existing module is loaded
	// and instantiated
	// Channels 1,3,5,7 are grounded
	// in the datasheet, pin channels are labelled 1-8, in the driver sys files, channels are numbered
	// 0-7, therefore device files 1,3,5,7 correspond to pin channels 2,4,6,8
	// DEV_FILES:
	//  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage1_raw : channel 2 - battery thermistor1 voltage
	//  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage3_raw : channel 4 - battery thermistor2 voltage
	//  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage5_raw : channel 6 - solar panel1_3 voltage divider
	//  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage7_raw : channel 8 - solar panel2_4 voltage divider

	FILE* adSysFile;
	char readBuf[10];
	size_t lastLen=0;

	adSysFile=fopen("/sys/bus/i2c/devices/1-0023/iio:device3/in_voltage1_raw","r");
	if (adSysFile!=NULL) {
		fgets(readBuf,10,adSysFile);
		fclose(adSysFile);
	} else {
		strncpy(readBuf,"readfail\n",9);
	}
	logMsgVal.append("bat-thrm-v1 ");
	lastLen=logMsgVal.length()+1;
	logMsgVal.append(readBuf);
	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
	logMsgVal.append(" :: ");
	memset(readBuf, 0, sizeof(readBuf));

	adSysFile=fopen("/sys/bus/i2c/devices/1-0023/iio:device3/in_voltage3_raw","r");
	if (adSysFile!=NULL) {
		fgets(readBuf,10,adSysFile);
		fclose(adSysFile);
	} else {
		strncpy(readBuf,"readfail\n",9);
	}
	logMsgVal.append("bat-thrm-v2 ");
	lastLen=logMsgVal.length()+1;
	logMsgVal.append(readBuf);
	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
	logMsgVal.append(" :: ");
	memset(readBuf, 0, sizeof(readBuf));

	adSysFile=fopen("/sys/bus/i2c/devices/1-0023/iio:device3/in_voltage5_raw","r");
	if (adSysFile!=NULL) {
		fgets(readBuf,10,adSysFile);
		fclose(adSysFile);
	} else {
		strncpy(readBuf,"readfail\n",9);
	}
	logMsgVal.append("sp1-3-v ");
	lastLen=logMsgVal.length()+1;
	logMsgVal.append(readBuf);
	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
	logMsgVal.append(" :: ");
	memset(readBuf, 0, sizeof(readBuf));

	adSysFile=fopen("/sys/bus/i2c/devices/1-0023/iio:device3/in_voltage7_raw","r");
	if (adSysFile!=NULL) {
		fgets(readBuf,10,adSysFile);
		fclose(adSysFile);
	} else {
		strncpy(readBuf,"readfail\n",9);
	}
	logMsgVal.append("sp2-4-v ");
	lastLen=logMsgVal.length()+1;
	logMsgVal.append(readBuf);
	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
	memset(readBuf, 0, sizeof(readBuf));

	// write to log via shakespeare
	tgtLog=Shakespeare::open_log("/var/log/telemetryPowerLog",processName);
	Shakespeare::log(tgtLog,Shakespeare::NOTICE,processName,logMsgVal);

	// close and exit
	fclose(tgtLog);
	return exitStatus;*/
