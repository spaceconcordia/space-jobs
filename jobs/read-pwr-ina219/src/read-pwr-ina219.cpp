#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <shakespeare.h>
#include "i2c-device.h"
#define LOG_DIR "/home/logs/"
#define PROCESS_NAME "telemetryINA219"
#define PROCESS_PATH "INA2XXPATH"
#define LOG_PATH "/home/logs"

//Error codes
#define NULL_PATH_ERROR 2;
#define NULL_DEVICENAME_ERROR 3;

uint8_t process_id = CS1_PWR_INA219;
const string process = cs1_systems[process_id];

using namespace std;
using namespace I2CDevice;

char readBuff[100];

int main()
{
	int exitStatus=0;
  char* pPath = getenv(PROCESS_PATH);


 	/******** /sys/bus/i2c/devices/1-0040/curr1_input  :: current through Rsens ********/
	readDevice(pPath, "/curr1_input");
	/***********************************************************************************/

	/******** /sys/bus/i2c/devices/1-0040/in0_input    :: voltage across Rsens ********/
	readDevice(pPath, "/in0_input");
	/***********************************************************************************/

	/******** /sys/bus/i2c/devices/1-0040/in1_input    :: voltage from Bus to Gnd ********/
	readDevice(pPath, "/in1_input");
	/***********************************************************************************/

	/********  /sys/bus/i2c/devices/1-0040/power1_input :: power through Rsens ********/
	readDevice(pPath, "/power1_input");
	/***********************************************************************************/

	return exitStatus;

}
