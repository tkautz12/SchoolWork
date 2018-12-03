#include "my.h"
int my_revstr(char* str){
	int length=my_strlen(str);
	char temp;
	int L;
	if(str !=NULL && length!=0){
	for(int i=0; i<length/2;i++){
		L=length-1-i;
		temp = str[i];
		str[i]=str[L];
		str[L]=temp;

			}
		}
	return length;
	}