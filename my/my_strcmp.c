#include "my.h"
int my_strcmp(char* a, char* b){
	int k=0;
	int l1= my_strlen(a);
	int l2=my_strlen(b);
	if(a!=NULL && b!=NULL){
		int i;
		for(i=0;i<l2&&i<l2&&k==0;i++){
			k=a[i]-b[i];
		}
		if(k==0&&i<l1)
			k=1;
		else if (k==0&&i<l2)
			k=-1;
	}
	else{
		if (a==NULL && b==NULL)
			return 0;
		else if(a==NULL)
			return -1;
		else if (b==NULL)
			return 1;
	}
	return k;
}