#include <stdio.h>

int main(){
	
	int i, j, k;
	int x, d, n;
	int tj=0, tm=0;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		
		for(j=0;j<3;j++){
			scanf("%d %d", &x, &d);
			tj+=x*d;
		}
		
		x=0;
		d=0;
		
		for(k=0;k<3;k++){
			scanf("%d %d", &x, &d);
			tm+=x*d;
		}
		
		if(tj>tm)
			printf("JOAO\n");
			
		if(tj<tm)
			printf("MARIA\n");
		
		tj=0;
		tm=0;
		
	}
	
	
	return 0;
}