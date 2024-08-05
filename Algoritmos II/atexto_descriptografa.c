#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

int main(){

	FILE *arquivo;
	char nomarq[11], padrao[MAX+2], cripto[MAX+1], caracterep, caracterec;
	int i;
	
	printf("Digite o nome do arquivo: ");
	gets(nomarq);
	
	if((arquivo=fopen(nomarq,"r+t"))==NULL){
		printf("Erro na abertura de arquivo.\n");
		exit(1);
	}
	
	for(i=0;!feof(arquivo);i++){
		cripto[i]=getc(arquivo);
		padrao[i]=cripto[i]-15;
		
		printf("%c", &padrao[i]);
	}
	
	/*while(!feof(arquivo)){
		caracterec=fget
	}*/
	
	fclose(arquivo);
	
	return 0;
}