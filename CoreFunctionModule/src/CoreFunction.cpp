#include "CoreFunction.h"
#include "Log.h"
#include <string>

Core::Core() : numEntries(0), totalCredit(0), totalDebit(0) {
  memset(idList, 0, MAX_NUM_ENTRIES);
}

void Core::addEntry(EntryModel input) {
  if (input.id >= MAX_NUM_ENTRIES) {
    LOG(plog::error) << "Overflow in entryDB";
    return;
  }
  entriesDB[numEntries] = input;
  idList[numEntries] = input.id;

  //  update member parameters
  numEntries++;
  totalCredit += Uint8(input.txType) * input.amount;
  totalDebit += Uint8(!input.txType) * input.amount;
}

void Core::addEntrySort(EntryModel input) {
  if (input.id >= MAX_NUM_ENTRIES) {
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
    if (idList[entryIndex] == id) {
      //  return the pointer to the entry
      return &entriesDB[entryIndex];
    }
  }

  //  entry doesn't exist
  return nullptr;
}

void Core::generateReport() {}