#include <stdio.h>

int main(){
	
	
	int N[1000];
	int T, i, j;
	
	scanf("%d", &T);
	
	for(i=0;i<=999;i++){
		
		N[i]=i%T;
		
		printf("N[%d] = %d\n", i, N[i]);
	}
	
	
	return 0;
}
