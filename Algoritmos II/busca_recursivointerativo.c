#include <stdio.h>
#define TRUE 1
#define FALSE 0

int buscavetor(int *vetor, int n, int busca){
	
	if(n==0)return -1;
	
	if(vetor[n-1] == busca)
		return n-1;
		
		return buscavetor(vetor,n-1,busca);
	
}

int main(){
	
	int v[200], item, n;
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d", &v[i]);
	}
	
	printf("Qual o numero que voce gostaria de buscar?\n");
	scanf("%d", &item);
	
	printf("O numero esta na posicao %d - se posicao = -1, nao foi encontrado.", buscavetor(v[200], n, item));
	
	return 0;
}