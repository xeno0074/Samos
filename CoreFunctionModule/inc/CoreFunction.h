#pragma once
#include "EntryModel.h"
#include "SystemDefines.h"

class Core {
  private:
  EntryModel entriesDB[MAX_NUM_ENTRIES];
  int numEntries;

  public:
  Core() = default;
  ~Core() = default;

  int sampleFunc();
  void addEntry(EntryModel input);
  EntryModel *findEntry(Uint8 id);
};
