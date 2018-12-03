#include "my.h"
int my_strrindex(char* str, char c){
	int counter=0;
	int checker=-1;
	if(str!=NULL){		
		while(str[counter]){
			counter++;
			if(str[counter]==c)
				checker=counter;
		}
	}
	return checker;
}