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
uint8_t process_id = CS1_PWR_INA219;
const string process = cs1_systems[process_id];

using namespace std;
using namespace I2CDevice;

int main()
{
	int exitStatus=0;
	string processName = "telemetryINA219",logMsgVal;
	char* pPath;
	pPath = getenv("INA2XXPATH");
	char readBuff[100];
	char * pEnd;
	short int temp_data = 0;


 	/******** /sys/bus/i2c/devices/1-0040/curr1_input  :: current through Rsens ********/
	char result[100];	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/curr1_input");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);
	/***********************************************************************************/

    	temp_data = 0;
	result[0] = '\0';



	/******** /sys/bus/i2c/devices/1-0040/in0_input    :: voltage across Rsens ********/
	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in0_input");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);

	/***********************************************************************************/

    	temp_data = 0;
	result[0] = '\0';

	/******** /sys/bus/i2c/devices/1-0040/in1_input    :: voltage from Bus to Gnd ********/
	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/in1_input");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);
	/***********************************************************************************/

    	temp_data = 0;
	result[0] = '\0';

	/********  /sys/bus/i2c/devices/1-0040/power1_input :: power through Rsens ********/
	
	strcpy(result,pPath); // copy string one into the result.
	strcat(result,"/power1_input");
    	I2CRead(result,readBuff);
    	temp_data = strtol(readBuff,NULL,0);
	Shakespeare::log_bin(Shakespeare::NOTICE,process_id,temp_data);
	/***********************************************************************************/

	temp_data = 0;
	result[0] = '\0';
  	return exitStatus;

/*
  // main function variables 
  int exitStatus=0;

  // variables needed to call shakespeare log function
  string logMsgVal;

  // *** note: for now we assume the ina2xx driver has already been instantiated 
  // *** ina219 is hardwired to: 
  //  bus: i2c-1
  //  address: 0x40
  // The data values can be read from the dev system if the existing module is loaded
  // and instantiated
  // DEV_FILES:
  //  /sys/bus/i2c/devices/1-0040/curr1_input  :: current through Rsens
  //  /sys/bus/i2c/devices/1-0040/in0_input    :: voltage across Rsens
  //  /sys/bus/i2c/devices/1-0040/in1_input    :: voltage from Bus to Gnd
  //  /sys/bus/i2c/devices/1-0040/power1_input :: power through Rsens

  FILE* inaSysFile;
  char readBuf[10];
  size_t lastLen=0;

  inaSysFile=fopen("/sys/bus/i2c/devices/1-0040/in1_input","r");
  if (inaSysFile!=NULL) {
    fgets(readBuf,10,inaSysFile);
    fclose(inaSysFile);
  } else {
    strncpy(readBuf,"readfail\n",9);
  }
  logMsgVal.append("bus_v: ");
  lastLen=logMsgVal.length()+1;
  logMsgVal.append(readBuf);
  logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  logMsgVal.append(" :: ");
  memset(readBuf, 0, sizeof(readBuf));

  inaSysFile=fopen("/sys/bus/i2c/devices/1-0040/in0_input","r");
  if (inaSysFile!=NULL) {
    fgets(readBuf,10,inaSysFile);
    fclose(inaSysFile);
  } else {
    strncpy(readBuf,"readfail\n",9);
  }  
  logMsgVal.append("shunt_v: ");
  lastLen=logMsgVal.length()+1;
  logMsgVal.append(readBuf);
  logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  logMsgVal.append(" :: ");
  memset(readBuf, 0, sizeof(readBuf));

  inaSysFile=fopen("/sys/bus/i2c/devices/1-0040/curr1_input","r");
  if (inaSysFile!=NULL) {
    fgets(readBuf,10,inaSysFile);
    fclose(inaSysFile);
  } else {
    strncpy(readBuf,"readfail\n",9);
  }
  logMsgVal.append("shunt_i: ");
  lastLen=logMsgVal.length()+1;
  logMsgVal.append(readBuf);
  logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  logMsgVal.append(" :: ");
  memset(readBuf, 0, sizeof(readBuf));

  inaSysFile=fopen("/sys/bus/i2c/devices/1-0040/power1_input","r");
  if (inaSysFile!=NULL) {
    fgets(readBuf,10,inaSysFile);
    fclose(inaSysFile);
  } else {
    strncpy(readBuf,"readfail\n",9);
  }
  logMsgVal.append("power: ");
  logMsgVal.append(readBuf);
  logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  memset(readBuf, 0, sizeof(readBuf));

  Shakespeare::log(Shakespeare::NOTICE,PROCESS,logMsgVal);

  return exitStatus;*/
}
