#ifndef STRUCTS_H
#define STRUCTS_H

#include "model.h"
#include "enums.h"
#include "bool.h"
//include what is needed for vector
#include <stdint.h>
#include <SDL2/SDL.h>

#define MERGE(a, b) a ## b

#define UNK_TYPE(t) t

typedef struct{
    float x;
    float y;
    float z;
} vec3f;

#define TUPLE(t, n) union{\
    struct{ t n##_x; t n##_y; t n##_z; };\
    struct{ t n##_pitch; t n##_yaw; t n##_roll; };\
    t n[3];\
}

#define PAIR(t, n) union{\
    struct{ t n##_first; t n##_second;};\
    struct{ t n##_min; t n##_max;};\
    struct{ t n##_x; t n##_y;};\
    t n[2];\
}

#define TUPLE_PAIR(t, n) union{\
    struct{ TUPLE(t, n##_min);  TUPLE(t, n##_max);};\
    t n[2][3];\
}

#define KEY_VALUE_PAIR(T1, T2) struct { T1 key; T2 value; }

typedef struct freelist_s{
    int16_t elem_size;
    int16_t elem_cnt;
    uint8_t unk4[];
}FLA;

#define FREE_LIST(T) struct freelist_s
//^defined to keep element type with sla

typedef struct {
    float m[4][4];
} MtxF;

typedef struct bk_sprite_s{
    int16_t frameCnt;
    int16_t type;
    int16_t unk4;
    int16_t unk6;
    int16_t unk8;
    int16_t unkA;
    struct{
        uint32_t bit31 : 4;
        uint32_t bit27 : 3;
        uint32_t bit24 : 2;
        uint32_t bit22 : 2;
        uint32_t pad_bit20 : 21;
    }unkC;
    int32_t offsets[];
} BKSprite;

typedef struct{
    Gfx *gfx; //gfx_offset
    Vtx *vtx; //vtx_offset
}BKSpriteFrameDisplayData;

typedef struct{
    BKSprite *sprite;
    BKSpriteFrameDisplayData frame[];
}BKSpriteDisplayData;

typedef struct bk_sprite_frame_s{
    int16_t unk0;
    int16_t unk2;
    int16_t w;
    int16_t h;
    int16_t chunkCnt;
    int16_t unkA;
    int16_t unkC;
    int16_t unkE;
    int16_t unk10;
    int16_t unk12;
} BKSpriteFrame;

typedef struct bk_sprite_texture_block_s{
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
} BKSpriteTextureBlock;

typedef struct model_cache_s{
    BKModelBin * modelPtr;
    BKSprite   * unk4; 
    BKSpriteDisplayData *unk8;
    uint32_t     animated_texture_cache_id;
    uint32_t     unk10;
} ModelCache;

typedef struct portrait_voice_s{
    uint16_t sfxIndex;
    uint8_t  pad2[2];
    float duration;
} PortraitVoice;

typedef struct portrait_info_s{
    uint16_t assetIndx;
    uint8_t  pad2[2];
    PortraitVoice voiceInfo[5];
} PortraitInfo;

typedef struct struct_0_s{ //floor
    void *  model;
    BKCollisionTri unk4;
    BKCollisionTri unk10;
    float     unk1C[3];
    float     unk28[3];
    float     normX;
    float     normY;
    float     normZ;
    float     posX; //40
    float     posY; //44
    float     posZ; //48
    union{
        struct{
            uint32_t unk4C_0:32;
        };
        uint32_t     unk4C;
    };
    int16_t     unk50;
    int16_t     unk52;
    uint32_t     unk54;
    uint8_t      unk58;
    uint8_t      unk59;
    uint8_t      unk5A;
    uint8_t      unk5B;
    uint8_t      unk5C;
    uint8_t      unk5D;
    uint8_t      unk5E;
    uint8_t      unk5F;
} struct0; //geo(used for floor)

typedef struct struct_2_s{
    float duration;
    uint8_t argCount;
    uint8_t activationFrameDelay;
    int32_t arg0;
    int32_t arg1;
    int32_t arg2;
    void *funcPtr;
} AnSeqElement;

typedef struct struct_3_s{
    uint32_t unk0;
    float unk4[3];
    float unk10[3];
    uint8_t unk1C;
    uint8_t pad1D[0x3];
    vector(struct struct_4_s) *unk20;
    int32_t unk24;
    int32_t unk28;
    void *unk2C;
    float unk30;
    uint8_t unk34;
    uint8_t pad35[0x3];
    float unk38;
    float unk3C;
    float unk40[0x4];
} struct3s;

typedef struct struct_4_s{
    float unk0[3];
    float unkC[3];
    uint8_t unk18;
    uint8_t pad19[3];
} struct4s;

typedef struct struct_5_s{
    BKModelBin *unk0;
    float unk4[3];
    float unk10[3];
    float unk1C[3];
    float unk28[3];
    uint8_t unk34;
    uint8_t pad35[0x3];
}struct5s;

typedef struct struct_6_s{
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    uint32_t unk18;
    vector(struct5s) *unk1C;
    int16_t unk20;
    uint8_t unk22;
    uint8_t pad23[1];
    void *unk24[4];
    uint8_t    unk34;
    uint8_t pad35[0x3];
    float unk38;
}struct6s;

typedef struct struct_7_s{
    int32_t unk0;
    int32_t unk4;
    float unk8;
    float unkC;
    float unk10;
    int32_t unk14;
    int32_t unk18;
    float unk1C;
}struct7s;

typedef struct struct_8_s{
    int32_t unk0;
    int32_t unk4;
    float unk8;
    float unkC;
    float unk10;
    int32_t unk14;
    int32_t unk18;
    float unk1C; //first 0x20 should be struct7s
    uint32_t unk20; //item_id
    int32_t unk24; //asset_id
    uint32_t unk28;
    int32_t unk2C;
    float unk30;
    float unk34;
    float unk38; //added to x string print position (position?)
    float unk3C; //added to y string print position (position?)
    float unk40; //scale???
    float unk44; //added to x string print position (sprite w)
    float unk48; //added to y string print position (sprite h)
    float unk4C; 
    uint32_t unk50; //asset_ptr (indx in unk24)
    int8_t string_54[0xC]; //value string
    float unk60;
}struct8s;

typedef struct struct_11_s{
    float unk0;
    float unk4;
    int32_t unk8;
    int32_t unkC;
    int16_t track_id; //trackId
    int16_t unk12;
    uint8_t unk14;
    uint8_t unk15;
    uint8_t pad16[0x2];
    FREE_LIST(struct12s) *unk18;
    int32_t unk1C[0xE];
} CoMusic;

typedef struct struct_12_s{
    int32_t unk0;
    int32_t unk1;
} struct12s;

typedef struct struct_13_s{
    int32_t cmd;
    uint8_t* str;
}struct13s;

typedef struct struct_14_s{
    int16_t unk0;
    int16_t unk2;
    TUPLE(float, unk4);
    struct actorMarker_s *unk10;
    int32_t unk14;
    void (*unk18)(struct actorMarker_s *, int32_t, int32_t);
    void (*unk1C)(struct actorMarker_s *, int32_t, int32_t);
    int32_t unk20;
}struct14s;

typedef struct struct_15_s{
    uint8_t unk0_7:2;
    uint8_t unk0_5:2;
    uint8_t pad0_3:4;
}struct15s;

typedef struct struct_16_s{
    int32_t unk0;
    int32_t unk4;
    int32_t unk8;
    int32_t unkC;
}struct16s;

typedef struct struct_1B_s{
    int16_t map;
    int16_t exit;
}struct1Bs;

typedef struct struct_1C_1_s{
    int16_t level_id;
    int16_t x;   //0x2
    uint8_t *string; //0x4
}struct1Cs_1;

typedef struct struct_21_s{
    int32_t unk0;
    void * unk1;
}struct21s;



//particle_ctrl
typedef struct particle_emitter{
    uint32_t pad0_31:8;
    uint32_t doneSpawning_0_23:7; //doneSpawning
    uint32_t unk0_16:1;
    uint32_t assetId_0_15:14; //uid
    uint32_t dead:1;
    uint32_t auto_free:1;
    float unk4[3];
    float fade_in; //fade_in_end
    float fade_out; //fade_out_start
    uint32_t draw_mode;
    BKSprite *sprite_1C; //sprite_ptr
    BKModelBin *model_20; //model_ptr
    float particleSpawnTimer_24; //particleSpawnTimer?
    float postion_28[3]; //position
    BKSpriteDisplayData *unk34;
    float spawnIntervalTimer_38; //spawnIntervalTimer
    int32_t rgb[3];
    uint8_t  sphericalParticleVelocity_48; //sphericalParticalVelocity
    uint8_t  alpha;
    uint8_t  pad4A[0x2];
    TUPLE_PAIR(float, particleAccerationRange_4C);
    int16_t unk64;
    int16_t sfx_id;
    float unk68;
    float unk6C;
    float unk70;
    float unk74;
    float unk78;
    int32_t unk7C;
    void  (*particleCallback_80)(struct particle_emitter *, float [3]); //particleCallback
    PAIR(int32_t, particleStartingFrameRange_84);
    PAIR(float, particleFramerateRange_8C);
    TUPLE_PAIR(float, particleSpawnPositionRange_94);
    PAIR(float, particleStartingScaleRange_AC);
    PAIR(float, particleFinalScaleRange_B4);
    float unkBC[3];
    float unkC8[3];
    PAIR(float, spawnIntervalRange_D4);
    float particleLifeTimeRange[2];
    union
    {
        TUPLE_PAIR(float, cartisian);
        struct{
            PAIR(float, yaw);
            PAIR(float, pitch);
            PAIR(float, radius);
        }spherical;
    } particleVelocityRange_E4;
    float unkFC;
    int32_t unk100;
    int16_t unk104;
    uint8_t pad106[0x2];
    float unk108;
    float unk10C[3];
    float unk118[3];
    struct particle *pList_start_124; //start_ptr?
    struct particle *pList_end_128; //end_ptr
    struct particle *pList_capacity_12C; //capacity_end_ptr;
} ParticleEmitter;

typedef struct particle_scale_and_lifetime_ranges_s{
    float unk0[2]; //particle_starting_scale_range
    float unk8[2]; //particle_starting_scale_range
    float unk10[2]; //particle_spawn_interval_range
    float unk18[2]; //particle_lifetime_range
    float unk20; //particle_fade_in
    float unk24; //particle_fade_in
} ParticleScaleAndLifetimeRanges;

typedef struct struct_32_s{
    float min[3];
    float max[3];
} ParticleSettingsVelocity;

typedef struct struct_33_s{
    float min[3];
    float max[3];
} ParticleSettingsAcceleration;

typedef struct struct_34_s{
    float min[3];
    float max[3];
} ParticleSettingsSpawnPosition;

typedef struct struct_40_s{
    ParticleScaleAndLifetimeRanges scale_and_lifetime;
    float drawmode;
    float count;
} ParticleSettingsScaleAndLifetimeDrawModeEmitCount;

typedef struct struct_41_s{
    ParticleSettingsVelocity velocity;
    ParticleSettingsAcceleration acceleration;
} ParticleSettingsVelocityAcceleration;

typedef struct struct_42_s{
    ParticleSettingsVelocity velocity;
    ParticleSettingsSpawnPosition spawn_position;
} ParticleSettingsVelocityPosition;

typedef struct struct_43_s{
    ParticleSettingsVelocity velocity;
    ParticleSettingsAcceleration acceleration;
    ParticleSettingsSpawnPosition spawn_position;
} ParticleSettingsVelocityAccelerationPosition;

typedef struct {
    uint32_t unk0_31:11;
    uint32_t unk0_20:10;
    uint32_t unk0_10:11;
}struct44s;

typedef struct {
    struct struct_81_s *unk0;
    int32_t unk4;
}struct46s;


typedef struct{
    float unk0[3];
    float unkC[3];
    uint8_t unk18;
    uint8_t pad19[3];
    struct struct_4D_s *unk1C;
}struct4Cs;

typedef struct struct_4D_s{
    float unk0[3];
    float unkC[3];
}struct4Ds;

typedef struct{
    uint8_t unk0; // sfxsource index
    uint8_t pad1[0x3];
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    int16_t unk38;
    int16_t unk3A;
    uint8_t unk3C;
    uint8_t unk3D;
    uint8_t unk3E;
    uint8_t unk3F;
}struct4Es;

typedef struct{
    uint8_t unk0;
    uint8_t unk1;
    float unk4[3];
}struct50s;

typedef struct{
    int16_t unk0;
    uint8_t pad2[4];
    int16_t unk6;
    uint8_t pad8[4];
}struct51s;

typedef struct{
    int32_t unk0;
    uint8_t pad4[8];
}struct52s;



typedef struct{
    int32_t unk0;
    int32_t unk4;
    float unk8[0][3];
} struct56s;



typedef struct {
    float (*unk0)[3];
    float (*unk4)[3];
}struct5Bs;

typedef struct{
    uint16_t unk0_15 : 4;
    uint16_t unk0_11 : 2;
    uint16_t unk0_9  : 3;
    uint16_t unk0_6  : 2;
    uint16_t unk0_4  : 3;
    uint16_t unk0_1  : 2;
}struct5Cs;

typedef struct struct_5d_s{
    int32_t unk0;
    float unk4[3];
    float unk10;
    void (*unk14)(struct struct_5d_s *, int32_t);
    void (*unk18)(struct struct_5d_s *, int32_t);
    uint8_t unk1C;
    uint8_t unk1D;
    uint8_t unk1E;
    uint8_t unk1F;
}Struct5Ds;

typedef struct struct_5e_s{
    uint8_t pad0[0x8];
    union{
        uint32_t unk8;
        struct{
            uint32_t pad8_31 : 4;
            int32_t unk8_27 : 1;
            uint32_t pad8_26 : 27;
        };
    };
}Struct5Es;

typedef struct {
    float unk0;
    float unk4;
    uint8_t  unk8;
    uint8_t  unk9;
    uint8_t  unkA;
    //uint8_t padB;
    float unkC;
    float unk10;
    float unk14;
} Struct5Fs;

//Struct60s moved to top


typedef struct {
    int16_t unk0;
    // uint8_t pad2[2];
    struct struct_63_s *unk4;
}Struct62s;

typedef struct struct_63_s{
    int16_t unk0;
    // uint8_t pad2[2];
    void (*unk4)(vector(AnSeqElement) **, struct actorMarker_s *);
} Struct63s;

typedef struct struct_64_s{
    struct struct_65_s *unk0;
    int32_t unk4;
} Struct64s;

typedef struct struct_65_s{
    float unk0[3];
    struct actorMarker_s *unkC;
    int32_t (*unk10)(float[3], float, struct actorMarker_s *);
    int16_t unk14[3];
    int16_t unk1A[3];
    uint8_t unk20;
    uint8_t unk21;
    uint8_t unk22;
    uint8_t unk23;
    int8_t unk24;
    uint8_t unk25;
    uint8_t unk26;
    uint8_t unk27;
}Struct65s;


typedef void  (*Struct68DrawMethod)(void *, struct struct_68_s *, float[3], float[3], float, BKModelBin*, Gfx**, Mtx**, Vtx**);

typedef struct struct_68_s{
    uint8_t unk0; // sfxsource index
    // uint8_t pad1[0x3];
    struct actorMarker_s *unk4;
    Struct68DrawMethod unk8;
    BKModelBin *unkC;
    uint8_t pad10[0x4];
    float position[3];
    float unk20[3]; //rotation
    float unk2C;    //scale
    uint8_t unk30;
    uint8_t unk31;
    uint8_t pad32[2];
    uint8_t local[0x80];
} Struct68s;

typedef struct {
    float unk0;
    float unk4[3];
    float unk10[3];
    float unk1C[3];
    float unk28[3];
    float unk34;
} Struct6Bs;

typedef struct{
    BKCollisionTri * (* unk0)(struct actorMarker_s *, float[3], float[3], float[3], int32_t);
    BKCollisionTri *(* unk4)(struct actorMarker_s *, float[3], float[3], float, float[3], int32_t, uint32_t);
    BKCollisionTri *(* unk8)(struct actorMarker_s *, float[3], float, float[3], int32_t);
    int32_t (* unkC)(struct actorMarker_s *, float[3], float, float[3], int32_t);
} Struct6Cs;

typedef struct struct_6D_s{
    uint8_t unk0; //sfxsource index
    // uint8_t pad1[3];
    float unk4;
    float unk8;
    void (*unkC)(struct struct_6D_s *);
    void (*unk10)(struct struct_6D_s *);
    int16_t unk14[3];//min_vtx
    int16_t unk1A[3];//max_vtx
    float unk20;
    float unk24;
    uint8_t unk28;
    uint8_t unk29;
    uint8_t pad2A[2];
    float unk2C[3];
    float unk38[3];
    float unk44;
    float unk48;
    int16_t unk4C;
    int16_t unk4E;
    float unk50[4];
    float unk60[4];
    float unk70;
    float unk74;
    float unk78[3];
    float unk84;
    float unk88[3];
    float unk94;
    float unk98;
    float unk9C;
}Struct6Ds;



typedef struct {
    float unk0;
    float unk4;
}Struct6Fs;

typedef struct {
    int32_t unk0;
    float unk4;
    float unk8;
    float unkC;
}Struct71s;

typedef struct {
    float unk0;
}Struct72s;

typedef struct {
    int16_t d_tc[2];
    float unk4;
    float unk8;
    int16_t unkC;
    int16_t unkE;
    int16_t dy;
    //uint8_t pad12[2];
    float unk14;
    float unk18;
    float unk1C;
}Struct73s;

typedef struct {
    uint8_t pad0[0x4];
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    uint8_t unk18[0x8];
    float unk20;
    float unk24;
    float unk28[2];
}Struct74s;

typedef struct {
    float unk0;
}Struct75s;

typedef struct {
    int16_t alpha;
    int16_t unk2;
    int32_t unk4;
    int32_t unk8;
    int32_t unkC;
    float unk10;
    float unk14;
}Struct76s;

typedef struct {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    uint8_t unk18[0x8];
    float unk20;
    float unk24;
    int16_t unk28[2];
    float unk2C;
}Struct77s;

typedef union {
    Struct6Ds type_6D;
    Struct6Fs type_6F;
    Struct71s type_71;
    Struct72s type_72;
    Struct73s type_73;
    Struct74s type_74;
    Struct77s type_77;
}Struct70s;


typedef struct {
    uint8_t unk0;
    // uint8_t pad1[0x3];
    BKModel *unk4;
    int16_t unk8;
    uint8_t padA[2];
    Struct70s unkC;
}Struct6Es;






typedef struct {
    int actor_id;
    struct actorMarker_s *marker;
    float position[3];
    void (*unk14)(struct actor_s *, struct actorMarker_s *);
    struct actorMarker_s *unk18;
}Struct81s;

typedef struct {
    int actor_id;
    struct actorMarker_s *marker;
    float position[3];
    void (*unk14)(struct actor_s *, struct actorMarker_s *);
    struct actorMarker_s *unk18;
}Struct82s;

typedef struct {
    float unk0;
    float unk4;
    float unk8[3];
    int16_t unk14[3];
    uint8_t unk1A;
    uint8_t pad1B[1];
}Struct83s;

typedef struct{
    int16_t texture_type;
    int16_t count;
    int32_t offset[];
}Struct84s;

typedef struct{
    uint8_t pad0[1];
}struct85s;

typedef struct{
    float unk0[3];
    float unkC;
    uint32_t flags;
    int16_t unk14;
    // uint8_t pad16[2];
    void *unk18;
}struct86s;

typedef struct {
    int32_t unk0; //sound state cnt
    int32_t unk4;
    int32_t unk8; //maxSounds
    ALHeap *unkC; //heap
    uint16_t unk10;
}Struct87s;
#endif
