#pragma once
#include "EntryModel.h"
#include "SystemDefines.h"

class Core {
  private:
  EntryModel entriesDB[MAX_NUM_ENTRIES];
  Uint8 numEntries;
  Uint32 totalCredit;
  Uint32 totalDebit;
  Uint16 idList[MAX_NUM_ENTRIES];//  0 if the corresponding entry in entriesDB is empty (deleted)

  public:
  Core();
  ~Core() = default;

  void addEntry(EntryModel input);
  void addEntrySort(EntryModel input);
  EntryModel *getEntry(Uint16 id);
  void generateReport();
};
