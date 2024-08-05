#include <stdio.h>

int main(){
	
	int x=0, soma=0;
	int i;
	
	while(1){
		scanf("%d", &x);
		
		if(x%2==0){
			for(i=x;i<x+10;i+=2){
				soma+=i;
			}
		}
		
		else{
			for(i=x+1;i<x+11;i+=2){
				soma+=i; //soma = soma + i
			}
		}
		
		if(x==0)
			break;
		
		printf("%d\n", soma);
		soma=0;
		
	}

	
	return 0;
}
