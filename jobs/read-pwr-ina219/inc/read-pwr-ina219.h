/*
 * =====================================================================================
 *
 *       Filename:  read-pwr-ina219.h
 *
 *    Description:  Custom functions for use with read-pwr-ina219.cpp
 *
 *        Version:  1.0
 *        Created:  01/22/2015 05:34:39 PM
 *       Revision:  none
 *       Compiler:
 *
 *         Author:  AUSTIN HUBBELL
 *   Organization:  Space Concordia
 *
 * =====================================================================================
 */

//Read data from an I2C device, and log the process and data using Shakespeare
int readDevice (char* pPath, const char* deviceName);
