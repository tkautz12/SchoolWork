#include "my.h"

void my_int(int i){
	long num=i;
	long x=1;
	if(i<0){
		my_char('-');
		num=-num;
	} 
	for(int j=10; j<=(num/10); j*=10){
		x=j;
	}
	if(!(i<10&&i>-10)){
		x=x*10;
	}
	while (x){
		my_char('0'+num/x);
		num=num% x;
		x=x/10;
	}

}