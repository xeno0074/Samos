//
// Created by iamar on 5/30/2022.
//
#include "TestHelper.h"
#include "Log.h"
#include "SystemDefines.h"
#include <cstring>
#include <fstream>
#include <sstream>

void TestHelper::compareReport() {}

int TestHelper::compareEntryFiles(const char filePath1[], const char filePath2[]) {
  int diff = 0;
  std::fstream file1(filePath1, std::ios::in);
  std::fstream file2(filePath2, std::ios::in);
  if (!file1.is_open() || !file2.is_open()) {
    LOG(plog::fatal) << "Couldn't open file " << std::string(filePath1) << " or " << std::string(filePath2);
    return UNOPENED_FILE;
  }

  char lineStr1[MAX_ENTRY_BYTES];
  char lineStr2[MAX_ENTRY_BYTES];
  //  remove first line
  file1.getline(lineStr1, MAX_ENTRY_BYTES);
  file2.getline(lineStr2, MAX_ENTRY_BYTES);
  while (!file1.eof()) {
    file1.getline(lineStr1, MAX_ENTRY_BYTES);
    file2.getline(lineStr2, MAX_ENTRY_BYTES);

    if ((strcmp(lineStr1, "") && !strcmp(lineStr2, "")) || (!strcmp(lineStr1, "") && strcmp(lineStr2, ""))) {
      return INVALID_NUM_LINES;
    }
    if (strcmp(lineStr1, lineStr2)) {
      diff++;
    }
  }
  return diff;
}

void TestHelper::readTC01(const char *filePath) {}

void TestHelper::reportResults(char testName[MAX_TEST_NAME_CHARS], int diff) {
  printf("%s results: ", testName);
  switch (diff) {
    case 0:
      printf("[PASS] exactly same\n", testName);
      break;
    case UNOPENED_FILE:
      printf("[ERROR] couldn't open file\n");
      break;
    case INVALID_NUM_LINES:
      printf("[FAIL] invalid test\n");
      break;
    default:
      printf("[FAIL] diff=%d\n", diff);
  }
}