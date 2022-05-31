#pragma once
#include "EntryModel.h"
#include "SystemDefines.h"

class Core {
  private:
  EntryModel entriesDB[MAX_NUM_ENTRIES];
  Uint16 numEntries;
  Uint32 totalCredit;
  Uint32 totalDebit;

  public:
  Core();
  ~Core() = default;

  void addEntry(EntryModel input);
  void addEntrySort(EntryModel input);

  EntryModel *getEntry(Uint16 id);

  Uint16 getNumEntries();
  Uint32 getTotalCredit();
  Uint32 getTotalDebit();

  void generateReport();

  friend class DataWriter;
};
