#pragma once
#include "DateModel.h"
#include "SystemDefines.h"

class EntryModel {
  public:
  char data[MAX_ENTRY_DATA_BYTES];
  Uint16 id;
  Uint32 amount;
  Uint8 txType;
  DateModel dateTime;
  char tag[MAX_ENTRY_TAG_BYTES];

  EntryModel();
  explicit EntryModel(const char entryString[MAX_ENTRY_BYTES]);

  void toStr(char entryString[MAX_ENTRY_BYTES]);
};
