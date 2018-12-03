#include "my.h"
int my_atoi(char *n){
	int result=0;
	int potato='0';
	int length= my_strlen(n);
	int sign=1;
	int check=0;
	for(int i=0; i<length;i++){
		if(n[i]== '-'){
			sign=sign*-1;
		}
		if((n[i]<'0'|| n[i]>'9') &&check==1)
			return result/10*sign;
		if(n[i]>='0'&&n[i]<='9'){
			check=1;
			result=result+(n[i]-potato);
			result=result*10;
		}

	}
	return result/10*sign;
}	