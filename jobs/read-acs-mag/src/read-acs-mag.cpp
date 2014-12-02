/*
X - > X axis
Y - > Y axis
Z - > Z axis
r - > range
s - > scale
rf - > read failed
*/
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
uint8_t process_id = CS1_ACS_MAG;
const string process = cs1_systems[process_id];



using namespace std;
using namespace I2CDevice;

int main()
{

	int exitStatus=0;
	string processName = "telemetryMAG",logMsgVal;
	char* pPath;
	pPath = getenv("HMC5843PATH");
	char readBuff[100];
	char * pEnd;
	short int temp_data = 0;


	/************************************************************/
	/*********************HMC5883L X axis Raw********************/
	/************************************************************/
	char result[100];	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_magn_x_raw");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/************************************************************/
	/*********************HMC5883L Y axis Raw********************/
	/************************************************************/


	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_magn_y_raw");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);


	/************************************************************/
	/************************************************************/
	/************************************************************/
	result[0] = 0;
	/************************************************************/
	/*********************HMC5883L Z axis Raw********************/
	/************************************************************/
	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_magn_z_raw");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

  	memset(readBuff, 0, sizeof(readBuff));
	/************************************************************/
	/************************************************************/
	/************************************************************/
	result[0] = 0;
	/************************************************************/
	/***********************HMC5883L Range***********************/
	/************************************************************/;

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_magn_range");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/************************************************************/
	/************************************************************/
	/************************************************************/
	result[0] = 0;
	/************************************************************/
	/***********************HMC5883L Scale***********************/
	/************************************************************/

	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_magn_scale");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/************************************************************/
	/************************************************************/
	/************************************************************/
	temp_data = 0;
	result[0] = '\0';
  	return exitStatus;

}   
