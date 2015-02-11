#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include "shakespeare.h"
#include <i2c-device.h>
#include "../inc/read-pwr-ad7998.h"
#define LOG_DIR "/home/logs/"
#define PROCESS_NAME "telemetryPWR_AD7998"
#define PROCESS_PATH "AD7998x23PATH"
#define LOG_PATH "/home/logs"
uint8_t process_id = CS1_PWR_AD7998;
const string process = cs1_systems[process_id];

//Error codes
#define NULL_PATH_ERROR 2;
#define NULL_DEVICENAME_ERROR 3;

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
	if(pPath == NULL)
		return NULL_PATH_ERROR;

	if (deviceName == NULL)
		return NULL_DEVICENAME_ERROR;

	char result[100];
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,deviceName);
	I2CRead(result,readBuff);
	short int temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	return CS1_SUCCESS;
}
