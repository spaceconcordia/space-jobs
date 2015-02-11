/*
 * =====================================================================================
 *
 *       Filename:  read-temp-EBPL.h
 *
 *    Description:  Custom functions for use with read-temp-EBPL.cpp
 *
 *        Version:  1.0
 *        Created:  02/07/2015 05:54:39 PM
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
