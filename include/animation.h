#ifndef ANIMATION_H
#define ANIMATION_H

#include <stdint.h>
#include <SDL2/SDL.h>
#include "prop.h"

size_t anim_getSize(void);
enum asset_e anim_getIndex(Animation *this);
float anim_getTimer(Animation *this);
float anim_getDuration(Animation *this);
void anim_new(Animation *this, bool arg1);
void anim_setTimer(Animation *this, float arg1);
void anim_80289790(Animation* this, void (*arg1)(int, int));
void anim_80289798(Animation *this, int arg1);
void anim_setDuration(Animation *this, float arg1);

// Represents the transformation on a given model bone
typedef union {
    struct {
        uint16_t unk0_15 : 1;
        uint16_t unk0_14 : 1;
        uint16_t unk0_13 : 14;
        int16_t unk2;
    };
} AnimationFileData;

typedef struct animation_file_elem_s {
    uint16_t unk0_15 : 12;
    uint16_t unk0_3 : 4;
    int16_t data_cnt;
    AnimationFileData data[];
} AnimationFileElement;

typedef struct animation_file_s {
    int16_t unk0;
    int16_t unk2;
    int16_t elem_cnt;
    uint8_t pad6[2];
} AnimationFile;

#endif
