#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <shakespeare.h>
#include <SpaceDecl.h>

using namespace std;

int main()
{
  // main function variables 
  int exitStatus=0;

  // variables needed to call shakespeare log function
  string processName,logMsgVal;
  processName = CS1_MECH_AHRM;

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
  Shakespeare::log(Shakespeare::NOTICE,processName,logMsgVal);

  return exitStatus;
}
