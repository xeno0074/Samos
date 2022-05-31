//
// Created by Arif Ahmed on 31/05/22.
//

#include "../inc/DataWriter.h"
#include "Log.h"
#include <cstring>
#include <fstream>
#include <sstream>

DataWriter::DataWriter(const char *filePath, Core &core) {
  dumpCore(filePath, core);
  this->~DataWriter();
}

void DataWriter::dumpCore(const char filePath[], Core &core) {
  std::fstream file(filePath);
  if (!file.is_open()) {
    LOG(plog::fatal) << "Couldn't open file " << std::string(filePath);
    return;
  }

  char entryString[MAX_ENTRY_BYTES];
  file.getline(entryString, MAX_ENTRY_BYTES);
  while (!file.eof()) {
    file.getline(entryString, MAX_ENTRY_BYTES);
    if (strcmp(entryString, "")) {
      EntryModel entry(entryString);
      core.addEntry(entry);
    }
  }
}