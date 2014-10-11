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
  string processName,logMsgVal;
  processName = "mechAHRM";

  // *** note, for now we assume that the GPIO has been pre-configured
  //   direction set to 'out'
  //   active_low set to 1
  //   pin values:
  //     1 = disabled
  //     0 = enabled
  // write to GPIO pin
  // this is an active lo switch, write 0 to enable

  char pinValue='0';

  FILE* gpioSysFile;
  gpioSysFile=fopen("/dev/gpios/consat/GPIO_./value","w");
  if (gpioSysFile!=NULL) {
    fputc(pinValue,gpioSysFile);
    fclose(gpioSysFile);
    logMsgVal = "enabled AHRM";
  } else {
    logMsgVal = "failed to enable AHRM";
  }

  Shakespeare::log(Shakespeare::NOTICE,processName,logMsgVal);

  return exitStatus;
}
