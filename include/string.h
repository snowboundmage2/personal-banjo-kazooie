#ifndef STRING_H
#define STRING_H

#include "structs.h"

void strcat(char *dst, char *src);
void strcatc(char *dst, char src);
void strFToA(char *dst, float val);
void _strFToA(char *dst, float val, int32_t decPlaces);
void strIToA(char *str, int32_t num);
void _strIToA(char *str, int32_t num, char base);
void strcpy(char *dst, char *src);
int32_t strlen(char *str);
void strToUpper(char *str);



#endif
