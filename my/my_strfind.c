#include "my.h"
char* my_strfind(char* str, char c){
	if((str==NULL)&&(c=='\0')){
		return NULL;
	}
	else{
		while(*str)
		{
		if(*str==c)
			return str;
		str++;
		}
		return NULL;
	}
}