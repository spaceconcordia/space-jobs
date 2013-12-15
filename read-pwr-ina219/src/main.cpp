//#include <system.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <fstream>
#include "shakespeare.h"

using namespace std;

int main()
{
 
  int exitStatus=0;
  // variables needed to call shakespeare log function
  FILE* tgtLog;
  tgtLog=fopen("/tmp/telemetryPowerLog","a");
  Priority logPriority = NOTICE;
  string processName,logMsgVal;
  processName = "telemetryPwrIna219";
  logMsgVal = "Test log payload string";
  // variables needed to retrieve ina status



  // write to log via shakespeare
  Log(tgtLog,logPriority,processName,logMsgVal);

  // close and exit
  fclose(tgtLog);
  return exitStatus;
}
