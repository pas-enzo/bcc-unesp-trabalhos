#include <stdio.h>

int main(){
	
	int N, menor=1000, pos=0;
	int i;
	
	scanf("%d", &N);
	
	int X[N];
	
	for(i=0;i<N;i++){
		scanf("%d", &X[i]);
	}
	
	for(i=0;i<N;i++){
		if(X[i]<menor){
			menor=X[i];
			pos=i;
		}
	}	
	
	printf("Menor valor: %d\n", menor);
	printf("Posicao: %d\n", pos);
	
	return 0;
}