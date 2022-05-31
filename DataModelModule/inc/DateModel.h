//
// Created by Arif Ahmed on 23/05/22.
//

#include "SystemDefines.h"

#ifndef SAMOSC_DATEMODEL_H
#define SAMOSC_DATEMODEL_H

class DateModel {
  private:
  int dd;
  int mm;
  int yyyy;
  int hour;
  int minutes;
  int sec;
  int msec;

  public:
  DateModel();
  void setDate(const char *dateStr);
  bool operator<(const DateModel &date);
  bool operator>(const DateModel &date);

  void toStr(char dateStr[MAX_ENTRY_DATE_BYTES]);
};

#endif//SAMOSC_DATEMODEL_H
