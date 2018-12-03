#include "my.h"
int my_strindex(char* str, char c){
	int counter=0;
	if(str!=NULL&&c!='\0'){		
		while(str[counter]){
			if(str[counter]==c)
				return counter;
			counter++;
		}
	}
	return -1;
}