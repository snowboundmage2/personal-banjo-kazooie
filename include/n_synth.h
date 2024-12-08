#ifndef __N_AUDIO_INT__
#define __N_AUDIO_INT__

#include "synthInternals.h"

#define SAMPLES               184
#define SAMPLE184(delta)      (((delta) + (SAMPLES / 2)) / SAMPLES) * SAMPLES
#define FIXED_SAMPLE          SAMPLES

#define N_AL_DECODER_IN	        0
#define	N_AL_RESAMPLER_OUT	0
#define N_AL_TEMP_0	        0
#define	N_AL_DECODER_OUT        368
#define	N_AL_TEMP_1	        368
#define	N_AL_TEMP_2	        736
#define	N_AL_MAIN_L_OUT	        1248
#define	N_AL_MAIN_R_OUT	        1616
#define	N_AL_AUX_L_OUT	        1984
#define	N_AL_AUX_R_OUT	        2352

#define N_AL_DIVIDED            368

typedef struct N_ALLoadFilter_s{
    uint8_t                          pad0[0xC];
    ADPCM_STATE                 *state; //0xC
    ADPCM_STATE                 *lstate; //0x10
    ALRawLoop                   loop; //0x14
    struct ALWaveTable_s        *table; //0x20
    int32_t                         bookSize;
    ALDMAproc                   dma;
    void                        *dmaState;
    int32_t                         sample;
    int32_t                         lastsam;
    int32_t                         first;
    int32_t                         memin; 
} N_ALLoadFilter;

typedef struct N_ALResampler_s {
    //ALFilter            filter;
    RESAMPLE_STATE      *state;
    float                 ratio;
    int32_t			upitch;
    float		        delta;
    int32_t			first;
} N_ALResampler;

typedef struct N_ALEnvMixer_s {
    ENVMIX_STATE    *state;
    int16_t         pan;
    int16_t         volume;
    int16_t         cvolL;
    int16_t         cvolR;
    int16_t         dryamt;
    int16_t         wetamt;
    uint16_t         lratl;
    int16_t         lratm;
    int16_t         ltgt;
    uint16_t         rratl;
    int16_t         rratm;
    int16_t         rtgt;
    int32_t         delta;
    int32_t         segEnd;
    int32_t         first;
    ALParam     *ctrlList;
    ALParam     *ctrlTail;
    ALFilter    **sources;
    int32_t         motion;
} N_ALEnvMixer;


typedef struct N_PVoice_s {
    ALLink               node;
    struct N_ALVoice_s    *vvoice;
/** ALLoadFilter *********************************/
    ADPCM_STATE                 *dc_state;
    ADPCM_STATE                 *dc_lstate;
    ALRawLoop                   dc_loop;
    struct ALWaveTable_s        *dc_table;
    int32_t                         dc_bookSize;
    ALDMAproc                   dc_dma;
    void                        *dc_dmaState;
    int32_t                         dc_sample;
    int32_t                         dc_lastsam;
    int32_t                         dc_first;
    int32_t                         dc_memin; 
/** ALResampler *********************************/
    RESAMPLE_STATE      *rs_state;
    float                 rs_ratio;
    int32_t			rs_upitch;
    float		        rs_delta;
    int32_t			rs_first;
/** ALEnvMixer *********************************/
    ENVMIX_STATE	*em_state;
    int16_t		        em_pan;
    int16_t		        em_volume;
    int16_t		        em_cvolL;
    int16_t		        em_cvolR;
    int16_t		        em_dryamt;
    int16_t		        em_wetamt;
    uint16_t                 em_lratl;
    int16_t                 em_lratm;
    int16_t                 em_ltgt;
    uint16_t                 em_rratl;
    int16_t                 em_rratm;
    int16_t                 em_rtgt;
    int32_t                 em_delta;
    int32_t                 em_segEnd;
    int32_t			em_first;
    ALParam		*em_ctrlList;
    ALParam		*em_ctrlTail;
    int32_t                 em_motion;
    int32_t                 offset;
} N_PVoice;

#define N_AL_MAX_RSP_SAMPLES      184


typedef Acmd *(*N_ALCmdHandler)(int32_t, Acmd *);

typedef struct N_ALFilter_s {
    struct N_ALFilter_s   *source;
    N_ALCmdHandler        handler;
    ALSetParam          setParam;
    int16_t                 inp;
    int16_t                 outp;
    int32_t                 type;
} N_ALFilter;


typedef struct N_ALMainBus_s {
    N_ALFilter           filter;
} N_ALMainBus;

typedef struct N_ALAuxBus_s {
    ALFilter            filter;
    int32_t                 sourceCount;
    int32_t                 maxSources;
    N_PVoice           **sources;
    ALFx                *fx;
    ALFx		*fx_array[AL_MAX_AUX_BUS_SOURCES];
} N_ALAuxBus;

extern N_ALSynth *n_syn;

/*
 * prototypes for private driver functions
 */
ALParam         *__n_allocParam(void);
void            __n_freeParam(ALParam *param);
void            _n_freePVoice(N_PVoice *pvoice);
void            _n_collectPVoices();

int32_t             _n_timeToSamples(int32_t micros);
ALMicroTime     _n_samplesToTime(int32_t samples);

int n_alEnvmixerParam(N_PVoice *v, int32_t paramId, void* param);
//n_alLoadParam
int n_alLoadParam(N_PVoice *v, int32_t paramId, void* param);
#endif
