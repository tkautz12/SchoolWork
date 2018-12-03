#include "my.h"
int my_strlen(char* str){
	int counter=0;
	if(str!=NULL){		
		while(str[counter]){
			counter++;
		}
		return counter;
	}
	else{
		return -1;
	}
}