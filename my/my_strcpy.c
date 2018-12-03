#include "my.h"
char* my_strcpy(char *dst, char *src){
		int l = my_strlen(src);
	if(dst==NULL||dst=='\0')
		return '\0';
	if(src==NULL||src=='\0'||src[0]=='\0')
		return dst;
	for(int i=0; i<l;i++)
		dst[i]=src[i];
	return dst;
/*
	int l = my_strlen(src);
	if(dst != NULL && l != -1&&src!=NULL){
		for(int i = 0; i < l; i++){ //if segfault, check on int i
			dst[i] = src[i];
		}
		return dst;
	}
	return NULL;
	*/
}