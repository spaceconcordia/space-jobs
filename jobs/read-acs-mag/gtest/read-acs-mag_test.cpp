#include "gtest/gtest.h"

class read-acs-mag_Test : public ::testing::Test
{
    protected:
    virtual void SetUp() { }
    int z=0;
};


//++++++++++++++++++++++++++++++++++++++readDevice() Testing++++++++++++++++++++++++++++++++++++++++

// Test that the readDevice function returns success when passed the correct pPath and "/in_magn_x_raw" device
TEST_F(read-acs-mag_Test, readFromCurr1)
{
  /*********************HMC5883L X axis Raw********************/
    int readDeviceReturn = readDevice(pPath, "/in_magn_x_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "/in_magn_y_raw" device
TEST_F(read-acs-mag_Test, readFromIn0)
{
  /*********************HMC5883L Y axis Raw********************/
    int readDeviceReturn = readDevice(pPath, "/in_magn_y_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "/in_magn_z_raw" device
TEST_F(read-acs-mag_Test, readFromIn1)
{
  /*********************HMC5883L Z axis Raw********************/
    int readDeviceReturn = readDevice(pPath, "/in_magn_z_raw");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "/in_magn_range" device
TEST_F(read-acs-mag_Test, readFromPower1)
{
  /*********************HMC5883L Range********************/
    int readDeviceReturn = readDevice(pPath, "/in_magn_range");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns success when passed the correct pPath and "/in_magn_scale" device
TEST_F(read-acs-mag_Test, readFromPower1)
{
  /*********************HMC5883L Scale********************/
    int readDeviceReturn = readDevice(pPath, "/in_magn_scale");

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns a null path error when passed a null path
TEST_F(read-acs-mag_Test, readFromNullPath)
{
    int readDeviceReturn = readDevice(NULL, "/in_magn_x_raw");

    ASSERT_EQ(
        NULL_PATH_ERROR, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns a null device error when passed a null device
TEST_F(read-acs-mag_Test, readFromNullDevice)
{
    int readDeviceReturn = readDevice(pPath, NULL);

    ASSERT_EQ(
        NULL_DEVICENAME_ERROR, // expected
        readDeviceReturn // actual
    );
}

// Test that the readDevice function returns a null path error when passed a null path and null device
TEST_F(read-acs-mag_Test, readFromNullPathNullDevice)
{
    int readDeviceReturn = readDevice(NULL, NULL);

    ASSERT_EQ(
        NULL_PATH_ERROR, // expected
        readDeviceReturn // actual
    );
}

//---------------------------------------------------------------------------------------------------------
