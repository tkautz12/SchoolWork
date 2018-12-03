#include "my.h"
char* my_strrfind(char *str, char c){
	char* index=NULL;

	if((str==NULL)&&(c=='\0')){	
		return index;
	}
	
	else{
		while(*str)
		{
			if(*str==c)
				index=str;
			str++;
		}
		if(index==NULL){
		return index;
	}
		else{
			str=index;
			return str;
		}

	}
}