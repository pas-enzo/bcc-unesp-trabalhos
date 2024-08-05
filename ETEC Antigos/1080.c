#include <stdio.h>
 
int main() {
 
    int i, x, maior=0, pos;
    
    for(i=1;i<=100;i++){
    	scanf("%d", &x);
    	
    	if(maior<x){
    		maior = x;
    		pos = i;
		}
		
	}
	
	printf("%d\n%d\n", maior, pos);
 
    return 0;
}
