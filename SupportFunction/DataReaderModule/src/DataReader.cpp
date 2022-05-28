//
// Created by iamar on 5/21/2022.
//
#include "DataReader.h"
#include "Log.h"
#include <fstream>
#include <sstream>

DataReader::DataReader(const char *filePath, Core &core) {
  fillCore(filePath, core);
  this->~DataReader();
}

EntryModel DataReader::makeEntry(const char entryString[MAX_ENTRY_BYTES]) {
  std::stringstream entryStream(entryString);
  char elements[MAX_COLUMNS][MAX_ENTRY_DATA_BYTES];
  char word[MAX_ENTRY_DATA_BYTES];
  EntryModel entry;

  for (Uint8 columnIndex = 0; entryStream.getline(word, MAX_ENTRY_DATA_BYTES, ','); columnIndex++) {
    snprintf(elements[columnIndex], MAX_ENTRY_DATA_BYTES, word);
  }
  snprintf(entry.data, MAX_ENTRY_DATA_BYTES, elements[0]);
  entry.id = std::stoi(elements[1]);
  entry.amount = std::stoi(elements[2]);
  if (!strcmp(elements[3], "credit")) {
    entry.txType = 1;
  } else {
    entry.txType = 0;
  }
  entry.dateTime.setDate(elements[4]);
  snprintf(entry.tag, MAX_ENTRY_DATA_BYTES, elements[5]);

  return entry;
}

void DataReader::fillCore(const char filePath[], Core &core) {
  std::fstream file(filePath);
  if (!file.is_open()) {
    LOG(plog::fatal) << "Couldn't open file" << std::string(filePath);
    return;
  }

  char entryString[MAX_ENTRY_BYTES];
  //  remove first line
  file.getline(entryString, MAX_ENTRY_BYTES);
  while (!file.eof()) {
    file.getline(entryString, MAX_ENTRY_BYTES);
    if (strcmp(entryString, "")) {
      core.addEntry(makeEntry(entryString));
    }
  }
}
