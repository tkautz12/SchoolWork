#include "my.h"
char* my_strconcat(char *a, char *b){
	char *temp;
	int l1 = my_strlen(a);
	int l2 = my_strlen(b);
	if(a == NULL && b == NULL){
		temp = NULL;
	}
	else if(a == NULL && b != NULL){
		temp = (char*)malloc(l2 + 1);
		for(int i = 0; i <= l2; i++){
			temp[i] = b[i];
		}
	}
	else if(a != NULL && b == NULL){
		temp = (char*)malloc(l1 + 1);
		for(int i = 0; i <= l1; i++){
			temp[i] = a[i];
		}
	}
	else{
		temp = (char*)malloc(l1 + l2 + 1);
		for(int i = 0; i < l1; i++){
			temp[i] = a[i];
		}
		for(int i = 0; i < l2; i++){
			temp[i] = b[i];
		}
	}
	return temp;
}