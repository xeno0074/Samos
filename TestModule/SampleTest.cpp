#include "CoreFunction.h"
#include "DataReader.h"
#include "Initializers/RollingFileInitializer.h"
#include "Log.h"
#include "Utilities.h"
#include "doctest_fwd.h"

int main(int argc, char **argv) {
  plog::init(plog::debug, "LOGS/logs.csv");

  return doctest::Context(argc, argv).run();
}

TEST_CASE("Prototype Test") {
  printf("\nRunning prototype test..\n");

  PREPARE_TEST("\
                  --seed 547 \
                  --bytes_data 50 \
                  --max_id 2001 \
                  --max_amount 100 \
                  --values_txType \"1 0 0\" \
                  --min_year_date \"1 1 2020 12 00 AM\" \
                  --max_year_date \"1 2 2020 12 00 AM\" \
                  --values_tags \"salary shopping rent\"");

  Core core;
  DataReader dataReader("TEST_FILES/entries.csv", core);


  const int numEntries = 500;
  char entryString[numEntries][MAX_ENTRY_BYTES];
  for (int i = 0; i < numEntries; i++) {
    core.getEntry(i)->toStr(entryString[i]);
    printf("%s\n", entryString[i]);
  }

  printf("Logs are stored in LOGS/logs.csv..\n");
  printf("Prototype test complete..\n");
}

TEST_CASE("Date Model Test") {
  printf("\nRunning date model test..\n");

  DateModel d1, d2, d3, d4, d5, d6;
  d1.setDate("1 5 2022 12 30 PM");
  d2.setDate("1 5 2022 1 30 PM");
  d3.setDate("1 5 2022 12 30 AM");
  d4.setDate("1 5 2022 1 30 AM");
  d5.setDate("1 5 2022 10 30 PM");
  d6.setDate("1 5 2022 9 30 AM");

  printf("%d, %d, %d, %d, %d\n", d1 < d2, d2 < d3, d3 < d4, d4 < d5, d5 < d6);
  printf("%d, %d, %d, %d, %d\n", d1 > d2, d2 > d3, d3 > d4, d4 > d5, d5 > d6);

  printf("Date model test complete..\n");
}