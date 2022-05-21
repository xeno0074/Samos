#pragma once
#include "EntryModel.h"
#include "SystemDefines.h"

class Core {
  private:
  EntryModel entriesDB[MAX_NUM_ENTRIES];
  Uint8 numEntries;
  Uint32 totalCredit;
  Uint32 totalDebit;

  public:
  Core();
  ~Core() = default;

  void addEntry(EntryModel input);
  EntryModel &findEntry(Uint16 id);
};
