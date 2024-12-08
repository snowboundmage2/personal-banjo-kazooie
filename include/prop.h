#ifndef PROP_H
#define PROP_H

#include <stdint.h>
#include "structs.h"
#include <SDL2/SDL.h>


typedef struct sprite_prop_s {
    uint32_t unk0_31: 12;
    uint32_t unk0_19: 1;
    uint32_t unk0_18: 3;
    uint32_t unk0_15: 3;
    uint32_t unk0_12: 3;
    uint32_t unk0_9: 8;
    uint32_t unk0_1: 1;
    uint32_t unk0_0: 1;
    int16_t unk4[3];
    uint16_t unk8_15: 5;
    uint16_t unk8_10: 5;
    uint16_t unk8_5: 1;
    uint16_t unk8_4: 1;
    uint16_t unk8_3: 1;
    uint16_t unk8_2: 1;
    uint16_t unk8_1: 1;
    uint16_t unk8_0: 1;
} SpriteProp;

typedef struct model_prop_s {
    union {
        uint16_t unk0;
        struct {
            uint16_t unk0_31 : 12;
            uint16_t pad0_19 : 4;
        };
    };
    uint8_t unk0_15;
    uint8_t unk0_7;
    int16_t unk4[3];
    uint8_t unkA;
    uint8_t padB_7 : 2;
    uint8_t unkB_5 : 1;
    uint8_t unkB_4 : 1;
    uint8_t padB_3 : 4;
} ModelProp;


typedef struct actor_prop_s{
    union {
        struct {
            struct actorMarker_s* marker;
            int16_t x;
            int16_t y;
            int16_t z;
            uint16_t unk8_15:5;
            uint16_t unk8_10:5;
            uint16_t unk8_5:1;
            uint16_t unk8_4:1;
            uint16_t unk8_3:1;
            uint16_t unk8_2:1;
            uint16_t unk8_1:1;
            uint16_t unk8_0:1;
        };
        int32_t words[3];
    };
} ActorProp;

typedef void(*MarkerCollisionFunc)(struct actorMarker_s *this, struct actorMarker_s *other);
typedef struct actor_s *(*MarkerDrawFunc)(struct actorMarker_s *, Gfx **, Mtx **, SDL_Vertex **);
typedef void (*ActorUpdateFunc)(struct actor_s *);
typedef void (*ActorFreeFunc)(struct actor_s *);

typedef struct actorMarker_s{
    ActorProp* propPtr;
    struct cude_s* cubePtr;
    MarkerDrawFunc drawFunc;
    MarkerCollisionFunc collisionFunc; //ow_func
    MarkerCollisionFunc collision2Func;
    uint32_t         yaw:9;
    uint32_t         unk14_22:1;
    uint32_t         unk14_21:1;
    uint32_t         id:10; //  marker id of type marker enum_e
    uint32_t         unk14_10:11; //used in ch/jiggy
    Struct6Cs   *unk18;
    MarkerCollisionFunc dieFunc;
    int32_t         unk20;
    ActorUpdateFunc actorUpdateFunc;
    int32_t     unk28;
    uint32_t         actrArrayIdx:11; //unk2C
    uint32_t         pitch:9;
    uint32_t         roll:9;
    uint32_t         unk2C_2:1;
    uint32_t         unk2C_1:1;
    uint32_t         collidable:1;
    ActorFreeFunc actorFreeFunc;
    ActorUpdateFunc actorUpdate2Func;
    int16_t         unk38[3];
    uint16_t         pad3E_15:1;
    uint16_t         modelId:13;
    uint16_t         unk3E_1:1;
    uint16_t         unk3E_0:1; //scaled
    uint32_t         unk40_31:4;
    uint32_t         unk40_27:4;
    uint32_t         unk40_23:1;
    uint32_t         unk40_22:1;
    uint32_t         unk40_21:1;
    uint32_t         unk40_20:1;
    uint32_t         unk40_19:1;
    uint32_t         pad40_18:19;
    struct5Bs * unk44;
    BKModel *   unk48;
    vector(Struct70s) * unk4C;
    int32_t         unk50;
    void        (*unk54)(struct actorMarker_s *, struct actorMarker_s *, uint16_t*);
    int32_t         (*unk58)(struct actorMarker_s *, struct actorMarker_s *);
    int32_t         unk5C;
} ActorMarker;

typedef struct ch_bgs_6730_s{
    uint32_t  unk0;
    uint32_t  unk4;
    int32_t  unk8;
    int32_t  unkC;
} ActorLocal_BGS_6730;

typedef struct chtanktupbody_s{
    int32_t unk0[4];
    int32_t unk10;
    int32_t unk14;
    float unk18[3];
}ActorLocal_TanktupBody;


typedef struct actor_anim_info_s{
    uint32_t     index;
    float     duration;
} ActorAnimationInfo;

typedef struct jinjo_s{
    int32_t     unk0;
    int32_t     unk4;
    int32_t     unk8;
    int32_t     unkC;
}ActorLocal_Jinjo;

typedef struct ch_sm_4070{
    int32_t dialog_id;
}ActorLocal_SM_4070;

typedef struct actor_s{
    ActorMarker* marker;
    TUPLE(float,position);
    uint32_t state:6; /* unk10_31*/
    uint32_t unk10_25:7;
    uint32_t unk10_18:6;
    uint32_t unk10_12:4; // number of defeated enemies in SM attack tutorial
    uint32_t unk10_8:1;
    uint32_t unk10_7:1;
    uint32_t unk10_6:2;
    uint32_t unk10_4:1;
    uint32_t unk10_3:2;
    uint32_t unk10_1:1;
    uint32_t is_bundle:1;
    AnimCtrl *anctrl;
    ActorAnimationInfo *unk18;
    TUPLE(float, unk1C); // actor position? // used as "home" for chbat
    float actor_specific_1_f; //used in cheggs
    TUPLE(float, velocity);
    uint32_t  unk38_31:10; // hit count for jinjo base in fight
    uint32_t  unk38_21:9;
    uint32_t  unk38_13:9;
    uint32_t  stored_anctrl_playbackType_:3; //anctrlPlaybackType
    uint32_t  unk38_0:1;
    uint32_t unk3C;
    int32_t unk40;
    uint32_t unk44_31:8; // sfxsource idx
    uint32_t modelCacheIndex:10; //modelCacheIndex
    int32_t unk44_14:10;
    uint32_t despawn_flag:1;
    uint32_t unk44_2:1; // is set, when actors created inside Cube?
    uint32_t unk44_1:1; // only used by blubber?
    uint32_t unk44_0:1; // unused
    float unk48; //used in chlmonkey (chimpy)
    float unk4C;
    /* 0x50 */ float yaw; //0x50
    float unk54; //0x54
    uint32_t anctrl_asset_id: 15; // animation asset id (enum asset_id)
    uint32_t stored_anctrl_index: 14; //anctrlAnimIndex;
    uint32_t unk58_2: 1;
    uint32_t unk58_1: 1;
    uint32_t unk58_0: 1;
    float unk5C;
    float lifetime_value; // actor lifetime?
    float yaw_ideal; //0x64
    float pitch;//0x68
    float unk6C;
    float unk70;
    float unk74;
    uint32_t unk78_31:9;
    uint32_t unk78_22:9;
    uint32_t unk78_13:12; //default_spawn_yaw?
    uint32_t stored_anctrl_forwards:1; //animCtrlDirection
    uint32_t stored_anctrl_smoothTransistion:1; //animCtrlSmoothTransition
    union
    { //DON'T DO THIS JUST DEFINE STATICLY IN ch/ FILE AND CAST FROM &Actor->local
        ActorLocal_BGS_6730 bgs_6730;
        ActorLocal_TanktupBody tanktup;
        ActorLocal_Jinjo jinjo;
        ActorLocal_SM_4070 sm_4070;
        uint8_t  local[1];
        struct{ 
            uint8_t  unk7C[0x40];
            uint8_t  unkBC[0x30];
        };
        
    };
    //uint8_t  padAC[0x44];
    float stored_anctrl_timer; // animCtrlTimer
    float stored_anctrl_duration; //animCtrlDuration
    uint32_t unkF4_31:1;
    uint32_t unkF4_30:1; // has something to do with vertices
    uint32_t unkF4_29:1;
    uint32_t unkF4_28:1; //saved marker->propPtr->unk8_3
    uint32_t unkF4_27:1; //saved marker->propPtr->unk8_2
    uint32_t unkF4_26:1; //saved marker->unk2C_1
    uint32_t stored_marker_collidable:1; //saved marker->collidable
    uint32_t unkF4_24:2;
    uint32_t unkF4_22:1;
    uint32_t initialized:1; //unkF4_21;
    uint32_t unkF4_20:12;
    uint32_t unkF4_8:9; /* jinjo id in final fight.
                    *  Is used to determine file progress related stuff, can also be a file_progress_e
                    */
    float stored_anctrl_subrangeMin; //animCtrl_SubRangeStart
    float stored_anctrl_subrangeMax; //animCtrl_SubRangeEnd
    ActorMarker *unk100; // child actor marker ?
    ActorMarker *unk104;
    Struct62s *unk108;
    // void ( *unk108)(struct actorMarker_s *, int32_t); //saved from marker->collisionFunc
    int32_t unk10C; //saved marker->unk10
    float roll;//110
    float sound_timer;
    TUPLE(float, spawn_position); //0x118
    uint32_t unk124_31:12; // only used by GV Jinxy Head 2
    uint32_t alpha_124_19:8;
    uint32_t unk124_11:2; //blend_mode? 
    uint32_t depth_mode:2; //render_mode (passed to modelRender_setDepthMode())
    uint32_t unk124_7:1;
    uint32_t unk124_6:1;
    uint32_t unk124_5:2;
    uint32_t unk124_3:3;
    uint32_t unk124_0:1; //read in bsbbuster func 
    float scale;
    /* 0x12C */ struct actor_info_s *actor_info;
    void (* unk130)(struct actor_s *);
    vector(AnSeqElement) **unk134; //vector<AnSeqElement> //saved marker->dieFunc
    uint32_t unk138_31:1;
    uint32_t unk138_30:1;
    uint32_t unk138_29:1;
    uint32_t unk138_28:1;
    uint32_t unk138_27:2;
    uint32_t unk138_25:1;
    uint32_t has_met_before:1;
    uint32_t unk138_23:1;
    uint32_t unk138_22:1;
    uint32_t unk138_21:1;
    uint32_t unk138_20:1;
    uint32_t unk138_19:10; //saved maker->id
    uint32_t unk138_9:1;
    uint32_t unk138_8:1; // set to one by ACTOR_FLAG_UNKNOWN_18, which no actor seems to use
    uint32_t unk138_7:4;
    uint32_t unk138_3:4;
    ActorFreeFunc backupFreeFunc; // saved marker->actorFreeFunc
    float unk140;
    float unk144;
    SkeletalAnimation *unk148;
    void *unk14C[2];
    // void *unk150;
    uint32_t unk154;
    ParticleEmitter *unk158[2];
    void *unk160; //saved marker->unk54
    uint8_t  unk164[0x2];
    uint8_t  unk166;
    int8_t  pad167[0x1];
    int32_t unk168; //saved marker->unk58
    uint32_t  unk16C_31:27; //saved s1->marker->unk5C
    uint32_t  volatile_initialized:1; // the difference between this flag and initialized is that it is reset in actors_appendToSavestate
    uint32_t  unk16C_3:1;
    uint32_t  unk16C_2:1;
    uint32_t  unk16C_1:1;
    uint32_t  unk16C_0:1;
    float unk170;
    float unk174;
    float unk178;
    uint32_t unk17C_31:1;
    uint32_t pad17C_30:31;
} Actor;

typedef struct actor_info_s{
    int16_t     markerId;
    int16_t     actorId;
    int16_t     modelId;
    int16_t     startAnimation;
    ActorAnimationInfo*   animations;
    void    (* update_func)(Actor *);
    void    (* update2_func)(Actor *);
    Actor*  (* draw_func)(ActorMarker *, Gfx **, Mtx **, SDL_Vertex **);
    uint16_t     unk18;
    uint16_t     draw_distance;
    float     shadow_scale;
    uint16_t     unk20;
    //uint8_t     pad22[2];
} ActorInfo;

typedef struct actor_spawn_s{
    ActorInfo   *infoPtr;
    Actor *(*spawnFunc)(int32_t[3], int32_t, ActorInfo*, uint32_t);
    int32_t         unk8;
} ActorSpawn;

typedef union prop_s
{
    ActorProp   actorProp;
    SpriteProp  spriteProp;
    ModelProp    modelProp;
    struct{
        uint32_t pad0;
        int16_t unk4[3];
        // int16_t unk6;
        int16_t pad8_15: 10;
        uint16_t unk8_5: 1;
        uint16_t unk8_4: 1;
        uint16_t unk8_3: 1;
        uint16_t unk8_2: 1;
        uint16_t unk8_1: 1;
        uint16_t markerFlag: 1;
    };
} Prop;

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
    uint16_t radius: 9; // selector / volume / diameter?
    uint16_t bit6: 6; // category?
    uint16_t bit0: 1;
    uint16_t unk8;       //actor_id?
    uint8_t unkA;        //marker_id
    uint8_t padB;
    uint32_t yaw: 9; // unkC_31
    uint32_t scale: 23; // unkC_22
    uint32_t unk10_31: 12; // unk10_31 and unk10_19 seem to be related
    uint32_t unk10_19: 12; // unk10_31 and unk10_19 seem to be related
    uint32_t pad10_7: 1;
    uint32_t unk10_6: 1; // isInitialized flag?
    uint32_t pad10_5: 4;
    uint32_t unk10_0: 2; // is only for used in func_803303B8
} NodeProp; // size = 20 (0x14) bytes

typedef struct {
    uint8_t pad0[0x4];
    uint32_t pad4_31:14;
    uint32_t unk4_17:2;  // only ever gets 0 written to it
    uint32_t pad4_15:8;
    uint32_t pad4_7:7;
    uint32_t unk4_0:1; // if this and unkC_0 is false then unk10_4 and unk4_17 are set to 0 
    uint8_t pad8[0x4];
    uint32_t padC_31:31;
    uint32_t unkC_0:1; // if this and unk4_0 is false then unk10_4 and unk4_17 are set to 0 
    uint32_t pad10_31:27;
    uint32_t unk10_4:4; // only ever gets 0 written to it
    uint32_t pad10_0:1; 
} OtherNode; //can be inplace of NodeProp (see code7AF80_initCubeFromFile) size: 12 (0xC) bytes

typedef struct cude_s{
    int32_t x:5;
    int32_t y:5;
    int32_t z:5;
    uint32_t prop1Cnt:6;
    uint32_t prop2Cnt:6;
    uint32_t unk0_4:5; //node_prop_count
    NodeProp *prop1Ptr;
    Prop *prop2Ptr;
}Cube;

typedef struct actor_array{
    int32_t cnt;
    int32_t max_cnt;
    Actor data[]; //variable size array
}ActorArray;

typedef struct {
    uint32_t cnt;
    Actor *actor_save_state[];
}ActorListSaveState;

#endif
