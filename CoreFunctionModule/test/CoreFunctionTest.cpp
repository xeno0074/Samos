//
// Created by Arif Ahmed on 11/05/22.
//
#include "CoreFunctionTest.h"
#include "DataReader.h"
#include "DataWriter.h"
#include "Utilities.h"
#include "doctest.h"
#include <cstdlib>

TEST_CASE("CoreFunction.Test") {
  Core &core = CoreTest::getInstance().getCore();

  PREPARE_TEST("--max_id 3000");

  SUBCASE("TC01.Test") {
    DataReader dataReader("TEST_FILES/entries.csv", core);
    DataWriter dataWriter("TEST_FILES/out_entries.csv", core);
  }

  REQUIRE(1 != 0);
}