//
// Created by iamar on 6/12/2021.
//

#ifndef VLADIS_SYSTEMDEFINES_H
#define VLADIS_SYSTEMDEFINES_H

#include <cstdint>

//  Typedefs
typedef uint8_t Uint8;
typedef uint32_t Uint32;

//  DEFINES
static constexpr Uint8 BYTE_SZ = 8;
static constexpr Uint8 WORD_SZ = 2 * BYTE_SZ;

//  MAX DEFINES
static constexpr Uint8 MAX_BUFFER_BYTES = 64;

#endif // VLADIS_SYSTEMDEFINES_H
