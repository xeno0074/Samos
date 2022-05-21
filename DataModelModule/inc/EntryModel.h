#pragma once
#include "SystemDefines.h"

struct EntryModel {
  char data[MAX_ENTRY_DATA_BYTES];
  Uint16 id;
  Uint32 amount;
  Uint8 txType;
  char dateStr[MAX_ENTRY_DATE_BYTES];
  struct {
    int dd;
    int mm;
    int yyyy;
    int hour;
    int min;
    int sec;
    int msec;
  } dateTime;
  char tag[MAX_ENTRY_TAG_BYTES];
};
