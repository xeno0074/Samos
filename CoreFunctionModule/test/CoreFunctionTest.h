//
// Created by Arif Ahmed on 11/05/22.
//

#ifndef SAMOSC_COREFUNCTIONTEST_H
#define SAMOSC_COREFUNCTIONTEST_H

#include "CoreFunction.h"

class CoreTest {
  Core *mCore;

  public:
  CoreTest() {
    mCore = new Core();
  }
  ~CoreTest() {
    delete mCore;
    mCore = nullptr;
  }
};

#endif//SAMOSC_COREFUNCTIONTEST_H
