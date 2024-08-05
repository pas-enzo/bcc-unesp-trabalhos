#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

int main (){
	
	FILE *arquivo;
	char escrita[100], caracter;
	int i, cont=0, conso=0;;
	
	arquivo = fopen ("arquivo.txt","w");
	if (!arquivo) {
    printf( "Erro na abertura do arquivo");
    exit(1);
  }
  	printf ("Digite uma string a ser gravada no arquivo: \n");
	gets (escrita);
  for (i=0; escrita[i]; i++){
  	putc (escrita[i], arquivo);
  	if(escrita[i]=='A' || escrita[i]=='a' || escrita[i]=='E' || escrita[i]=='e' || escrita[i]=='I' || escrita[i]=='i' || escrita[i]=='O' || escrita[i]=='o' || escrita[i]=='U' ||  escrita[i]=='u')cont++;
  }
  fclose(arquivo);
  
  printf("\n\n");
  
  fflush(arquivo);
  
	if(arquivo = fopen("arquivo.txt", "r") == NULL){
  	printf( "Erro na abertura do arquivo");
    	exit(1);
	}
	
	fflush(stdin);
	
	for(i=0; escrita[i]; i++)
		printf("%c", toupper(escrita[i]));
	
	printf("\n\nA quantidade de vogais de arquivo.txt e %d", cont);
	
	fclose(arquivo);
	
}