//
// Created by Arif Ahmed on 10/05/22.
//
#include "SystemDefines.h"

#ifndef SAMOSC_UTILITIES_H
#define SAMOSC_UTILITIES_H

#ifdef _WIN32
#define RUN_PY(args) system("py " args)
#else
#define RUN_PY(args) system("python3 " args);
#endif

#define PREPARE_TEST(args)                                                                                             \
  RUN_PY("prepare_test.py");                                                                                           \
  RUN_PY("conf_gen.py " args);                                                                                         \
  RUN_PY("entries_gen.py");

#endif//SAMOSC_UTILITIES_H
