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
#define PROCESS "job_template"

using namespace std;

int main()
{
  // main function variables 
  int exitStatus=0;

  // variables needed to call shakespeare log function
  FILE* logfile;
  logfile=Shakespeare::open_log("/var/log/job_template",PROCESS);
  // write to log via shakespeare
  if(logfile!=NULL) {
    Shakespeare::log(logfile, Shakespeare::WARNING, PROCESS, "This is a warning message");
    Shakespeare::log(logfile, Shakespeare::NOTICE, PROCESS, "This is a notice message");
    Shakespeare::log(logfile, Shakespeare::ERROR, PROCESS, "This is an error message");
    Shakespeare::log(logfile, Shakespeare::URGENT, PROCESS, "This is an urgent message");
    Shakespeare::log(logfile, Shakespeare::CRITICAL, PROCESS, "This is a critical message");
  }
  // close and exit
  fclose(logfile);
  return exitStatus;
}
