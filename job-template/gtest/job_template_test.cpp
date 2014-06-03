#include "gtest/gtest.h"

class job_template_Test : public ::testing::Test
{
    protected:
    virtual void SetUp() { }
    int z=0;
};

// Test writing to the helium device
TEST_F(job_template_Test, BoilerPlate)
{
    ASSERT_EQ(
        0, // expected
        0 // actual
    );
}

// TODO regenerate sample bytes from latest HE100 boards
TEST_F(job_template_Test, BoilerPlateArray)
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
