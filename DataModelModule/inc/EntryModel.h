#pragma once
#include "SystemDefines.h"

struct EntryModel {
  Uint8 data[MAX_ENTRY_DATA_BYTES];
  Uint8 id;
  Uint32 amount;
  Uint8 txType;
  Uint8 tags[MAX_ENTRY_DATA_BYTES];
};
