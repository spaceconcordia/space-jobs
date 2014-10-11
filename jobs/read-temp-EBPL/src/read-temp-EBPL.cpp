#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <shakespeare.h>
#define LOG_DIR "/home/logs/"
#define PROCESS "TeleSPTS"


using namespace std;


int main()
{
	int exitStatus=0;
	FILE* hmcSysFile;
	FILE* logfile;
	string processName = "telemetryEBPL",logMsgVal;
	char* pPath;
	pPath = getenv("PATH");
	char readBuff[100];
	size_t lastLen=0;

	/*****************************************************************************/
	/*********************AD7998 Temperature Sensor 0********************/
	/*****************************************************************************/
	char result[100];   // array to hold the result.

	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage0_raw/ \n");
	hmcSysFile = fopen(result,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("TPS0:");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/

	result[0] = 0;
	/*****************************************************************************/
	/*********************AD7998 Temperature Sensor 1********************/
	/*****************************************************************************/
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage1_raw/ \n");
	hmcSysFile = fopen(result,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("TS1:");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/

	result[0] = 0;

	/*****************************************************************************/
	/*********************AD7998 Battery Temperature Sensor 1********************/
	/*****************************************************************************/
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage2_raw/ \n");
	hmcSysFile = fopen(result,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("BTS1:");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/

	result[0] = 0;
	/*****************************************************************************/
	/*********************AD7998 Battery Temperature Sensor 0********************/
	/*****************************************************************************/
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage3_raw/ \n");
	hmcSysFile = fopen(result,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("BTS0:");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/*****************************************************************************/
	/*****************************************************************************/
	/*****************************************************************************/
	result[0] = 0;
	/********************************************************************************/
	/*********************AD7998 Temperature Sensor 2********************/
	/********************************************************************************/
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage4_raw/ \n");
	hmcSysFile = fopen(result,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("TS2:");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
	result[0] = 0;

	/********************************************************************************/
	/*********************AD7998 Temperature Sensor 3********************/
	/********************************************************************************/
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage5_raw/ \n");
	hmcSysFile = fopen(result,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("TS3:");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
	result[0] = 0;
	/********************************************************************************/
	/*********************AD7998 Payload Temperature Sensor********************/
	/********************************************************************************/
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage6_raw/ \n");
	hmcSysFile = fopen(result,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("PLTS:");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
	result[0] = 0;

	/********************************************************************************/
	/*********************AD7998 Elec Bay Temperature Sensor********************/
	/********************************************************************************/
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in_voltage7_raw/ \n");
	hmcSysFile = fopen(result,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("EBTS:");
  	lastLen=logMsgVal.length()+1;
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	logMsgVal.append(" :: ");
  	memset(readBuff, 0, sizeof(readBuff));
	/********************************************************************************/
	/********************************************************************************/
	/********************************************************************************/
	
	result[0] = 0;
 	// write to log via shakespeare
  	logfile=Shakespeare::open_log ("/home/logs/telemetryEBPL",PROCESS);
  	if(logfile!=NULL) 
	{
   		// Shakespeare::log(logfile, Shakespeare::WARNING, PROCESS, "This is a warning message");
    		Shakespeare::log(logfile, Shakespeare::NOTICE, PROCESS,logMsgVal);
        	// Shakespeare::log(logfile, Shakespeare::ERROR, PROCESS, "This is an error message");
    		// Shakespeare::log(logfile, Shakespeare::URGENT, PROCESS, "This is an urgent message");
   		// Shakespeare::log(logfile, Shakespeare::CRITICAL, PROCESS, "This is a critical message");
  	}

  	// close and exit
 	fclose(logfile);
  	return exitStatus;


}

