#include<stdio.h>

float d4(float x){
	//ignore 0 in 5th and 6th decimal
	int p,q;
	p = x*10000;
	q = x*100000;
	if(q%10 > 4){
		++p;
	}
	return((float)p/10000);
}

float d5(float x){	
	//ignore 0 in 6th decimal
	int p,q;
	p = x*100000;
	q = x*1000000;
	if(q%10 > 4){
		++p;
	}
	return((float)p/100000);
}

void main(){
	
	float x,y=22,z=7;
	int p,q;
	x=y/z;
	printf("%f\n",x);
	printf("%f\n",d4(x));	
	printf("%f",d5(x));
	
}
