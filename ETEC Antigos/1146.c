#include <stdio.h>

int main(){
	
	int x, i;
	int ultimo;
	
	while(1){
		scanf("%d", &x);
		
		if(x==0)
			break;
		
		ultimo=x;
		
		for(i=1;i<=x-1;i++){
			printf("%d ", i);
		}
		
		printf("%d\n", ultimo);
		
		if(x==0)
			break;
		
	}
	
	
	return 0;
}
