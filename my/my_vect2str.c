#include "my.h"
char *my_vect2str(char **x){
	if(x==NULL)
		return NULL;
	if(*x==NULL)
		return my_strdup("");
	char* str =(char*) malloc(500*sizeof(char));
	my_strcpy(str,"");
	for(int i = 0; x[i]!=NULL; i++){
		my_strcat(str,x[i]);
		if(x[i+1]!=NULL)
			my_strcat(str, " ");
	}
	str[my_strlen(str)]='\0';

	return str;
}