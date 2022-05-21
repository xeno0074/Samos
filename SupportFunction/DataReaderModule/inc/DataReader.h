//
// Created by iamar on 5/21/2022.
//
#include "CoreFunction.h"
#include "EntryModel.h"
#include "SystemDefines.h"
#include <string>

#ifndef SAMOSC_DATAREADER_H
#define SAMOSC_DATAREADER_H

class DataReader {
  private:
  char filePath[MAX_FILENAME_BYTES];

  void prepare(const char filePath[]);
  void process(Core &core);
  EntryModel makeEntry(const char entryString[MAX_ENTRY_BYTES]);

  public:
  DataReader() = delete;
  DataReader(const char filePath[], Core &core);
};

#endif//SAMOSC_DATAREADER_H
