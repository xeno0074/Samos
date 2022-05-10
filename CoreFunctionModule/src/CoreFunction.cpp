#include "CoreFunction.h"

int Core::sampleFunc() {
  return 0;
}

void Core::addEntry(EntryModel input) {
  if (numEntries >= MAX_NUM_ENTRIES) {
    //  add log for entry overflow
    return;
  }
  input.id = numEntries;
  entriesDB[numEntries] = input;
  numEntries++;
}

EntryModel *Core::findEntry(Uint8 id) {
  for (int entryIndex = 0; entryIndex < numEntries; entryIndex++) {
    if (entriesDB[entryIndex].id == id) {
      return &entriesDB[entryIndex];
    }
  }
  return nullptr;
}