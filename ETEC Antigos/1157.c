#include<stdio.h>

int main(){
	
	int N, i=1, div;
	
	scanf("%d", &N);
	
	for(i=1;i<=N;i++){
		
		if(N%i==0){
			
			div=i;
			printf("%d\n", div);
			
		}
		
		
	}
	
	return 0;
}
