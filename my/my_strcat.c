
#include "my.h"

char *my_strcat(char* dst, char* src){
    int lend = my_strlen(dst), lens = my_strlen(src), i;

    if(dst == NULL || src == NULL || src == '\0' || dst == '\0') return dst;
    
    for(i = 0; i<lens; i++) dst[lend + i] = src[i];

    dst[lend+lens] = '\0';
    return dst;
}