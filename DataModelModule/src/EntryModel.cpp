#include "EntryModel.h"
#include <sstream>

EntryModel::EntryModel() : id(0), amount(0), txType(0) {}

EntryModel::EntryModel(const char entryString[MAX_ENTRY_BYTES]) {
  std::stringstream entryStream(entryString);
  char elements[MAX_COLUMNS][MAX_ENTRY_DATA_BYTES];
  char word[MAX_ENTRY_DATA_BYTES];

  for (Uint8 columnIndex = 0; entryStream.getline(word, MAX_ENTRY_DATA_BYTES, ','); columnIndex++) {
    snprintf(elements[columnIndex], MAX_ENTRY_DATA_BYTES, word);
  }
  snprintf(data, MAX_ENTRY_DATA_BYTES, elements[0]);
  id = std::stoi(elements[1]);
  amount = std::stoi(elements[2]);
  if (!strcmp(elements[3], "credit")) {
    txType = 1;
  } else {
    txType = 0;
  }
  dateTime.setDate(elements[4]);
  snprintf(tag, MAX_ENTRY_DATA_BYTES, elements[5]);
}
