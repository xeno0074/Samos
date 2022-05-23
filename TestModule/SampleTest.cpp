#include "CoreFunction.h"
#include "DataReader.h"
#include "doctest.cpp"

int main(int argc, char **argv) { return doctest::Context(argc, argv).run(); }

TEST_CASE("Prototype Test") {
  printf("\nRunning prototype test..\n");

  system("python3 conf_gen.py \
                  --seed 547 \
                  --bytes_data 50 \
                  --max_id 10 \
                  --max_amount 100 \
                  --values_txType \"1 0 0\" \
                  --min_year_date \"1 1 2020 12 00 AM\" \
                  --max_year_date \"1 2 2020 12 00 AM\" \
                  --values_tags \"salary shopping rent\"");

  system("python3 entries_gen.py");

  Core core;
  DataReader dataReader("INPUT_FILES/entries.csv", core);


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

  printf("Date model test complete..\n");
}