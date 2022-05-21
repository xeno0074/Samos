#include "CoreFunction.h"
#include "DataReader.h"
#include "doctest.cpp"
#include <stdio.h>

int main(int argc, char **argv) { return doctest::Context(argc, argv).run(); }

TEST_CASE("Sample Test") {
  printf("\nRunning sample test..\n");
  Core *mCore = new Core();
  int coreCreationSuccessful = mCore->sampleFunc();
  if (coreCreationSuccessful) {
    printf("Core not created..\n");
  } else {
    printf("Core created..\n");
  }
  REQUIRE(mCore->sampleFunc() == 0);

  printf("Sample test complete..\n");
}

TEST_CASE("Prototype Test") {
  printf("\nRunning prototype test..\n");

  Core core;

  const char filePath[] = "entries.csv";
  DataReader dataReader(filePath, core);

  printf("Prototype test complete..\n");
}