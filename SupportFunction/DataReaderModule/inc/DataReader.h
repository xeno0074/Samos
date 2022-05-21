//
// Created by iamar on 5/21/2022.
//
#include "EntryModel.h"
#include "SystemDefines.h"

#ifndef SAMOSC_DATAREADER_H
#define SAMOSC_DATAREADER_H

class DataReader {
  private:
  Uint8 filePath[MAX_FILENAME_BYTES];

  EntryModel makeEntry(Uint8 entryString[MAX_ENTRY_BYTES]);

  public:
  DataReader() = default;
  DataReader(const Uint8 *filePath) {
    //    this->filePath = filePath;
  }
  void sampleFunc();
};

#endif//SAMOSC_DATAREADER_H
