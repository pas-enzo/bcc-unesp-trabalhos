#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

/*typedef struct{
	char padrao[MAX];
	char cripto[MAX+1];
}texto;*/

int main(){
	
	FILE *arquivo;
	//texto na_main;
	char nomarq[11], padrao[MAX], cripto[MAX+1];
	int i;
	
	printf("Digite o nome do arquivo: \n");
	gets(nomarq);
	
	if((arquivo=fopen(nomarq,"wt"))==NULL){
		printf("Erro na abertura de arquivo.\n");
		exit(1);
	}
	
	fflush(stdin);
	
	printf("Digite o texto a ser criptografado: \n");
	gets(padrao);
	
	for(i=0;i<strlen(padrao);i++){
		cripto[i]=padrao[i]+15;
	}
	
	fwrite(&cripto, sizeof(cripto), 1, arquivo);
	
	return 0;
	
}