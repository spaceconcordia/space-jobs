//#include <system.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>
#include <fstream>
#include <sys/ioctl.h>
#include <sys/fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
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
  processName = "telemetryPwrIna219";
  logMsgVal = "Test log payload string";

  // variables needed to retrieve ina status
  // *** note: for now we assume the ina2xx driver has already been instantiated 
  // *** ina219 is hardwired to: 
  //   i2c bus: 1 
  //   bus addr: 0x40
  //   shunt resistor: 10mOhm
  // *** ina219 internal register address table
  // addr(hex) name
  //  00h      Config Reg
  //  01h      Shunt Voltage Reg
  //  02h      Bus Voltage Reg
  //  03h      Power Reg
  //  04h      Current Reg
  //  05h      Calibration Reg

  //FILE* i2cDevFile;
  int i2cDevFile;
  int addr = 0x40;
  __u8 tgtRegister = 0x02;
  __s32 res;
  char buf[10];
  memset(buf, 0, sizeof(buf));

  // open i2c bus
  i2cDevFile=open("/dev/i2c-1",O_RDWR);
  if (i2cDevFile<0 ) {
    cout << "Failed to open i2c-1" << endl;
    exit(1);
  }
  // tell i2c bus what device address to address
  if (ioctl(i2cDevFile, I2C_SLAVE, addr) < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    cout << "Failed to set addr 0x40" << endl;
    exit(2);
  }

  buf[0]=tgtRegister;
  res = write(i2cDevFile,buf,1); 
  buf[0]=0x00;
  res = read(i2cDevFile,buf,1);
  if (res==1) {  
    cout << "byte read success:" << buf[0] << endl; 
  }

  /* Using SMBus commands */
  //res = i2c_smbus_read_word_data(i2cDevFile, tgtRegister);
  //if (res < 0) {
  //  /* ERROR HANDLING: i2c transaction failed */
  //} else {
  //  cout << res << endl ;/* res contains the read word */
  //}

  close(i2cDevFile);

  // write to log via shakespeare
  tgtLog=fopen("/tmp/telemetryPowerLog","a");
  Log(tgtLog,logPriority,processName,logMsgVal);

  // close and exit
  fclose(tgtLog);
  return exitStatus;
}
