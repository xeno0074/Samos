//
// Created by Arif Ahmed on 6/12/2021.
//

#ifndef VLADIS_SYSTEMDEFINES_H
#define VLADIS_SYSTEMDEFINES_H

#include <cstdint>

//  Typedefs
typedef uint8_t Uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;

//  DEFINES
static constexpr int BYTE_SZ = 8;
static constexpr int WORD_SZ = 2 * BYTE_SZ;

//  MAX DEFINES
static constexpr int MAX_BUFFER_BYTES = 64;
static constexpr int MAX_ENTRY_BYTES = 600;
static constexpr int MAX_ENTRY_DATA_BYTES = 150;
static constexpr int MAX_ENTRY_DATE_BYTES = 30;
static constexpr int MAX_ENTRY_TAG_BYTES = 100;
static constexpr int MAX_NUM_ENTRIES = 2000;
static constexpr int MAX_FILENAME_BYTES = 100;
static constexpr int MAX_COLUMNS = 6;
static constexpr int MAX_NUM_ELEMENTS = 6;
static constexpr int MAX_DATE_DATA_SIZE = 10;

#endif// VLADIS_SYSTEMDEFINES_H
