//
// Created by Arif Ahmed on 5/21/2022.
//
#include "CoreFunction.h"
#include "EntryModel.h"
#include "SystemDefines.h"

#ifndef SAMOSC_DATAREADER_H
#define SAMOSC_DATAREADER_H

class DataReader {
  private:
  void fillCore(const char filePath[], Core &core);

  public:
  DataReader() = delete;
  DataReader(const char filePath[], Core &core);
};

#endif//SAMOSC_DATAREADER_H
