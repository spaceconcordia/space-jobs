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
  processName = "telemetryPwrAd7998";
  //logMsgVal = "Test log payload string";

  // *** note: for now we assume the ad799x driver has already been instantiated 
  // *** power ad799x is hardwired to: 
  //  bus: i2c-1
  //  address: 0x23
  // The data values can be read from the dev system if the existing module is loaded
  // and instantiated
  // Channels 1,3,5,7 are grounded
  // DEV_FILES:
  //  /sys/bus/i2c/devices/1-0023/iio:device./in_voltage2_raw : channel 2 - battery thermistor1 voltage
  //  /sys/bus/i2c/devices/1-0023/iio:device./in_voltage4_raw : channel 4 - battery thermistor2 voltage
  //  /sys/bus/i2c/devices/1-0023/iio:device./in_voltage6_raw : channel 6 - solar panel1_3 voltage divider
  //  /sys/bus/i2c/devices/1-0023/iio:device./in_voltage8_raw : channel 8 - solar panel2_4 voltage divider

  FILE* adSysFile;
  char readBuf[10];
  size_t lastLen=0;

  adSysFile=fopen("/sys/bus/i2c/devices/1-0023/iio:device./in_voltage2_raw","r");
  if (adSysFile!=NULL) {
    fgets(readBuf,10,adSysFile);
    fclose(adSysFile);
  } else {
    strncpy(readBuf,"readfail\n",9);
  }
  logMsgVal.append("v: ");
  lastLen=logMsgVal.length()+1;
  logMsgVal.append(readBuf);
  logMsgVal.erase(logMsgVal.find("\n",lastLen),string::npos);
  logMsgVal.append(" :: ");
  memset(readBuf, 0, sizeof(readBuf));

  // write to log via shakespeare
  tgtLog=fopen("/tmp/telemetryPowerLog","a");
  Log(tgtLog,logPriority,processName,logMsgVal);

  // close and exit
  fclose(tgtLog);
  return exitStatus;
}