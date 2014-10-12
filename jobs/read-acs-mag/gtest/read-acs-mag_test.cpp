#include "gtest/gtest.h"

class read-acs-mag_Test : public ::testing::Test
{
    protected:
    virtual void SetUp() { }
    int z=0;
};

// Test writing to the helium device
TEST_F(read-acs-mag_Test, GetCorrectI2CPath)
{
    string test_identifier = "TeleACS";
    char * output_path = {0};

    int get_path_result = get_i2c_path(test_identifier, actual_path);

    char * expected_path = "/sys/bus/i2c/foo/bar/";

    ASSERT_EQ(
        CS1_SUCCESS, // expected
        get_path_result // actual
    );

    for (z=0; z<36; z++) {
        printf("z=%d\n",z);
        ASSERT_EQ(
            expected_path[z],
            actual_path[z]
        );
    }

    ASSERT_EQ(
       CS1_NULL_POINTER,
       get_path_result 
    ); 
}

// TODO regenerate sample bytes from latest HE100 boards
TEST_F(read-acs-mag_Test, BoilerPlateArray)
{


    unsigned char expected[36] = {0x01,0x02,0x03};
    unsigned char actual[36] = {0x01,0x02,0x03};
    
    for (z=0; z<36; z++) {
        printf("z=%d\n",z);
        ASSERT_EQ(
            expected[z],
            actual[z]
        );
    }
}   
