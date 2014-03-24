#include "gtest/gtest.h"
#include "../inc/timer.h"

class Helium_100_Test : public ::testing::Test
{
    protected:
    virtual void SetUp() { }
};

// Test writing to the helium device
TEST_F(Helium_100_Test, Boilerplate)
{
    ASSERT_EQ(
        0, // expected
        0 // actual
    );
}
