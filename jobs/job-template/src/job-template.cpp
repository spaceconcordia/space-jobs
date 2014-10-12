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

uint8_t process_id = CS1_UNDEF_SUB; // change this once your job is registered in SpaceDecl.h and cs1_systems.cpp
const string process = cs1_systems[process_id];

using namespace std;

int main()
{
  // see space-lib/include/SpaceDecl.h for global exit statuses, or define your own

  short int dummy_sensor_reading = 42;

  Shakespeare::log(Shakespeare::NOTICE, process, "This is a notice message");
  Shakespeare::log(Shakespeare::ERROR, process, "This is an error message");

  Shakespeare::log_bin(Shakespeare::NOTICE, process_id, dummy_sensor_reading); // log sensor readings in binary

  return CS1_SUCCESS;
}
