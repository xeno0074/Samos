#pragma once
#include "DateModel.h"
#include "SystemDefines.h"

struct EntryModel {
  char data[MAX_ENTRY_DATA_BYTES];
  Uint16 id;
  Uint32 amount;
  Uint8 txType;
  DateModel dateTime;
  char tag[MAX_ENTRY_TAG_BYTES];
};
