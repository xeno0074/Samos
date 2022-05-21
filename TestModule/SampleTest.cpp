#include "CoreFunction.h"
#include "DataReader.h"
#include "doctest.cpp"
#include <stdio.h>

int main(int argc, char **argv) {
  return doctest::Context(argc, argv).run();
}

TEST_CASE("Sample Test") {
  printf("Running sample test..\n");
  Core *mCore = new Core();
  int coreCreationSuccessful = mCore->sampleFunc();
  if (coreCreationSuccessful) {
    printf("Core not created..\n");
  } else {
    printf("Core created..\n");
  }
  REQUIRE(mCore->sampleFunc() == 0);
}

TEST_CASE("Prototype Test") {
  printf("Running prototype test..\n");
  DataReader dataReader;
  dataReader.sampleFunc();
}