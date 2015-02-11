#include "gtest/gtest.h"
#include "read-pwr-ad7998.cpp"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
