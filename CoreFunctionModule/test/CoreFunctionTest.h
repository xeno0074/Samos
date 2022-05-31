//
// Created by Arif Ahmed on 11/05/22.
//

#ifndef SAMOSC_COREFUNCTIONTEST_H
#define SAMOSC_COREFUNCTIONTEST_H

#include "CoreFunction.h"

class CoreTest {// CoreTest class as Meyer's Singleton
  Core core;

  CoreTest() : core() {}

  public:
  static CoreTest &getInstance() {
    static CoreTest ct;
    return ct;
  }
  ~CoreTest() = default;
  CoreTest(const CoreTest &) = delete;
  void operator=(const CoreTest &) = delete;

  Core &getCore() {
    return core;
  }
};

#endif//SAMOSC_COREFUNCTIONTEST_H
