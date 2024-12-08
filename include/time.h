#ifndef GL_TIME_H
#define GL_TIME_H

void time_reset(void);
void time_setDeltaReal_sec(float d_seconds);
void time_setDeltaReal_frames(int d_frames);
int time_getDeltaReal_frames(void);
float time_getDelta(void);
float time_func_8033DDB8(void);
float time_getDelta_frames(void);
void time_setMultiplier(float multiplier);

#endif
