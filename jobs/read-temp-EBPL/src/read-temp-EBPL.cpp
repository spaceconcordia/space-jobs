#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <SpaceDecl.h>
#include <shakespeare.h>
#include </home/samsara/CONSAT1/space-lib/utls/include/i2c-device.h>
#include "../inc/read-temp-EBPL.h"
#define LOG_DIR "/home/logs/"
#define PROCESS_PATH "AD7998x22PATH"
#define LOG_PATH "/home/logs"

//Error codes
#define NULL_PATH_ERROR 2;
#define NULL_DEVICENAME_ERROR 3;

uint8_t process_id = CS1_TEMP_EBPL;
const string process = cs1_systems[process_id];

using namespace std;
using namespace I2CDevice;

char readBuff[100];

int main()
{
	int exitStatus=0;
	char* pPath = getenv("");

	/*********************AD7998 Temperature Sensor 0********************/
	readDevice(pPath, PROCESS_PATH);
	/*****************************************************************************/

	/*********************AD7998 Temperature Sensor 1********************/
	readDevice(pPath, "/in_voltage1_raw");
	/*****************************************************************************/

	/*********************AD7998 Battery Temperature Sensor 1********************/
	readDevice(pPath, "/in_voltage2_raw");
	/*****************************************************************************/

	/*********************AD7998 Battery Temperature Sensor 0********************/
	readDevice(pPath, "/in_voltage3_raw");
	/*****************************************************************************/

	/*********************AD7998 Temperature Sensor 2********************/
	readDevice(pPath, "/in_voltage4_raw");
	/********************************************************************************/

	/*********************AD7998 Temperature Sensor 3********************/
	readDevice(pPath, "/in_voltage5_raw");
	/********************************************************************************/

	/*********************AD7998 Payload Temperature Sensor********************/
	readDevice(pPath, "/in_voltage6_raw");
	/********************************************************************************/

	/*********************AD7998 Elec Bay Temperature Sensor********************/
	readDevice(pPath, "/in_voltage7_raw");

	/********************************************************************************/

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
