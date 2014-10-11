#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <SpaceDecl.h>
#include <shakespeare.h>

#define PROCESS "job-template"

using namespace std;

int main()
{
  // see space-lib/include/SpaceDecl.h for global exit statuses, or define your own
  int exitStatus=CS1_SUCCESS;

  short int dummy_sensor_reading = 42;

  Shakespeare::log(Shakespeare::NOTICE, PROCESS, "This is a notice message");
  Shakespeare::log(Shakespeare::ERROR, PROCESS, "This is an error message");

  Shakespeare::log_bin(Shakespeare::NOTICE, PROCESS, dummy_sensor_reading); // log sensor readings in binary

  // close and exit
  fclose(logfile);
  return exitStatus;
}
