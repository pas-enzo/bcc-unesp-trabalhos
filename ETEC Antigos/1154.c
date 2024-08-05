#include<stdio.h>

int main(){
	
	int idade=0, soma=0, cont=0;
	double media;
	
	while(idade>=0){
		scanf("%d", &idade);
		
		if(idade>=0){
		soma += idade;
		cont++;
		}
	
	}
	
	media = (double)soma/cont;
	
	printf("%.2lf\n", media);
	
	return 0;
}
