#ifndef VARIABLES_H
#define VARIABLES_H

#define BAD_PI 3.141592654
#define BAD_DTOR (BAD_PI / 180.0)
#define M_TAU (2 * M_PI)
#define BAD_TAU 6.2831853

struct Overlay {
    void *start;
    void *end;
};

extern struct Overlay gOverlayTable[];

extern float climbPoleBottom[3];
extern float climbPoleTop[3];

#endif
