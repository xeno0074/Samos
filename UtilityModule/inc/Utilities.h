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

#endif//SAMOSC_UTILITIES_H
