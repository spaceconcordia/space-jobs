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

	string processName = "telemetrySPTS",logMsgVal;
	

	char readBuff[100];
	size_t lastLen=0;
	/*****************************************************************************/
	/*********************AD7998 Addr 0 Top Temp Solar Panel 1********************/
	/*****************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0021/iio:device2/in_voltage0_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Top Temp Solar Panel 1 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/


	/*****************************************************************************/
	/*********************AD7998 Addr 1 Top Temp Solar Panel 2********************/
	/*****************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0021/iio:device2/in_voltage1_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Top Temp Solar Panel 2 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/



	/*****************************************************************************/
	/*********************AD7998 Addr 2 Top Temp Solar Panel 3********************/
	/*****************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0021/iio:device2/in_voltage2_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Top Temp Solar Panel 3 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/


	/*****************************************************************************/
	/*********************AD7998 Addr 3 Top Temp Solar Panel 4********************/
	/*****************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0021/iio:device2/in_voltage3_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Top Temp Solar Panel 4 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/

	/********************************************************************************/
	/*********************AD7998 Addr 4 Bottom Temp Solar Panel 1********************/
	/********************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0021/iio:device2/in_voltage4_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Bottom Temp Solar Panel 1 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/


	/********************************************************************************/
	/*********************AD7998 Addr 5 Bottom Temp Solar Panel 2********************/
	/********************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0021/iio:device2/in_voltage5_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Bottom Temp Solar Panel 2 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/

	/********************************************************************************/
	/*********************AD7998 Addr 6 Bottom Temp Solar Panel 3********************/
	/********************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0021/iio:device2/in_voltage6_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Bottom Temp Solar Panel 3 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/


	/********************************************************************************/
	/*********************AD7998 Addr 7 Bottom Temp Solar Panel 4********************/
	/********************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0021/iio:device2/in_voltage7_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Bottom Temp Solar Panel 4 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
	

 	// write to log via shakespeare
  	tgtLog=fopen("/tmp/telemetrySPTS","a");
  	Log(tgtLog,logPriority,processName,logMsgVal);

  	// close and exit
 	fclose(tgtLog);
  	return exitStatus;


}

