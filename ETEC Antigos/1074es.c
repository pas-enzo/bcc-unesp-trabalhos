#include <stdio.h>

int main(){
	
	int n, alg, i;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &alg);
		
		if(alg%2==0 && alg>0)
			printf("EVEN POSITIVE\n");
			
		if(alg%2==0 && alg<0)
			printf("EVEN NEGATIVE\n");
			
		if(alg%2!=0 && alg>0)
			printf("ODD POSITIVE\n");
			
		if(alg%2!=0 && alg<0)
			printf("ODD NEGATIVE\n");
			
		else{
			printf("NULL\n");
		}
	}
	
	
	
	return 0;
}
