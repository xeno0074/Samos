//
// Created by Arif Ahmed on 31/05/22.
//
#include "CoreFunction.h"
#include "EntryModel.h"
#include "SystemDefines.h"

#ifndef SAMOSC_DATAWRITER_H
#define SAMOSC_DATAWRITER_H

class DataWriter {
  private:
  void dumpCore(const char filePath[], Core &core);

  public:
  DataWriter() = delete;
  DataWriter(const char filePath[], Core &core);
};

#endif//SAMOSC_DATAWRITER_H
