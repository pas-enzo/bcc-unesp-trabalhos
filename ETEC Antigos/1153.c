#include <stdio.h>

int main(){
	
	int n, sub=1, i;
	
	scanf("%d", &n);
	
	for(i=n;i>=1;i--){
		
		sub = sub*i;
		
	}
	
	printf("%d\n", sub);

	return 0;	
}
