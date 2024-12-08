#ifndef _OSINT_H
#define _OSINT_H

#include <os_internal.h>
#include <stdint.h>

typedef struct __OSEventState
{
    OSMesgQueue *messageQueue;
    OSMesg message;
} __OSEventState;
extern struct __osThreadTail
{
    OSThread *next;
    OSPri priority;
} __osThreadTail;

//maybe should be in exceptasm.h?
extern void __osEnqueueAndYield(OSThread **);
extern void __osDequeueThread(OSThread **, OSThread *);
extern void __osEnqueueThread(OSThread **, OSThread *);
extern OSThread *__osPopThread(OSThread **);
extern void __osDispatchThread(void);

extern void __osSetTimerIntr(OSTime);
extern OSTime __osInsertTimer(OSTimer *);
extern void __osTimerInterrupt(void);
extern uint32_t __osProbeTLB(void *);
extern int     __osSpDeviceBusy(void);

extern OSThread *__osRunningThread;
extern OSThread *__osActiveQueue;
extern OSThread *__osFaultedThread;
extern OSThread *__osRunQueue;

extern OSTimer *__osTimerList;
extern OSTimer __osBaseTimer;
extern OSTime __osCurrentTime;
extern uint32_t __osBaseCounter;
extern uint32_t __osViIntrCount;
extern uint32_t __osTimerCounter;

extern __OSEventState __osEventStateTab[OS_NUM_EVENTS];


//not sure if this should be here
extern int32_t osViClock;
extern void __osTimerServicesInit(void);
extern int32_t __osAiDeviceBusy(void);
extern int __osDpDeviceBusy(void);
#endif
