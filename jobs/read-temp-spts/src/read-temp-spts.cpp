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
uint8_t process_id = CS1_TEMP_SPTS;
const string process = cs1_systems[process_id];

using namespace std;
using namespace I2CDevice;


int main()
{
	int exitStatus=0;
	string processName = "telemetrySPTS",logMsgVal;
	char* pPath;
	pPath = getenv("AD7998x21PATH");
	char readBuff[100];
	char * pEnd;
	short int temp_data = 0;


	/*****************************************************************************/
	/*********************AD7998 Addr 0 Top Temp Solar Panel 1********************/
	/*****************************************************************************/
	
	char result[100];	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage0_raw");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/
    	temp_data = 0;
	result[0] ='\0';
	/*****************************************************************************/
	/*********************AD7998 Addr 1 Top Temp Solar Panel 2********************/
	/*****************************************************************************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage1_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/
    	temp_data = 0;
	result[0] = '\0';
	/*****************************************************************************/
	/*********************AD7998 Addr 2 Top Temp Solar Panel 3********************/
	/*****************************************************************************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage2_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/
    	temp_data = 0;
	result[0] = '\0';
	/*****************************************************************************/
	/*********************AD7998 Addr 3 Top Temp Solar Panel 4********************/
	/*****************************************************************************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage3_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/
    	temp_data = 0;
	result[0] = '\0';
	/********************************************************************************/
	/*********************AD7998 Addr 4 Bottom Temp Solar Panel 1********************/
	/********************************************************************************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage4_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
    	temp_data = 0;
	result[0] = '\0';
	/********************************************************************************/
	/*********************AD7998 Addr 5 Bottom Temp Solar Panel 2********************/
	/********************************************************************************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage5_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
    	temp_data = 0;
	result[0] = '\0';
	/********************************************************************************/
	/*********************AD7998 Addr 6 Bottom Temp Solar Panel 3********************/
	/********************************************************************************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage6_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
    	temp_data = 0;
	result[0] = '\0';

	/********************************************************************************/
	/*********************AD7998 Addr 7 Bottom Temp Solar Panel 4********************/
	/********************************************************************************/

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage7_raw");
	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
	temp_data = 0;
	result[0] = '\0';
  	return exitStatus;


}

