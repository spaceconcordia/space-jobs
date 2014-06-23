#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include "shakespeare.h"

#define LOG_DIR "/home/logs/"
#define PROCESS "TeleEBP"

using namespace std;


int main()
{

	int exitStatus=0;
	//Priority logPriority = NOTICE;
	FILE* hmcSysFile;
	FILE* tgtLog;

	string processName = "TempSensOtr",logMsgVal;
	
	char* pPath;

	pPath = getenv("PATH");

	char readBuff[100];
	size_t lastLen=0;
	/*****************************************************************************/
	/*********************AD7998 Addr 2 Batt Temp 1********************/
	/*****************************************************************************/
	// hmcSysFile = fopen(pPath + "/in_voltage2_raw","r");
	// hmcSysFile = fopen("/sys/bus/i2c/devices/1-0022/iio:device0/in_voltage2_raw","r");

	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"readfail\n",9);
	}

 	logMsgVal.append("BT1: "); // battery temp 1
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

	// hmcSysFile = fopen(pPath + "/in_voltage3_raw","r");
	// hmcSysFile = fopen("/sys/bus/i2c/devices/1-0022/iio:device0/in_voltage3_raw","r");

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

 	logMsgVal.append("BT2 : "); // battery temp 2
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
	// hmcSysFile = fopen(pPath + "/in_voltage6_raw","r");
	// hmcSysFile = fopen("/sys/bus/i2c/devices/1-0022/iio:device0/in_voltage6_raw","r");

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

 	logMsgVal.append("EBT1 : "); // elec bay temp 1
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

	// hmcSysFile = fopen(pPath + "/in_voltage7_raw","r");
	// hmcSysFile = fopen("/sys/bus/i2c/devices/1-0022/iio:device0/in_voltage7_raw","r");
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

 	logMsgVal.append("EBT2:"); // elec bay temp 2
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/

 	// write to log via shakespeare
  	logfile=Shakespeare::open_log (LOG_DIR,PROCESS);
  	if(logfile!=NULL) 
	{
   		// Shakespeare::log(logfile, Shakespeare::WARNING, PROCESS, "This is a warning message");
    		Shakespeare::log(logfile, Shakespeare::NOTICE, PROCESS,DATA);
        	// Shakespeare::log(logfile, Shakespeare::ERROR, PROCESS, "This is an error message");
    		// Shakespeare::log(logfile, Shakespeare::URGENT, PROCESS, "This is an urgent message");
   		// Shakespeare::log(logfile, Shakespeare::CRITICAL, PROCESS, "This is a critical message");
  	}

  	// close and exit
 	fclose(logfile);
  	return exitStatus;

}
