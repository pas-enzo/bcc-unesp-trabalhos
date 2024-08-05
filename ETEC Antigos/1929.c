#include <stdio.h>

int main(){
	
	int a, b, c, d, temp;
	int t1, t2, ver=0;
	
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
	
	if(a>b){
		temp=a;
		a=b;
		b=temp;
	}

	t1 = a+b;
	
	t2 = b+c;			
				
	if(t1>c || t2>d)
		printf("S\n");
		
	else 
		printf("N\n");
	
	return 0;
}