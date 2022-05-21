#include "CoreFunction.h"
#include "DataReader.h"
#include "doctest.cpp"

int main(int argc, char **argv) { return doctest::Context(argc, argv).run(); }

TEST_CASE("Prototype Test") {
  printf("\nRunning prototype test..\n");

  system("py conf_gen.py \
                  --seed 0 \
                  --bytes_data 50 \
                  --max_id 2000 \
                  --max_amount 1000 \
                  --values_txType \"1 0 0\" \
                  --min_year_date 2020 \
                  --max_year_date 2030 \
                  --values_tags \"salary shopping rent\"");

  system("py entries_gen.py");

  Core core;
  DataReader dataReader("INPUT_FILES/entries.csv", core);


  printf("Prototype test complete..\n");
}