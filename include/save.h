#ifndef __SAVE_H__
#define __SAVE_H__

typedef struct{
    uint8_t magic;
    uint8_t slotIndex;
    uint8_t data[0x70];
    uint8_t padding[0x2];
    uint32_t checksum;
}SaveData;

typedef struct {
    uint32_t snsItems;
    uint8_t padding[0x18];
    uint32_t checksum;
}GlobalData;

#endif
