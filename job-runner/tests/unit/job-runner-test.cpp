/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* AUTHORS : Space Concordia 2014, Joseph
*
* TITLE : getlog-command-test.cpp 
*
* DESCRIPTION : Tests the GetLogCommand class
*
*----------------------------------------------------------------------------*/
#include <time.h>
#include <unistd.h>
#include <dirent.h>     // DIR
#include <sys/types.h>

#include "CppUTest/TestHarness.h"
#include "CppUTest/MemoryLeakDetectorMallocMacros.h"
#include "SpaceDecl.h"

TEST_GROUP(JobRunnerTestGroup)
{
    void setup()
    {
    }
    void teardown()
    {
    }
};

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* GROUP : JobRunnerTestGroup
*
* NAME : Check_Zombie_Not_Created
* 
*-----------------------------------------------------------------------------*/
TEST(JobRunnerTestGroup, Check_Zombie_Not_Created)
{
    CHECK(0 == 0);
}
