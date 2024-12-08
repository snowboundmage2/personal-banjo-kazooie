#ifndef MODEL_H
#define MODEL_H

#include <stdint.h>
#include <SDL2/SDL.h>

typedef struct {
    SDL_Vertex v;
    int16_t unk10; // vtx_indx
    uint8_t pad12[2];
    uint8_t pad14[4];
} BKVtxRef;

/* BKMesh
 * This struct is a set of Vtx that will be modified at runtime.
 * This struct is followed by an array of int16_t containing the
 * Vtx index inside the model's BKVertexList.
*/
typedef struct {
    int16_t uid_0;
    int16_t vtxCount_2;
} BKMesh;

typedef struct {
    int32_t cmd_0;
    int32_t size_4;
} BKGeoList;

/* BKMeshList 
 * This struct is followed by an array of BKMesh which contain
 * lists of Vtx that are modified at runtime.
 */
typedef struct {
    int16_t meshCount_0;
} BKMeshList;

typedef struct {
    int16_t minCoord[3];
    int16_t maxCoord[3];
    int16_t centerCoord[3];
    int16_t local_norm;       //(distance to furthest vtx relative to model center)
    int16_t count;
    int16_t global_norm; //(distance to furthest vtx relative to model origin)
    SDL_Vertex vtx_18[];
} BKVertexList;

typedef struct {
    int16_t start_tri_index; // start_tri
    int16_t tri_count; // tri_cnt
} BKCollisionGeo; // BKCollisionGeometry

typedef struct {
    int16_t unk0[3]; // vtx_indx
    int16_t unk6;
    int32_t flags; // flags
} BKCollisionTri; // BKCollisionTri

typedef struct {
    int16_t unk0[3]; // min
    int16_t unk6[3]; // max
    int16_t unkC; // y_stride
    int16_t unkE; // z_stride
    int16_t unk10; // geo_cnt
    int16_t unk12; // scale
    int16_t unk14; // tri_cnt
    uint8_t pad16[2];
    // BKCollisionGeo[]
    // BKCollisionTri[]
} BKCollisionList;

typedef struct {
    uint8_t pad0[0];
} BKEffectsList; // see BKMeshList

typedef struct {
    float unk0[3];
    int16_t bone_id;
    int16_t mtx_id;
} BKAnimation;

typedef struct {
    float unk0;
    int16_t cnt_4;
    BKAnimation anim[];
} BKAnimationList;

typedef struct {
    uint8_t pad0[8];
    Gfx list[]; 
} BKGfxList;

typedef struct {
    int32_t offset_0;
    int16_t type_4;
    uint8_t pad6[2];
    uint8_t width_8;
    uint8_t height_9;
    uint8_t padA[6];
} BKTextureHeader;

typedef struct {
    int32_t size_0;
    int16_t cnt_4;
    uint8_t pad6[2];
    BKTextureHeader tex_8[];
} BKTextureList;

typedef struct {
    int16_t unk0[3];
    int16_t unk6[3];
    int16_t unkC[3];
    uint8_t unk12[3];
    uint8_t unk15;
    int8_t unk16;
    uint8_t pad17[1];
} BKModelUnk14_0;

typedef struct {
    int16_t unk0;
    int16_t unk2;
    int16_t unk4[3];
    uint8_t unkA[3];
    uint8_t unkD;
    int8_t unkE;
    uint8_t padF[1];
} BKModelUnk14_1;

typedef struct {
    int16_t unk0;
    int16_t unk2[3];
    uint8_t unk8;
    int8_t unk9;
    uint8_t padA[2];
} BKModelUnk14_2;

typedef struct {
    int16_t cnt0; // number of BKModelUnk14_0 structs
    int16_t cnt2; // number of BKModelUnk14_1 structs
    int16_t unk4; // number of BKModelUnk14_2 structs
    int16_t unk6;
    // BKModelUnk14_0[]
    // BKModelUnk14_1[]
    // BKModelUnk14_2[]
} BKModelUnk14List;

typedef struct {
    int16_t unk0[3];
    int16_t unk6[3];
    uint8_t unkC;
    uint8_t padD[1];
} BKModelUnk20_0;

typedef struct {
    uint8_t unk0;
    uint8_t pad1[1];
    // BKModelUnk20_0[]
} BKModelUnk20List;

typedef struct {
    int16_t coord[3];
    int8_t anim_index;
    uint8_t vtx_count;
    int16_t vtx_list[1];
} BKModelUnk28;

typedef struct {
    int16_t count;
    uint8_t pad2[2];
    // BKModelUnk28_0[]
} BKModelUnk28List;

typedef struct {
    int16_t frame_size;
    int16_t frame_cnt;
    float frame_rate;
} AnimTexture;

typedef struct {
    BKMeshList *meshList_0;
    BKVertexList *vtxList_4;
} BKModel;

typedef struct {
    uint8_t pad0[4];
    int32_t geo_list_offset_4;
    int16_t texture_list_offset_8;
    int16_t geo_typ_A;
    int32_t gfx_list_offset_C;
    int32_t vtx_list_offset_10;
    int32_t unk14;
    int32_t animation_list_offset_18;
    int32_t collision_list_offset_1C;
    int32_t unk20;
    int32_t effects_list_setup_24;
    int32_t unk28;
    int32_t animated_texture_list_offset; // AnimTexture[4]
} BKModelBin;

BKVertexList *model_getVtxList(BKModelBin *arg0);
SDL_Vertex *vtxList_getVertices(BKVertexList *vtxList);
void codeAC520_func_80333D48(BKVertexList *arg0, float position[3], float rotation[3], float scale, float arg4[3], BKVertexList *arg5);

#endif // MODEL_H
