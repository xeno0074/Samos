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
  txType = std::stoi(elements[3]);
  dateTime.setDate(elements[4]);
  snprintf(tag, MAX_ENTRY_DATA_BYTES, elements[5]);
}

void EntryModel::toStr(char entryString[MAX_ENTRY_BYTES]) {
  char dateStr[MAX_ENTRY_DATE_BYTES];
  dateTime.toStr(dateStr);
  snprintf(entryString, MAX_ENTRY_BYTES, "%s,%u,%u,%u,%s,%s", data, id, amount, txType, dateStr, tag);
}
