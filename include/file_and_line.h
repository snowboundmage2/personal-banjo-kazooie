#ifndef FILE_AND_LINE_H
#define FILE_AND_LINE_H
#include <assert.h>
extern void func_8033F000(const char *, const char *, int);

#ifdef NONMATCHING
    #define LINE(line_num) __LINE__
    #define FILE(file_name) __FILE__
    #define matching_assert(EX, F, L) assert(EX)
#else
    #define LINE(line_num) line_num
    #define FILE(file_name) file_name
    #define matching_assert(EX, F, L)  ((EX)?((void)0):func_8033F000(#EX, F, L))
#endif

#endif
