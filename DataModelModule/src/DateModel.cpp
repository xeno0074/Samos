//
// Created by Arif Ahmed on 23/05/22.
//
#include "DateModel.h"
#include "SystemDefines.h"
#include <cstring>
#include <sstream>

DateModel::DateModel() : dd(0), mm(0), yyyy(0), hour(0), minutes(0), sec(0), msec(0) {}

void DateModel::setDate(const char *dateStr) {//  dateStr format : '%d %m %Y %I %M %p'
  char word[MAX_DATE_DATA_SIZE];
  char elements[MAX_NUM_ELEMENTS][MAX_DATE_DATA_SIZE];
  std::stringstream dateStrStream(dateStr);
  Uint8 elementIndex;

  for (elementIndex = 0; dateStrStream.getline(word, MAX_DATE_DATA_SIZE, ' '); elementIndex++) {
    snprintf(elements[elementIndex], MAX_DATE_DATA_SIZE, word);
  }
  dd = std::stoi(elements[0]);
  mm = std::stoi(elements[1]);
  yyyy = std::stoi(elements[2]);
  hour = std::stoi(elements[3]);
  minutes = std::stoi(elements[4]);

  // check if input is 24 hour format
  if (elementIndex == 5) {
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

bool DateModel::operator<(const DateModel &date) {
  if (yyyy < date.yyyy) {
    return true;
  }
  if (mm < date.mm) {
    return true;
  }
  if (dd < date.dd) {
    return true;
  }
  if (hour < date.hour) {
    return true;
  }
  if (minutes < date.minutes) {
    return true;
  }
  return false;
}

bool DateModel::operator>(const DateModel &date) {
  if (yyyy > date.yyyy) {
    return true;
  }
  if (mm > date.mm) {
    return true;
  }
  if (dd > date.dd) {
    return true;
  }
  if (hour > date.hour) {
    return true;
  }
  if (minutes > date.minutes) {
    return true;
  }
  return false;
}

void DateModel::toStr(char dateStr[MAX_ENTRY_DATE_BYTES]) {
  // todo arif : optimize
  char meridian[]{"AM"};
  switch (hour) {
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
      hour -= 12;
    case 12:
      meridian[0] = 'P';
      break;
    case 0:
      hour += 12;
      break;
  }

  snprintf(dateStr, MAX_ENTRY_DATE_BYTES, "%02d %02d %d %02d %02d %s", dd, mm, yyyy, hour, minutes, meridian);
}
