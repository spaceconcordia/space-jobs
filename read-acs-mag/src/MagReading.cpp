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
#include "shakespeare.h"
#define LOG_DIR "/home/logs/"
#define PROCESS "TeleACS"

using namespace std;


int main()
{

	int exitStatus=0;
	FILE* hmcSysFile;
	FILE* logfile;

	string DATA = "telemetryACS",logMsgVal;
	
	char* pPath;

	pPath = getenv("PATH");

	char readBuff[100];
	size_t lastLen=0;
	/************************************************************/
	/*********************HMC5883L X axis Raw********************/
	/************************************************************/
	
	//hmcSysFile = fopen(pPath1 +"/in_magn_x_raw" ,"r");  <-- want to amend the string path to access 
	hmcSysFile = fopen(pPath,"r");
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("X : "); // X AXIS < to decrease the size of the file, since we know what the device is, just need simple header
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
	//hmcSysFile = fopen(pPath + "/in_magn_y_raw","r"); <-- want to amend the string path to access 
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("Y : "); // Y AXIS < to decrease the size of the file, since we know what the device is, just need simple header
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
	//hmcSysFile = fopen(pPath + "/in_magn_z_raw","r"); <-- want to amend the string path to access 
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,10,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("Z: "); //Z AXIS < to decrease the size of the file, since we know what the device is, just need simple header
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
	
	//hmcSysFile = fopen(pPath + "/in_magn_range","r"); <-- want to amend the string path to access 
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,100,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}

 	logMsgVal.append("R: ");// RANGE < to decrease the size of the file, since we know what the device is, just need simple header
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
	
	//hmcSysFile = fopen(pPath + "/in_magn_scale","r"); <-- want to amend the string path to access 
	if (hmcSysFile !=NULL)
	{
		fgets(readBuff,100,hmcSysFile);
		fclose(hmcSysFile);
	}
	else
	{
		strncpy(readBuff,"rf\n",9);
	}
 	logMsgVal.append("S: "); // SCALE < to decrease the size of the file, since we know what the device is, just need simple header
  	logMsgVal.append(readBuff);
  	logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  	memset(readBuff, 0, sizeof(readBuff));
	/************************************************************/
	/************************************************************/
	/************************************************************/

	

 	// write to log via shakespeare
  	logfile=Shakespeare::open_log ("/var/log/telemetryACSLog",PROCESS);
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
