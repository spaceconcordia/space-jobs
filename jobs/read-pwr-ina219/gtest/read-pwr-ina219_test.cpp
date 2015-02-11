#include "gtest/gtest.h"

class Read_Pwr_Ina219_Test : public ::testing::Test
{
    protected:
        virtual void SetUp() { }
        int z=0;
};

//++++++++++++++++++++++++++++++++++++++readDevice() Testing++++++++++++++++++++++++++++++++++++++++

// Test that the readDevice function returns success when passed the correct pPath and "curr1_input" device
TEST_F(Read_Pwr_Ina219_Test, readFromCurr1)
{
    /******** /sys/bus/i2c/devices/1-0040/curr1_input  :: current through Rsens ********/
    int readDeviceReturn = readDevice(pPath, "/curr1_input");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "in0_input" device
TEST_F(Read_Pwr_Ina219_Test, readFromIn0)
{
    /******** /sys/bus/i2c/devices/1-0040/in0_input    :: voltage across Rsens ********/
    int readDeviceReturn = readDevice(pPath, "/in0_input");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "in1_input" device
TEST_F(Read_Pwr_Ina219_Test, readFromIn1)
{
    /******** /sys/bus/i2c/devices/1-0040/in1_input    :: voltage from Bus to Gnd ********/
    int readDeviceReturn = readDevice(pPath, "/in1_input");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "power1_input" device
TEST_F(Read_Pwr_Ina219_Test, readFromPower1)
{
    /********  /sys/bus/i2c/devices/1-0040/power1_input :: power through Rsens ********/
    int readDeviceReturn = readDevice(pPath, "/power1_input");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns a null path error when passed a null path
TEST_F(Read_Pwr_Ina219_Test, readFromNullPath)
{
    int readDeviceReturn = readDevice(NULL, "/curr1_input");

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
