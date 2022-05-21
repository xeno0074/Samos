#include "CoreFunction.h"
#include "DataReader.h"
#include "doctest.cpp"
#include <stdio.h>

int main(int argc, char **argv) { return doctest::Context(argc, argv).run(); }

TEST_CASE("Prototype Test") {
  printf("\nRunning prototype test..\n");

  Core core;
  DataReader dataReader("entries.csv", core);

  printf("Prototype test complete..\n");
}