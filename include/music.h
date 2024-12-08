#ifndef MUSIC_H
#define MUSIC_H

#include <stdint.h>
#include "structs.h"

typedef struct struct_B_s{
    int32_t unk0;
    int32_t chan;
    float unk8;
    float unkC;
    float unk10;
} structBs;

typedef struct music_track_s{
    int16_t unk0;
    uint8_t  unk2;
    uint8_t  unk3;
    ALCSeq cseq;
    ALCSPlayer cseqp;
    int16_t index;
    int16_t index_cpy;
    float unk17C;
    float unk180;
    uint8_t unk184[0xE];
    uint8_t unk192[0xE];
} MusicTrack;

typedef struct music_track_meta_s{
    char *name;
    uint16_t  unk4;
    // uint8_t pad6[2];
}MusicTrackMeta;

#endif
