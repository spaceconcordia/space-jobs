#include "gtest/gtest.h"
#include "read-pwr-ina219.cpp"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
