//
// Created by Arif Ahmed on 11/05/22.
//
#include "CoreFunctionTest.h"
#include "doctest.cpp"

TEST_CASE("CoreFunction.Test") {
  CoreTest &coreTest = CoreTest::getInstance();
  EntryModel entry[MAX_NUM_ENTRIES];

    SUBCASE("addEntry.Test") {
      pCore->addEntry()
    }
}