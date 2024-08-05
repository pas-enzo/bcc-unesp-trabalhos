#include <stdio.h>
#include <stdlib.h>
int main () {
  FILE *arq;
  char caracter;
  if ((arq = fopen ("bcc.txt","r")) == NULL) {
    printf("\n Erro de abertura de arquivo");
    exit(1);
   }
  do {
    caracter = getc(arq);
    printf ("%c",caracter);
  } while (caracter != EOF);
}

