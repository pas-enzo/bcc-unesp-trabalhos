#include <stdio.h>
#include <stdlib.h>
int main () {
  FILE *arq;
  char caracter;
  if ((arq = fopen ("arquivo.txt","r")) == NULL) {
    printf("\n Erro de abertura de arquivo");
    exit(1);
  }
  while (!feof(arq)) {
    caracter = getc(arq);
    printf ("%c",caracter);
  };
}

