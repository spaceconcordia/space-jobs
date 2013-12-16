//#include <system.h>
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
  // main function variables 
  int exitStatus=0;

  // variables needed to call shakespeare log function
  FILE* tgtLog;
  Priority logPriority = NOTICE;
  string processName,logMsgVal;
  processName = "telemetryPwrIna219";
  //logMsgVal = "Test log payload string";

  // *** note: for now we assume the ina2xx driver has already been instantiated 
  // *** ina219 is hardwired to: 
  // The data values can be read from the dev system if the existing module is loaded
  // and instantiated
  // DEV_FILES:
  //  /sys/bus/i2c/devices/1-0040/curr1_input  :: current through Rsens
  //  /sys/bus/i2c/devices/1-0040/in0_input    :: voltage across Rsens
  //  /sys/bus/i2c/devices/1-0040/in1_input    :: voltage from Bus to Gnd
  //  /sys/bus/i2c/devices/1-0040/power1_input :: power through Rsens

  FILE* inaSysFile;
  char readBuf[10];

  inaSysFile=fopen("/sys/bus/i2c/devices/1-0040/in1_input","r");
  if (inaSysFile!=NULL) {
    fgets(readBuf,10,inaSysFile);
  } else {
    strncpy(readBuf,"readfail\0",9);
  }
  logMsgVal.append("bus_v: ");
  logMsgVal.append(readBuf);
  logMsgVal.append(" :: ");
  memset(readBuf, 0, sizeof(readBuf));
  fclose(inaSysFile);

  inaSysFile=fopen("/sys/bus/i2c/devices/1-0040/in0_input","r");
  if (inaSysFile!=NULL) {
    fgets(readBuf,10,inaSysFile);
  } else {
    strncpy(readBuf,"readfail\0",9);
  }  
  logMsgVal.append("shunt_v: ");
  logMsgVal.append(readBuf);
  logMsgVal.append(" :: ");
  memset(readBuf, 0, sizeof(readBuf));
  fclose(inaSysFile);

  inaSysFile=fopen("/sys/bus/i2c/devices/1-0040/curr1_input","r");
  if (inaSysFile!=NULL) {
    fgets(readBuf,10,inaSysFile);
  } else {
    strncpy(readBuf,"readfail\0",9);
  }
  logMsgVal.append("shunt_i: ");
  logMsgVal.append(readBuf);
  logMsgVal.append(" :: ");
  memset(readBuf, 0, sizeof(readBuf));
  fclose(inaSysFile);

  inaSysFile=fopen("/sys/bus/i2c/devices/1-0040/power1_input","r");
  if (inaSysFile!=NULL) {
    fgets(readBuf,10,inaSysFile);
  } else {
    strncpy(readBuf,"readfail\0",9);
  }
  logMsgVal.append("power: ");
  logMsgVal.append(readBuf);
  memset(readBuf, 0, sizeof(readBuf));
  fclose(inaSysFile);

  // write to log via shakespeare
  tgtLog=fopen("/tmp/telemetryPowerLog","a");
  Log(tgtLog,logPriority,processName,logMsgVal);

  // close and exit
  fclose(tgtLog);
  return exitStatus;
}
