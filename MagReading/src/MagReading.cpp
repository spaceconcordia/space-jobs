#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include "shakespeare.h"
using namespace std;


int main()
{

	int exitStatus=0;
	Priority logPriority = NOTICE;
	FILE* hmcSysFile;
	FILE* tgtLog;

	string processName = "telemetryACS",logMsgVal;
	

	char readBuff[100];
	size_t lastLen=0;
	/************************************************************/
	/*********************HMC5883L X axis Raw********************/
	/************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-001e/iio:device1/in_magn_x_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Magnetometer X : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/************************************************************/
	/************************************************************/
	/************************************************************/

	/************************************************************/
	/*********************HMC5883L Y axis Raw********************/
	/************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-001e/iio:device1/in_magn_y_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Magnetometer Y : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/************************************************************/
	/************************************************************/
	/************************************************************/



	/************************************************************/
	/*********************HMC5883L Z axis Raw********************/
	/************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-001e/iio:device1/in_magn_z_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Magnetometer Z : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/************************************************************/
	/************************************************************/
	/************************************************************/





	
	/************************************************************/
	/***********************HMC5883L Range***********************/
	/************************************************************/
	
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-001e/iio:device1/in_magn_range","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,100,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Magnetometer Range : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/************************************************************/
	/************************************************************/
	/************************************************************/





	/************************************************************/
	/***********************HMC5883L Scale***********************/
	/************************************************************/
	
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-001e/iio:device1/in_magn_scale","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,100,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}
 	logMsgVal.append("Magnetometer Scale : ");
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	memset(readBuff, 0, sizeof(readBuff));
	/************************************************************/
	/************************************************************/
	/************************************************************/

	

 	// write to log via shakespeare
  	tgtLog=fopen("/tmp/telemetryACSlog","a");
  	Log(tgtLog,logPriority,processName,logMsgVal);

  	// close and exit
 	fclose(tgtLog);
  	return exitStatus;


}
