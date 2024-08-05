#include <stdio.h>

int main(){
	
	int a, b, c, d;
	int temp;
	
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	if(c>d){
		temp=c;
		c=d;
		d=temp;
	}
	
	if(b>d){
		temp=b;
		b=d;
		d=temp;
	}
	
	if(b>c){
		temp=b;
		b=c;
		c=temp;
	}
	
	if(a>d){
		temp=a;
		a=d;
		d=temp;
	}
	
	if(a>c){
		temp=a;
		a=c;
		c=temp;
	}
	
	if(a>d){
		temp=a;
		a=b;
		b=temp;
	}
	
	printf("%d %d %d %d \n", a, b, c, d);
	
	if(a+b>c || b+c>d){
		printf("S\n");
	}
	
	else
		printf("N\n");
	
	
	return 0;
}