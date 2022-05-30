//
// Created by Arif Ahmed on 5/21/2022.
//
#include "DataReader.h"
#include "Log.h"
#include <cstring>
#include <fstream>
#include <sstream>

DataReader::DataReader(const char *filePath, Core &core) {
  fillCore(filePath, core);
  this->~DataReader();
}

void DataReader::fillCore(const char filePath[], Core &core) {
  std::fstream file(filePath);
  if (!file.is_open()) {
    LOG(plog::fatal) << "Couldn't open file " << std::string(filePath);
    return;
  }

  char entryString[MAX_ENTRY_BYTES];
  //  remove first line
  file.getline(entryString, MAX_ENTRY_BYTES);
  while (!file.eof()) {
    file.getline(entryString, MAX_ENTRY_BYTES);
    if (strcmp(entryString, "")) {
      core.addEntry(EntryModel(entryString));
    }
  }
}
