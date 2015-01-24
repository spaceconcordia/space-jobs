#include "gtest/gtest.h"

class Read_Pwr_Ina219_Test : public ::testing::Test
{
    protected:
        virtual void SetUp() { }
        int z=0;
};
//++++++++++++++++++++++++++++++++++++++logToShakespeare() Testing++++++++++++++++++++++++++++++++++++++++

// The same process that leads to the final char array (timeAndPeakData) for logging is repeated here,
// assuming proper data sent to binaryPeakMagData and detecionTime, then the logToShakespeare() function is called with
// to log
TEST_F(Read_Pwr_Ina219_Test, logCorrectDataNoticeShakespeare)
{
    clock_t start_time = clock();
    //The expected data from I2C should be a 12-bit char array
    char binaryPeakMagData[12 + 1] = {0,0,0,0,1,0,1,0,1,0,1,0};
    char detectionTimeData[10];
    //Determine etermine elapsed time for detection
    clock_t elapsed_time = clock() - start_time;

    //Store peak detection time to temporary variable
    float detectionTime = ((float)elapsed_time/CLOCKS_PER_SEC);
    sprintf(detectionTimeData, "%f", detectionTime);

    //Log peak magnitude and detection times using Shakspeare
    char *temp = strcat(detectionTimeData, " ");
    char *timeAndPeakData = strcat(temp, binaryPeakMagData);

    int logReturn = logToShakespeare(timeAndPeakData, "NOTICE");
    ASSERT_EQ(
        CS1_SUCCESS, // expected
        logReturn // actual
    );
}


//---------------------------------------------------------------------------------------------------------
