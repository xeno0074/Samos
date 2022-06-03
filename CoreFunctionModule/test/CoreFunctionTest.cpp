//
// Created by Arif Ahmed on 11/05/22.
//
#include "CoreFunctionTest.h"
#include "DataReader.h"
#include "DataWriter.h"
#include "TestHelper.h"
#include "Utilities.h"
#include "doctest.h"
#include <cstdlib>
#include <sstream>

TEST_CASE("CoreFunction.Test") {
  Core &core = CoreTest::getInstance().getCore();
  TestHelper testHelper;
  char testName[MAX_TEST_NAME_CHARS];

  PREPARE_TEST("--max_id 3000");

  SUBCASE("entries.Test") {
    DataReader dataReader("TEST_FILES/entries.csv", core);
    DataWriter dataWriter("TEST_FILES/out_entries.csv", core);

    int diff = testHelper.compareEntryFiles("TEST_FILES/entries.csv", "TEST_FILES/out_entries.csv");
    snprintf(testName, MAX_TEST_NAME_CHARS, "[entries.Test]");
    testHelper.reportResults(testName, diff);

    REQUIRE(diff == 0);
  }
}