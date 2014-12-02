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
#include </home/spaceconcordia/CONSAT1/space-lib/utls/include/i2c-device.h>
#define LOG_DIR "/home/logs/"
uint8_t process_id = CS1_TEMP_EBPL;
const string process = cs1_systems[process_id];

using namespace std;
using namespace I2CDevice;

int main()
{
	int exitStatus=0;
	string processName = "telemetryEBPL",logMsgVal;
	char* pPath;
	pPath = getenv("AD7998x22PATH");
	char readBuff[100];
	char * pEnd;
	short int temp_data = 0;

	/*********************AD7998 Temperature Sensor 0********************/

	char result[100];	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage0_raw");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);
	/*****************************************************************************/
    	temp_data = 0;
	result[0] ='\0';

	/*********************AD7998 Temperature Sensor 1********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage1_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);
	/*****************************************************************************/

    	temp_data = 0;
	result[0] = '\0';


	/*********************AD7998 Battery Temperature Sensor 1********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage2_raw");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);
	/*****************************************************************************/

    	temp_data = 0; 
	result[0] = '\0';

	/*********************AD7998 Battery Temperature Sensor 0********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage3_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);
	/*****************************************************************************/

    	temp_data = 0;
	result[0] = '\0';

	/*********************AD7998 Temperature Sensor 2********************/
	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage4_raw");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);
	/********************************************************************************/

    	temp_data = 0;
	result[0] = '\0';


	/*********************AD7998 Temperature Sensor 3********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage5_raw");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/********************************************************************************/

    	temp_data = 0;
	result[0] = '\0';

	/*********************AD7998 Payload Temperature Sensor********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage6_raw");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/********************************************************************************/

    	temp_data = 0;
	result[0] = '\0';


	/*********************AD7998 Elec Bay Temperature Sensor********************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage7_raw");
	I2CRead(result,readBuff);
	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/********************************************************************************/

	temp_data = 0;
	result[0] = '\0';
  	return exitStatus;


}

