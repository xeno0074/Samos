//
// Created by Arif Ahmed on 23/05/22.
//
#include "DateModel.h"
#include "SystemDefines.h"
#include <sstream>

DateModel::DateModel() : dd(0), mm(0), yyyy(0), hour(0), minutes(0), sec(0), msec(0) {}

void DateModel::setDate(const char *dateStr) {//  dateStr format : '%d %m %Y %I %M %p'
  char word[MAX_DATE_DATA_SIZE];
  char elements[MAX_NUM_ELEMENTS][MAX_DATE_DATA_SIZE];
  std::stringstream dateStrStream(dateStr);

  for (Uint8 elementIndex = 0; dateStrStream.getline(word, MAX_DATE_DATA_SIZE, ' '); elementIndex++) {
    snprintf(elements[elementIndex], MAX_DATE_DATA_SIZE, word);
  }
  dd = std::stoi(elements[0]);
  mm = std::stoi(elements[1]);
  yyyy = std::stoi(elements[2]);
  hour = std::stoi(elements[3]);
  minutes = std::stoi(elements[4]);

  // check if input is 24 hour format
  if (!strcmp(elements[5], "..")) {
    return;
  }

  // convert 12 hour format to 24 hour format
  if (!strcmp(elements[5], "PM") && hour < 12) {
    hour += 12;
  }
  if (!strcmp(elements[5], "AM") && hour == 12) {
    hour = 0;
  }
}
