//
// Created by Arif Ahmed on 11/05/22.
//
#include "CoreFunctionTest.h"
#include "doctest_fwd.h"

TEST_CASE("CoreFunctionTest") {
  CoreTest &coreTest = CoreTest::getInstance();
  Core *pCore = coreTest.getCore();

  EntryModel entries[MAX_NUM_ENTRIES];

  SUBCASE("addEntry.Test") {
    //      pCore->addEntry();
  }

  REQUIRE(1 != 0);
}