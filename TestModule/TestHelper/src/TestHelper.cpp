//
// Created by iamar on 5/30/2022.
//
#include "TestHelper.h"
#include "EntryModel.h"
#include "Log.h"
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
    return -1;
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
      return -1;
    }
    if (strcmp(lineStr1, lineStr2)) {
      diff++;
    }
  }
  return diff;
}
