#include "CoreFunction.h"
#include "doctest.cpp"
//todo arif: fix doctest.cpp as include issue
#include <stdio.h>

int main(int argc, char **argv) { return doctest::Context(argc, argv).run(); }

TEST_CASE("Sample Test") {
  Core *mCore = new Core();
  int coreCreationSuccessful = mCore->sampleFunc();
  if (coreCreationSuccessful) {
    printf("core not created");
  } else {
    printf("core created");
  }
  REQUIRE(mCore->sampleFunc() == 0);
}