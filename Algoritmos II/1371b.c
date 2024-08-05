#include <stdio.h>


int main(){
	
	int n=1, i, j, div=0;
	
	while(n!=0){
		
		scanf("%d", &n); 
		
		for(i=1;i*i<=n;++i){
			if(i==1)
				printf("%d", i);

				
			else 	
				printf(" %d", i*i);
			
		}
		
		printf("\n");
		
	}
	
	
	return 0;
}