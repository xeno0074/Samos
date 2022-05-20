#include "CoreFunction.h"
#include "doctest.cpp"
#include <stdio.h>

int main(int argc, char **argv) {
  return doctest::Context(argc, argv).run();
}

TEST_CASE("Sample Test") {
  Core *mCore = new Core();
  int coreCreationSuccessful = mCore->sampleFunc();
  if (coreCreationSuccessful) {
    printf("core not created\n");
  } else {
    printf("core created\n");
  }
  REQUIRE(mCore->sampleFunc() == 0);
}

TEST_CASE("Prototype Test"){

}