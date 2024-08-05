#include <stdio.h>

int main(){
	
	int wma=0, wjo=0;
	int i, j, n=1, game;
	
	while(scanf("%d", &n)!=0){
		
		wma=0;
		wjo=0;
		
		if(n==0)break;
		
		for(i=0;i<n;i++){
			
			scanf("%d", &game);
			
			if(game==0)wma++;
			
			else if(game==1)wjo++;
		}
			
		
		printf("Mary won %d times and John won %d times\n", wma, wjo);
		
		
	}
	
	return 0;
}