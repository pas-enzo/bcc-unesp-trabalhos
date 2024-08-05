#include <stdio.h>

int main(){
	
	int x, y, i=1, n;
	float quo;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		
		scanf("%d%d", &x, &y);
		
		quo = (float)x/y;
		
		if(y==0)
			printf("divisao impossivel\n");
			
		else{
			printf("%.1f\n", quo);
		}
		
	}
	
	return 0;
}
