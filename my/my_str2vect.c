#include "my.h"

char** my_str2vect(char* str){
	if(str == NULL){
		return NULL;
	}
	int place =0;
	int vectPlace=0;
	int len=0;
	int num=0;
	int next=0;
	while(str[place]!='\0'){
		next = place+1;
		if((str[place]!=' ')&&(str[place]!='\n')){
			if((str[next] == ' ') || (str[next] == '\n')){
				num++;
				place++;
			}
			else if (str[next]=='\0')
				num++;
		}
		place++;
	}
	char** vect = (char**)malloc((num+1)*sizeof(char*));
	vect[num]=NULL;
	place=0;
	while(str[place]!='\0'){
		next=place+1;
		if((str[place] != ' ') && (str[place] != '\n')){
			if((str[next] == ' ') || (str[next] == '\n') || (str[next] == '\0')){
				len++;
				vect[vectPlace]=(char*)malloc((len+1)*sizeof(char));
				for (int i = 0; i < len; i++){
					vect[vectPlace][i]=str[place-len+i+1];
				}
				vect[vectPlace][len]='\0';
				len=0;
				vectPlace++;
				if(str[next]!='\0'){
					place++;
				}
			}
			else{
				len++;
			}
		}
		place++;
	}
	return vect;
}