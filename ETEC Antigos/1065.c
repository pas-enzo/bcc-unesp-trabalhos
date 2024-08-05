#include <stdio.h>

int main(){
	
	int i, par=0, x;
	
	
	for(i=1;i<=5;i++){
		scanf("%d", &x);
		
		if(x%2==0)
			par++;
	}	
	
	printf("%d valores pares\n", par);
	
	return 0;
}
