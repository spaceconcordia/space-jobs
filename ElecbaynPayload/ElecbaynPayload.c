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

	string processName = "TempSensOtr",logMsgVal;
	

	char readBuff[100];
	size_t lastLen=0;
	/*****************************************************************************/
	/*********************AD7998 Addr 2 Batt Temp 1********************/
	/*****************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0022/iio:device0/in_voltage2_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Batt Temp 1 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/


	/*****************************************************************************/
	/*********************AD7998 Addr 3 Batt Temp 2********************/
	/*****************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0022/iio:device0/in_voltage3_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Batt Temp 2 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/



	/*****************************************************************************/
	/*********************AD7998 Addr 6 Elec Bay Temp 1********************/
	/*****************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0022/iio:device0/in_voltage6_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Elec Bay Temp 1 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/


	/*****************************************************************************/
	/*********************AD7998 Addr 7 Elec Bay Temp 0********************/
	/*****************************************************************************/
	hmcSysFile = fopen("/sys/bus/i2c/devices/1-0022/iio:device0/in_voltage7_raw","r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("Elec Bay Temp 2 : ");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/

 	// write to log via shakespeare
  	tgtLog=fopen("/tmp/telemetryTempSensOtr","a");
  	Log(tgtLog,logPriority,processName,logMsgVal);

  	// close and exit
 	fclose(tgtLog);
  	return exitStatus;

}