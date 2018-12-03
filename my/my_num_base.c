#include "my.h"
void my_num_base(int i, char* base){
	long x;
	if((base==NULL)|| (my_strlen(base)==0)){
		my_str("Error");
		return;
	}
	x=i;
	if(i<0){
		my_char('-');
		x=x*(-1);	}
	int length=my_strlen(base);
	if (length==1){
		for(int i=0;i<length;i++)
		my_char(*base);
		return;
	}
	if(i==0){
	my_char(base[0]);
	return;
	}
	if(my_strlen(base)==2){
		if (x==0){
			return;
		}
		if (x == 1){
			my_char(base[1]);
			return;
		}
		else{
			if(x%2 == 1){
				my_num_base(x/2, base);
				my_char(base[1]);
				return;
			}
			else{
				my_num_base(x/2, base);
				my_char(base[0]);
				return;
			}
		}
	}

	int baseNum=1;
	long temp=x;
		while(temp>length){
			temp=temp/length;
			baseNum=baseNum*length;
		}
		while(baseNum>0){
			int index = x/baseNum;
			x=x%baseNum;
			my_char(base[index]);
			baseNum=baseNum/length;
		}
}