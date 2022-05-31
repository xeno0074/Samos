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
  std::fstream file(filePath, std::ios::out);
  if (!file.is_open()) {
    LOG(plog::fatal) << "Couldn't open file " << std::string(filePath);
    return;
  }

  for (int lineNumber = 0; lineNumber < core.numEntries; lineNumber++) {
    char entryStr[MAX_ENTRY_BYTES];
    core.entriesDB[lineNumber].toStr(entryStr);
    file << entryStr << std::endl;
  }

  file.close();
}