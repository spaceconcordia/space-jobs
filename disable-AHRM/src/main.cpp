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
  processName = "mechAHRM";

  // write to GPIO pin

  FILE* gpioSysFile;
  gpioSysFile=fopen("/sys/...","w");
  if (gpioSysFile!=NULL) {
    // fgets(readBuf,10,gpioSysFile);
    fclose(gpioSysFile);
    logMsgVal = "enabled AHRM";
  } else {
    logMsgVal = "failed to enable AHRM";
  }

  // write to log via shakespeare
  tgtLog=fopen("/var/log/","a");
  Log(tgtLog,logPriority,processName,logMsgVal);

  // close and exit
  fclose(tgtLog);
  return exitStatus;
}
