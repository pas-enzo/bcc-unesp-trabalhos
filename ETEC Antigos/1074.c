#include<stdio.h>
#include<math.h>

int main(){
	
	int N, X, i;
	
	scanf("%d", &N);
	
	if(N<10000){
	
		for(i=1;i<=N;i++){
		
		scanf("%d", &X);
		
		if(X>pow(-10,7) && X<pow(10,7)){
		
			if(X==0){
				printf("NULL\n");
				}
		
			if(X%2==0 && X>0){
				printf("EVEN POSITIVE\n");
				}
		
			if(X%2!=0 && X>0){
				printf("ODD POSITIVE\n");
				}
		
			if(X%2!=0 && X<0){
				printf("ODD NEGATIVE\n");
				}
		
			if(X%2==0 && X<0){
				printf("EVEN NEGATIVE\n");
				}
		
			}
	
		}
		
	}
	
	
	return 0;
}
