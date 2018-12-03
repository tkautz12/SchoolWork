#include "my.h"
char* my_strncpy(char *dst, char *src, int n){
	int l = my_strlen(src);
	if (n<0)
		n=0;
	if(dst==NULL||dst=='\0')
		return '\0';
	if(src==NULL||src=='\0'||src[0]=='\0'||n==0)
		return dst;
	if(l>n)
		l=n;
	for(int i=0; i<l;i++)
		dst[i]=src[i];
	
	return dst;


	/*
	if(dst != NULL && l != -1&& src!=NULL){
		for(int i = 0; i < l && i < n; i++){ //if segfault, check on int i
			dst[i] = src[i];
		}
		return dst;
	}
	return NULL;
	*/
}