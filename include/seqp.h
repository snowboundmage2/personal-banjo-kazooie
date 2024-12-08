

#define KILL_TIME	50000	/* 50 ms */

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

ALVoiceState    *__n_mapVoice(ALSeqPlayer *, uint8_t, uint8_t, uint8_t);
void            __n_unmapVoice(ALSeqPlayer *seqp, ALVoice *voice);
char		__n_voiceNeedsNoteKill(ALSeqPlayer *seqp, ALVoice *voice, ALMicroTime killTime);	/* sct 1/5/96 */

ALVoiceState    *__n_lookupVoice(ALSeqPlayer *, uint8_t, uint8_t);
ALSound         *__lookupSound(ALSeqPlayer *, uint8_t, uint8_t, uint8_t);
ALSound         *__n_lookupSoundQuick(ALSeqPlayer *, uint8_t, uint8_t, uint8_t);

int16_t             __n_vsVol(ALVoiceState *voice, ALSeqPlayer *seqp);
ALMicroTime     __n_vsDelta(ALVoiceState *voice, ALMicroTime t);
ALPan           __n_vsPan(ALVoiceState *voice, ALSeqPlayer *seqp);

void		__n_initFromBank(ALSeqPlayer *seqp, ALBank *b);
void            __n_initChanState(ALSeqPlayer *seqp);
void            __resetPerfChanState(ALSeqPlayer *seqp, s32 chan);
void            __n_setInstChanState(ALSeqPlayer *seqp, ALInstrument *inst, s32 chan);

void            __seqpPrintVoices(ALSeqPlayer *);
void		__n_seqpReleaseVoice(ALSeqPlayer *seqp, ALVoice *voice,
                                           ALMicroTime deltaTime);

void            __n_seqpStopOsc(ALSeqPlayer *seqp, ALVoiceState *vs);

void		__postNextSeqEvent(ALSeqPlayer *seqp);			/* sct 11/7/95 */

