//
// Created by iamar on 5/21/2022.
//
#include "DataReader.h"
#include <fstream>
#include <sstream>

DataReader::DataReader(const char *filePath, Core &core) {
  prepare(filePath);
  process(core);
}

void DataReader::prepare(const char *filePath) { snprintf(this->filePath, MAX_FILENAME_BYTES, filePath); }

EntryModel DataReader::makeEntry(const char entryString[MAX_ENTRY_BYTES]) {
  std::stringstream entryStream(entryString);
  char elements[MAX_COLUMNS][MAX_ENTRY_DATA_BYTES];
  char tmp[MAX_ENTRY_DATA_BYTES];
  EntryModel entry;

  for (Uint8 columnIndex = 0; entryStream.getline(tmp, MAX_ENTRY_DATA_BYTES, ','); columnIndex++) {
    snprintf(elements[columnIndex], MAX_ENTRY_DATA_BYTES, tmp);
  }
  snprintf(entry.data, MAX_ENTRY_DATA_BYTES, elements[0]);
  entry.id = std::stoi(elements[1]);
  entry.amount = std::stoi(elements[2]);
  if (!strcmp(elements[3], "credit")) {
    entry.txType = 1;
  } else {
    entry.txType = 0;
  }
  snprintf(entry.dateStr, MAX_ENTRY_DATA_BYTES, elements[4]);
  //  todo arif : convert dateStr to dateTime
  snprintf(entry.tag, MAX_ENTRY_DATA_BYTES, elements[5]);

  //  printf("%s, %d, %d, %d, %s, %s\n", entry.data, entry.id, entry.amount, entry.txType, entry.dateStr, entry.tag);

  return entry;
}

void DataReader::process(Core &core) {
  std::ifstream file(filePath, std::ios::in | std::ios::beg);
  if (!file.is_open()) {
    // todo arif : add log for unopened file
    return;
  }

  char entryString[MAX_ENTRY_BYTES];
  //  remove first line
  file.getline(entryString, MAX_ENTRY_BYTES);
  while (!file.eof()) {
    file.getline(entryString, MAX_ENTRY_BYTES);
    if (strcmp(entryString, "")) { core.addEntry(makeEntry(entryString)); }
  }
}
