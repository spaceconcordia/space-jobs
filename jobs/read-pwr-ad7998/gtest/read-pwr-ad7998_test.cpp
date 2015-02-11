#include "gtest/gtest.h"

class Read_Pwr_Ad7998_Test : public ::testing::Test
{
    protected:
        virtual void SetUp() { }
        int z=0;
};


//++++++++++++++++++++++++++++++++++++++readDevice() Testing++++++++++++++++++++++++++++++++++++++++

// Test that the readDevice function returns success when passed the correct pPath and "in_voltage1_raw" device
TEST_F(Read_Pwr_Ina219_Test, readFromInVoltage1)
{
    /****  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage1_raw : channel 2 - battery thermistor1 voltage ****/
    int readDeviceReturn = readDevice(pPath, "/in_voltage1_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage3_raw" device
TEST_F(Read_Pwr_Ad7998_Test, readFromInVoltage3)
{
    /****  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage3_raw : channel 4 - battery thermistor2 voltage ****/
    int readDeviceReturn = readDevice(pPath, "/in_voltage3_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage6_raw" device
TEST_F(Read_Pwr_Ina219_Test, readFromInVoltage6)
{
    /****  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage5_raw : channel 6 - solar panel1_3 voltage divider ****/
    int readDeviceReturn = readDevice(pPath, "/in_voltage6_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage7_raw" device
TEST_F(Read_Pwr_Ina219_Test, readFromInVoltage7)
{
      /****  /sys/bus/i2c/devices/1-0023/iio:device3/in_voltage7_raw : channel 8 - solar panel2_4 voltage divider ****/
    int readDeviceReturn = readDevice(pPath, "/in_voltage7_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns a null path error when passed a null path
TEST_F(Read_Pwr_Ina219_Test, readFromNullPath)
{
    int readDeviceReturn = readDevice(NULL, "/in_voltage1_raw");

    ASSERT_EQ(
        NULL_PATH_ERROR, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns a null device error when passed a null device
TEST_F(Read_Pwr_Ina219_Test, readFromNullDevice)
{
    int readDeviceReturn = readDevice(pPath, NULL);

    ASSERT_EQ(
        NULL_DEVICENAME_ERROR, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns a null path error when passed a null path and null device
TEST_F(Read_Pwr_Ina219_Test, readFromNullPathNullDevice)
{
    int readDeviceReturn = readDevice(NULL, NULL);

    ASSERT_EQ(
        NULL_PATH_ERROR, // expected
        readDeviceReturn // actual
    );
}

//---------------------------------------------------------------------------------------------------------
