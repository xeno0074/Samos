//
// Created by Arif Ahmed on 11/05/22.
//

#ifndef SAMOSC_COREFUNCTIONTEST_H
#define SAMOSC_COREFUNCTIONTEST_H

#include "CoreFunction.h"

class CoreTest {// CoreTest class as Meyer's Singleton
  Core *pCore;

  CoreTest() {
    pCore = nullptr;
  }

  public:
  static CoreTest &getInstance() {
    static CoreTest ct;
    return ct;
  }
  ~CoreTest() = default;
  CoreTest(const CoreTest &) = delete;
  void operator=(const CoreTest &) = delete;

  Core *getCore() {
    return pCore;
  }

  void replaceCore(Core *core) {
    pCore = core;
  }
};

#endif//SAMOSC_COREFUNCTIONTEST_H
