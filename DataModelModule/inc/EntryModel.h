#pragma once
#include"SystemDefines.h"

const Uint8 MAX_ENTRY_DATA_BYTES = 200;

class EntryModel
{
private:
    Uint8 data[MAX_ENTRY_DATA_BYTES];
    Uint8 id;
    Uint32 amount;
    Uint8 txType;
    Uint8 tag[MAX_ENTRY_DATA_BYTES];
public:
    EntryModel();
    ~EntryModel();
};
