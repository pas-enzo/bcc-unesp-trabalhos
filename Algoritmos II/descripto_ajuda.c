#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


int main () {
	FILE *arquivo;
	char caracter;
	int i;
  
    
	if ((arquivo = fopen( "ajudacrpfin.txt", "rt")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
     exit(1);
  }

	//ler arquivo
	for (i=0; i<=808 ; i++){
	
	if(i==64 || i==132 || i==205 || i==265 || i==266 || i==294 || i==324 || i==377 || i==448 || i==499 || i==541 || i==565 || i==566 || i==616 || i==679
	|| i==723 || i==724)
		printf("\n");
	
	caracter = getc(arquivo);
	fflush(stdin);
    printf("%c", caracter-2);
}
  
  fclose(arquivo);
}