#include <stdio.h>

int main(){
	
	int x, i;
	
	scanf("%d", &x);
	
	if(x%2==0){
		for(i=x;i<=x+12;i++){
		
			if(i%2!=0){
				printf("%d\n", i);
			}
		}
	}
	
	else{
		for(i=x;i<=x+11;i++){
		
			if(i%2!=0){
				printf("%d\n", i);
			}
		}
		
	}
	

	return 0;
}
