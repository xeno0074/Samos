//
// Created by iamar on 5/30/2022.
//

#ifndef SAMOSC_TESTHELPER_H
#define SAMOSC_TESTHELPER_H

constexpr int MAX_TEST_NAME_CHARS = 25;
constexpr int UNOPENED_FILE = -2;
constexpr int INVALID_NUM_LINES = -1;

class TestHelper {
  public:
  void readTC01(const char filePath[]);

  int compareEntryFiles(const char filePath1[], const char filePath2[]);
  void compareReport();

  void reportResults(char testName[MAX_TEST_NAME_CHARS], int diff);
};

#endif//SAMOSC_TESTHELPER_H
