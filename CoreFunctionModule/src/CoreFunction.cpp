#include "CoreFunction.h"

Core::Core() : numEntries(0), totalCredit(0), totalDebit(0) {}

void Core::addEntry(EntryModel input) {
  if (input.id >= MAX_NUM_ENTRIES) {
    // todo arif : add log for entry overflow
    return;
  }
  entriesDB[input.id] = input;

  //  update member parameters
  numEntries++;
  totalCredit += Uint8(input.txType) * input.amount;
  totalDebit += Uint8(!input.txType) * input.amount;
}

EntryModel &Core::findEntry(Uint16 id) {
  //  for (int entryIndex = 0; entryIndex < numEntries; entryIndex++) {
  //    if (entriesDB[entryIndex].id == id) { return &entriesDB[entryIndex]; }
  //  }
  return entriesDB[id];
}
