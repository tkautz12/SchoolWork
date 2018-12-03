#include "my.h"
void my_str(char* str){
	int counter=0;
	if(str!=NULL){		
		while(str[counter]){
			my_char(str[counter]);
			counter++;
		}
	}
}