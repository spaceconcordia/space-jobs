/*
 * =====================================================================================
 *
 *       Filename:  read-pwr-ad7998.h
 *
 *    Description:  Custom functions for use with read-pwr-ad7998.cpp
 *
 *        Version:  1.0
 *        Created:  01/24/2015 04:14:15 PM
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
