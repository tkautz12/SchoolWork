#include "my.h"
char* my_strnconcat(char *a, char *b, int n){
	char *temp;
	int l1 = my_strlen(a);
	int l2 = my_strlen(b);
	if(a == NULL && b == NULL){
		temp = NULL;
	}
	else if(a != NULL && b == NULL){
		temp = (char*)malloc(l1 + 1);
		for(int i = 0; i <= l1; i++){
			temp[i] = a[i];
		}
	}
	else if(a == NULL && b != NULL){
		if(l2 < n){
			temp = (char*)malloc(l2 + 1);
			for(int i = 0; i <= l2; i++){
				temp[i] = b[i];
			}
		}
		else{
			temp = (char*)malloc(n);
			for(int i = 0; i < n; i++){
				temp[i] = b[i];
			}
		}
	}
	else{
		if(l2 < n){
			temp = (char*)malloc(l1 + l2 + 1);
		}
		else{
			temp = (char*)malloc(l1+n);
		}
		for(int i = 0; i < l1; i++){
			temp[i] = a[i];
		}
		if(l2 < n){
			for(int i = 0; i < l2; i++){
				temp[i + l1] = b[i];
			}
		}
		else{
			for(int i = 0; i < n; i++){
				temp[i + l1] = b[i];
			}
		}
		
	}
	return temp;
}