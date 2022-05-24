//
// Created by Arif Ahmed on 23/05/22.
//

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
};

#endif//SAMOSC_DATEMODEL_H
