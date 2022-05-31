#include "CoreFunction.h"
#include "Log.h"
#include <string>

Core::Core() : numEntries(0), totalCredit(0), totalDebit(0) {}

void Core::addEntry(EntryModel input) {
  if (numEntries >= MAX_NUM_ENTRIES) {
    LOG(plog::error) << "Overflow in entryDB";
    return;
  }
  entriesDB[numEntries] = input;

  //  update member parameters
  numEntries++;
  totalCredit += Uint8(input.txType) * input.amount;
  totalDebit += Uint8(!input.txType) * input.amount;
}

void Core::addEntrySort(EntryModel input) {
  if (numEntries >= MAX_NUM_ENTRIES) {
    LOG(plog::error) << "Overflow in entryDB";
    return;
  }
  entriesDB[numEntries] = input;


  //  update member parameters
  numEntries++;
  totalCredit += Uint8(input.txType) * input.amount;
  totalDebit += Uint8(!input.txType) * input.amount;

  // todo arif : complete this function
}

EntryModel *Core::getEntry(Uint16 id) {
  for (int entryIndex = 0; entryIndex < numEntries; entryIndex++) {
    if (entriesDB[entryIndex].id == id) {
      //  return the pointer to the entry
      return &entriesDB[entryIndex];
    }
  }

  //  entry doesn't exist
  return nullptr;
}

Uint32 Core::getTotalCredit() {
  return totalCredit;
}
Uint32 Core::getTotalDebit() {
  return totalDebit;
}
Uint16 Core::getNumEntries() {
  return numEntries;
}
