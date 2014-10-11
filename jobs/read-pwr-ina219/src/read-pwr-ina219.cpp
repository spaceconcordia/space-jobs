#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <shakespeare.h>

#define PROCESS "telemetryPwrIna219"

using namespace std;

int main()
{
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

  return exitStatus;
}