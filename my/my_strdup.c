
#include "my.h"
char* my_strdup(char *str){
	char *temp;
	int length= my_strlen(str);
	if (str == NULL){
		temp = NULL;
	}
	else{
		int i;
		temp = (char*) malloc((length + 1) * sizeof(char)); //gotta fix that one up
		for(i = 0; i < my_strlen(str); i++){
			temp[i] = str[i];
		}
		temp[i]='\0';
	}
	return temp;
}

#include "my.h"
