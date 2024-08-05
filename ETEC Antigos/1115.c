#include <stdio.h>

int main(){
	
	int x=1, y=1;
	
	while(x!=0 && y!=0){
		
		scanf("%d%d", &x, &y);
		
		if(x>0 && y>0)
			printf("primeiro\n");
			
		if(x<0 && y>0)
			printf("segundo\n");
			
		if(x<0 && y<0)
			printf("terceiro\n");
			
		if(x>0 && y<0)
			printf("quarto\n");
		
	}
	
	
	return 0;
}
