#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <shakespeare.h>
#include </home/spaceconcordia/CONSAT1/space-lib/utls/include/i2c-device.h>
#define LOG_DIR "/home/logs/"
#define PROCESS "TeleSPTS"


using namespace std;
using namespace I2CDevice;

int main()
{
	int exitStatus=0;
	string processName = "telemetryEBPL",logMsgVal;
	char* pPath;
	pPath = getenv("AD7998x21PATH");
	char readBuff[100];
	char * pEnd;
	short int temp_data = 0;

	/*********************AD7998 Temperature Sensor 0********************/

	char result[100];	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage0_raw/ \n");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,&pEnd,10);
	Shakespeare::log_bin(Shakespeare::NOTICE,10,temp_data);
	/*****************************************************************************/

	result[0] = 0;

	/*********************AD7998 Temperature Sensor 1********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage1_raw/ \n");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,&pEnd,10);
	Shakespeare::log_bin(Shakespeare::NOTICE,10,temp_data);
	/*****************************************************************************/

	result[0] = 0;

	/*********************AD7998 Battery Temperature Sensor 1********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage2_raw/ \n");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,&pEnd,10);
	Shakespeare::log_bin(Shakespeare::NOTICE,10,temp_data);
	/*****************************************************************************/


	result[0] = 0;

	/*********************AD7998 Battery Temperature Sensor 0********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage3_raw/ \n");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,&pEnd,10);
	Shakespeare::log_bin(Shakespeare::NOTICE,10,temp_data);
	/*****************************************************************************/

	result[0] = 0;

	/*********************AD7998 Temperature Sensor 2********************/
	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage4_raw/ \n");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,&pEnd,10);
	Shakespeare::log_bin(Shakespeare::NOTICE,10,temp_data);
	/********************************************************************************/

	result[0] = 0;


	/*********************AD7998 Temperature Sensor 3********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage5_raw/ \n");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,&pEnd,10);
	Shakespeare::log_bin(Shakespeare::NOTICE,10,temp_data);

	/********************************************************************************/

	result[0] = 0;

	/*********************AD7998 Payload Temperature Sensor********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage6_raw/ \n");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,&pEnd,10);
	Shakespeare::log_bin(Shakespeare::NOTICE,10,temp_data);

	/********************************************************************************/

	result[0] = 0;


	/*********************AD7998 Elec Bay Temperature Sensor********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage7_raw/ \n");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,&pEnd,10);
	Shakespeare::log_bin(Shakespeare::NOTICE,10,temp_data);

	/********************************************************************************/

	
	result[0] = 0;
  	return exitStatus;


}

