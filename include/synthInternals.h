/*====================================================================
 * audioInternals.h
 *
 * Synopsis:
 *
 * Copyright 1993, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

#ifndef __audioInternals__
#define __audioInternals__


/*
 * filter message ids
 */
enum {
    AL_FILTER_FREE_VOICE,
    AL_FILTER_SET_SOURCE,
    AL_FILTER_ADD_SOURCE,
    AL_FILTER_ADD_UPDATE,
    AL_FILTER_RESET,
    AL_FILTER_SET_WAVETABLE,
/*    AL_FILTER_SET_DMA_PROC,*/
/*    AL_FILTER_SKIP_LOOP,*/
    AL_FILTER_SET_DRAM,
    AL_FILTER_SET_PITCH,
    AL_FILTER_SET_UNITY_PITCH,
    AL_FILTER_START,
/*    AL_FILTER_SET_DECAY,*/
/*    AL_FILTER_SET_FC,*/
    AL_FILTER_SET_STATE,
    AL_FILTER_SET_VOLUME,
    AL_FILTER_SET_PAN,
    AL_FILTER_START_VOICE_ALT,
    AL_FILTER_START_VOICE,
    AL_FILTER_STOP_VOICE,
    AL_FILTER_SET_FXAMT
};

#define AL_MAX_RSP_SAMPLES      160
    
/*
 * buffer locations based on AL_MAX_RSP_SAMPLES
 */
#define AL_DECODER_IN	        0
#define	AL_RESAMPLER_OUT	0
#define AL_TEMP_0	        0
#define	AL_DECODER_OUT	        320
#define	AL_TEMP_1	        320
#define	AL_TEMP_2	        640
#define	AL_MAIN_L_OUT	        1088
#define	AL_MAIN_R_OUT	        1408
#define	AL_AUX_L_OUT	        1728
#define	AL_AUX_R_OUT	        2048

/*
 * filter types
 */
enum {
    AL_ADPCM,
    AL_RESAMPLE,
    AL_BUFFER,
    AL_SAVE,
    AL_ENVMIX,
    AL_FX,
    AL_AUXBUS,
    AL_MAINBUS
};

typedef struct ALParam_s {
    struct ALParam_s    *next;
    int32_t                 delta;
    int16_t                 type;
    union {
        float             f;
        int32_t             i;
    } data;
    union {
        float             f;
        int32_t             i;
    } moredata;
    union {
        float             f;
        int32_t             i;
    } stillmoredata;
    union {
        float             f;
        int32_t             i;
    } yetstillmoredata;
} ALParam;

typedef struct {
    struct ALParam_s            *next;
    int32_t                         delta;
    int16_t                         type;
    int16_t                         unity;  /* disable resampler */
    float                         pitch;
    int16_t                         volume;
    ALPan                       pan;
    uint8_t                          fxMix;
    int32_t                         samples;
    struct ALWaveTable_s        *wave;
} ALStartParamAlt;

typedef struct {
    struct ALParam_s            *next;
    int32_t                         delta;
    int16_t                         type;
    int16_t                         unity;  /* disable resampler */
    struct ALWaveTable_s        *wave;
} ALStartParam;

typedef struct {
    struct ALParam_s    *next;
    int32_t                 delta;
    int16_t                 type;
    struct PVoice_s     *pvoice;
} ALFreeParam;

typedef Acmd *(*ALCmdHandler)(void *, int16_t *, int32_t, int32_t, Acmd *);
typedef int32_t   (*ALSetParam)(void *, int32_t, void *);

typedef struct ALFilter_s {
    struct ALFilter_s   *source;
    ALCmdHandler        handler;
    ALSetParam          setParam;
    int16_t                 inp;
    int16_t                 outp;
    int32_t                 type;
} ALFilter;

void    alFilterNew(ALFilter *f, ALCmdHandler h, ALSetParam s, int32_t type);

#define AL_MAX_ADPCM_STATES     3       /* Depends on number of subframes
                                         * per frame and loop length
                                         */
typedef struct {
    ALFilter                    filter;
    ADPCM_STATE                 *state;
    ADPCM_STATE                 *lstate;
    ALRawLoop                   loop;
    struct ALWaveTable_s        *table;
    int32_t                         bookSize;
    ALDMAproc                   dma;
    void                        *dmaState;
    int32_t                         sample;
    int32_t                         lastsam;
    int32_t                         first;
    int32_t                         memin; 
} ALLoadFilter;

void    alLoadNew(ALLoadFilter *f, ALDMANew dma, ALHeap *hp);
Acmd    *alAdpcmPull(void *f, int16_t *outp, int32_t byteCount, int32_t sampleOffset, Acmd *p);
Acmd    *alRaw16Pull(void *f, int16_t *outp, int32_t byteCount, int32_t sampleOffset, Acmd *p);
int32_t     alLoadParam(void *filter, int32_t paramID, void *param);

typedef struct ALResampler_s {
    ALFilter            filter;
    RESAMPLE_STATE      *state;
    float                 ratio;
    int32_t			upitch;
    float		        delta;
    int32_t			first;
    ALParam		*ctrlList;
    ALParam		*ctrlTail;
    int32_t                 motion;
} ALResampler;

typedef struct {
    int16_t		        fc;
    int16_t		        fgain;
    union {
        int16_t		fccoef[16];
        s64             force_aligned;
    } fcvec;
    POLEF_STATE		*fstate;
    int32_t			first;
} ALLowPass;

typedef struct {
    uint32_t		input;
    uint32_t		output;
    int16_t		ffcoef;
    int16_t		fbcoef;
    int16_t		gain;
    float		rsinc;
    float		rsval;
    int32_t		rsdelta;
    float		rsgain;
    ALLowPass	*lp;
    ALResampler	*rs;
} ALDelay;

typedef int32_t   (*ALSetFXParam)(void *, int32_t, void *);
typedef struct {
    struct ALFilter_s   filter;
    int16_t			*base;
    int16_t			*input;
    uint32_t			length;
    ALDelay		*delay;
    uint8_t			section_count;
    ALSetFXParam        paramHdl;
} ALFx;

void    alFxNew(ALFx *r, ALSynConfig *c, ALHeap *hp);
Acmd    *alFxPull(void *f, int16_t *outp, int32_t out, int32_t sampleOffset, Acmd *p);
int32_t     alFxParam(void *filter, int32_t paramID, void *param);
int32_t     alFxParamHdl(void *filter, int32_t paramID, void *param);

#define AL_MAX_MAIN_BUS_SOURCES       1
typedef struct ALMainBus_s {
    ALFilter            filter;
    int32_t                 sourceCount;
    int32_t                 maxSources;
    ALFilter            **sources;
} ALMainBus;

void    alMainBusNew(ALMainBus *m, void *ptr, int32_t len);
Acmd    *alMainBusPull(void *f, int16_t *outp, int32_t outCount, int32_t sampleOffset, Acmd *p);
int32_t     alMainBusParam(void *filter, int32_t paramID, void *param);

#define AL_MAX_AUX_BUS_SOURCES       8
#define AL_MAX_AUX_BUS_FX	     1
typedef struct ALAuxBus_s {
    ALFilter            filter;
    int32_t                 sourceCount;
    int32_t                 maxSources;
    ALFilter            **sources;
    ALFx		fx[AL_MAX_AUX_BUS_FX];
} ALAuxBus;

void    alAuxBusNew(ALAuxBus *m, void *ptr, int32_t len);
Acmd    *alAuxBusPull(void *f, int16_t *outp, int32_t outCount, int32_t sampleOffset, Acmd *p);
int32_t     alAuxBusParam(void *filter, int32_t paramID, void *param);

void    alResampleNew(ALResampler *r, ALHeap *hp);
Acmd    *alResamplePull(void *f, int16_t *outp, int32_t out, int32_t sampleOffset, Acmd *p);
int32_t     alResampleParam(void *f, int32_t paramID, void *param);

typedef struct ALSave_s {
    ALFilter            filter;
    int32_t	       		dramout;
    int32_t                 first;
} ALSave;

void    alSaveNew(ALSave *r);
Acmd    *alSavePull(void *f, int16_t *outp, int32_t outCount, int32_t sampleOffset, Acmd *p);
int32_t     alSaveParam(void *f, int32_t paramID, void *param);

typedef struct ALEnvMixer_s {
    ALFilter            filter;
    ENVMIX_STATE	*state;
    int16_t		        pan;
    int16_t		        volume;
    int16_t		        cvolL;
    int16_t		        cvolR;
    int16_t		        dryamt;
    int16_t		        wetamt;
    uint16_t                 lratl;
    int16_t                 lratm;
    int16_t                 ltgt;
    uint16_t                 rratl;
    int16_t                 rratm;
    int16_t                 rtgt;
    int32_t                 delta;
    int32_t                 segEnd;
    int32_t			first;
    ALParam		*ctrlList;
    ALParam		*ctrlTail;
    ALFilter            **sources;
    int32_t                 motion;
} ALEnvMixer;

void    alEnvmixerNew(ALEnvMixer *e, ALHeap *hp);
Acmd    *alEnvmixerPull(void *f, int16_t *outp, int32_t out, int32_t sampleOffset, Acmd *p);
int32_t     alEnvmixerParam(void *filter, int32_t paramID, void *param);


/*
 * heap stuff
 */
typedef struct {
    int32_t         magic;  /* check structure integrety                    */
    int32_t         size;   /* size of this allocated block                 */
    uint8_t          *file;  /* file that this alloc was called from         */
    int32_t         line;   /* line that it was called from                 */
    int32_t         count;  /* heap call number                             */
    int32_t         pad0;
    int32_t         pad1;
    int32_t         pad2;   /* Make it 32 bytes                             */
} HeapInfo;

#define AL_CACHE_ALIGN  15

/*
 * synth stuff
 */

typedef struct PVoice_s {
    ALLink               node;
    struct ALVoice_s    *vvoice;
    ALFilter            *channelKnob;
    ALLoadFilter        decoder;
    ALResampler         resampler;
    ALEnvMixer          envmixer;
    int32_t                 offset;
} PVoice;



/*
 * prototypes for private driver functions
 */
ALParam         *__allocParam(void);
void            __freeParam(ALParam *param);
void            _freePVoice(ALSynth *drvr, PVoice *pvoice);
void            _collectPVoices(ALSynth *drvr);

int32_t             _timeToSamples(ALSynth *drvr, int32_t micros);
ALMicroTime     _samplesToTime(ALSynth *synth, int32_t samples);



#endif

