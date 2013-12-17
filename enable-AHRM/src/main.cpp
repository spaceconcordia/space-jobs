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

  // *** note, for now we assume that the GPIO has been pre-configured
  //   direction set to 'out'
  //   active_low set to ???
  // write to GPIO pin
  // this is an active lo switch, write 0 to enable?

  FILE* gpioSysFile;
  gpioSysFile=fopen("/sys/...","w");
  if (gpioSysFile!=NULL) {
    fputc('0',gpioSysFile);
    fclose(gpioSysFile);
    logMsgVal = "enabled AHRM";
  } else {
    logMsgVal = "failed to enable AHRM";
  }

  // write to log via shakespeare
  tgtLog=fopen("/var/log/mechJobLog","a");
  Log(tgtLog,logPriority,processName,logMsgVal);

  // close and exit
  fclose(tgtLog);
  return exitStatus;
}
