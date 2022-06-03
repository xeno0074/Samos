//
// Created by Arif Ahmed on 11/05/22.
//
#include "CoreFunctionTest.cpp"
#include "Initializers/RollingFileInitializer.h"
#include "Log.h"
#include "Utilities.h"
#include "doctest.h"

int main(int argc, char **argv) {
  plog::init(plog::debug, "LOGS/logs.csv");

  return doctest::Context(argc, argv).run();
}