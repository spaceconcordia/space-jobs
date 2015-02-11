#incl#include "gtest/gtest.h"

class Read_Temp_spts_Test : public ::testing::Test
{
    protected:
        virtual void SetUp() { }
        int z=0;
};



//++++++++++++++++++++++++++++++++++++++readDevice() Testing++++++++++++++++++++++++++++++++++++++++

// Test that the readDevice function returns success when passed the correct pPath and "in_voltage0_raw" device
TEST_F(Read_Temp_spts_Test, readFromInVoltage0)
{
    /*********************AD7998 Temperature Sensor 0********************/
    int readDeviceReturn = readDevice(pPath, "/in_voltage0_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage1_raw" device
TEST_F(Read_Temp_spts_Test, readFromInVoltage1)
{
    /*********************AD7998 Temperature Sensor 1********************/
    int readDeviceReturn = readDevice(pPath, "/in_voltage1_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage2_raw" device
TEST_F(Read_Temp_spts_Test, readFromInVoltage2)
{
    /*********************AD7998 Battery Temperature Sensor 1********************/
    int readDeviceReturn = readDevice(pPath, "/in_voltage2_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage3_raw" device
TEST_F(Read_Temp_spts_Test, readFromInVoltage3)
{
    /*********************AD7998 Battery Temperature Sensor 0********************/
    int readDeviceReturn = readDevice(pPath, "/in_voltage3_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage4_raw" device
TEST_F(Read_Temp_spts_Test, readFromInVoltage4)
{
    /*********************AD7998 Battery Temperature Sensor 2********************/
    int readDeviceReturn = readDevice(pPath, "/in_voltage4_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage5_raw" device
TEST_F(Read_Temp_spts_Test, readFromInVoltage5)
{
    /*********************AD7998 Temperature Sensor 3********************/
    int readDeviceReturn = readDevice(pPath, "/in_voltage5_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage6_raw" device
TEST_F(Read_Temp_spts_Test, readFromInVoltage6)
{
    /*********************AD7998 Payload Temperature Sensor********************/
    int readDeviceReturn = readDevice(pPath, "/in_voltage6_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns success when passed the correct pPath and "/in_voltage7_raw" device
TEST_F(Read_Temp_spts_Test, readFromInVoltage7)
{
    /*********************AD7998 Elec Bay Temperature Sensor********************/
    int readDeviceReturn = readDevice(pPath, "/in_voltage7_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns a null path error when passed a null path
TEST_F(Read_Temp_spts_Test, readFromNullPath)
{
    int readDeviceReturn = readDevice(NULL, "/in_voltage1_raw");

    ASSERT_EQ(
        NULL_PATH_ERROR, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns a null device error when passed a null device
TEST_F(Read_Temp_spts_Test, readFromNullDevice)
{
    int readDeviceReturn = readDevice(pPath, NULL);

    ASSERT_EQ(
        NULL_DEVICENAME_ERROR, // expected
        readDeviceReturn // actual
    );
}


// Test that the readDevice function returns a null path error when passed a null path and null device
TEST_F(Read_Temp_spts_Test, readFromNullPathNullDevice)
{
    int readDeviceReturn = readDevice(NULL, NULL);

    ASSERT_EQ(
        NULL_PATH_ERROR, // expected
        readDeviceReturn // actual
    );
}

//---------------------------------------------------------------------------------------------------------
