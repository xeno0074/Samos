#pragma once
#include "SystemDefines.h"

struct EntryModel {
  Uint8 data[MAX_ENTRY_DATA_BYTES];
  Uint8 id;
  Uint32 amount;
  Uint8 txType;
  struct {
    int dd;
    int mm;
    int yyyy;
    int hour;
    int min;
    int sec;
    int msec;
  } dateTime;
  Uint8 tags[MAX_ENTRY_DATA_BYTES];
};
