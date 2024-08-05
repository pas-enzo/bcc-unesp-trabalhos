#include <stdio.h>

int main(){
	
	int n, i;
	int a, b, c, d, e, f;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		
		a=i;
		b=a*a;
		c=a*b;
		
		d=i;
		e=b+1;
		f=c+1;
		
		printf("%d %d %d\n", a, b, c);
		printf("%d %d %d\n", d, e, f);
	}
	
	
	return 0;
}
