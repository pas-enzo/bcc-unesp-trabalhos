#include <stdio.h>
#define MAX 1000

int main(){
	
	int vetor[MAX], troca;
	int i, j, k, temp, n;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &vetor[i]);
	}
	
	printf("\n\nVetor digitado: ");
	
	for(i=0;i<n;i++){
		printf("%d ", vetor[i]);
	}
	
	//bubble sort    variavel troca => descontinua se tiver ordenado
	for(i=0;i<n-1 && troca;i++){
		troca=0;
		for(j=0;j<n-i-1;j++){
			if(vetor[j]>vetor[j+1]){
				troca=1
				temp=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=temp;
			}	
		}
	}
	
	printf("\n\nVetor ordenado (bubble): ");
	
	for(i=0;i<n;i++){
		printf("%d ", vetor[i]);
	}
	
	
	return 0;
}