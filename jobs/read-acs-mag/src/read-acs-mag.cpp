/*
X - > X axis
Y - > Y axis
Z - > Z axis
r - > range
s - > scale
rf - > read failed
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <shakespeare.h>
#include <i2c-device.h>
#define LOG_DIR "/home/logs/"
#define PROCESS_PATH "HMC5843PATH"
#define LOG_PATH "/home/logs"

//Error codes
#define NULL_PATH_ERROR 2;
#define NULL_DEVICENAME_ERROR 3;

uint8_t process_id = CS1_ACS_MAG;
const string process = cs1_systems[process_id];

using namespace std;
using namespace I2CDevice;

char readBuff[100];

int main()
{

	int exitStatus=0;
	char* pPath = getenv("HMC5843PATH");

	/*********************HMC5883L X axis Raw********************/
	readDevice(pPath, "/in_magn_x_raw");
	/************************************************************/

	/*********************HMC5883L Y axis Raw********************/
	readDevice(pPath, "/in_magn_y_raw");
	/************************************************************/

	/*********************HMC5883L Z axis Raw********************/
	readDevice(pPath, "/in_magn_z_raw");
	/************************************************************/

	/***********************HMC5883L Range***********************/
	readDevice(pPath, "/in_magn_range");
	/************************************************************/;

	/***********************HMC5883L Scale***********************/
	readDevice(pPath, "/in_magn_scale");
	/************************************************************/

  return exitStatus;

}
