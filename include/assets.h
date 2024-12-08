#ifndef ASSETS_H
#define ASSETS_H

#include <stdint.h>
#include "structs.h"

typedef struct {
    uint32_t count;
    uint32_t unk4;
} AssetROMHead;

typedef struct {
    uint32_t offset;
    int16_t compFlag;
    int16_t unk6;
} AssetFileMeta;

extern uint8_t assets_ROM_START[]; // ROM file asset bin

#endif
