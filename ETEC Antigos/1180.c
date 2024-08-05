#include <stdio.h>

int main(){
	
	int N, i, pos, menor=999;
	
	scanf("%d", &N);
	
	int X[N];
	
	for(i=0;i<N;i++){
		scanf("%d", &X[i]);
		
		if(X[i]<menor){
			menor=X[i];
			pos=i;
		}
			
	}
	
	printf("Menor valor: %d\n", menor);
	printf("Posicao: %d\n", pos);
	
	
	
	return 0;
}
