#ifndef RAREZIP_H
#define RAREZIP_H

#include <stdint.h>

extern struct huft *D_80007270;

extern uint8_t *inbuf; //inbuf
extern uint8_t *D_80007284; //slide
extern uint32_t inptr; //inptr
extern uint32_t wp; //wp
extern struct huft *D_80007290; //unk
extern uint32_t bb; //bb
extern uint32_t bk; //bk
extern uint32_t crc1; //crc1
extern uint32_t crc2; //crc2
extern uint32_t hufts; //hufts


#ifndef WSIZE
#  define WSIZE 0x8000     /* window size--must be a power of two, and */
#endif                     /*  at least 32K for zip's deflate method */

//#define get_byte()  (inptr < insize ? inbuf[inptr++] : fill_inbuf(0))
#define get_byte()  (inbuf[inptr++])

#ifdef CRYPT
  uch cc;
#  define NEXTBYTE() \
     (decrypt ? (cc = get_byte(), zdecode(cc), cc) : get_byte())
#else
#  define NEXTBYTE()  (uint8_t)get_byte()
#endif
#define NEEDBITS(n) {while(k<(n)){b|=((uint32_t)NEXTBYTE())<<k;k+=8;}}
#define DUMPBITS(n) {b>>=(n);k-=(n);}

struct huft {
  uint8_t e;                /* number of extra bits or operation */
  uint8_t b;                /* number of bits in this code or subcode */
  union {
    uint16_t n;              /* literal, length base, or distance base */
    struct huft *t;     /* pointer to next level of table */
  } v;
};

/* If BMAX needs to be larger than 16, then h and x[] should be ulg. */
#define BMAX 16         /* maximum bit length of any code (16 for explode) */
#define N_MAX 288       /* maximum number of codes in any set */

int bkboot_inflate(void);

#endif
