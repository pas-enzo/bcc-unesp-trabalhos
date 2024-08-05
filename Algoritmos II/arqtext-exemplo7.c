#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  FILE *arquivo;
  char texto[81];
  if ((arquivo = fopen("teste.txt","w")) == NULL){
    printf ("\n Arquivo não pode ser aberto");
    exit(1);
  }
  while (strlen(gets(texto))>0) {
    fputs (texto,arquivo); // grava
    putc ('\n',arquivo); // grava caractere de mudança de linha
  }
  fclose (arquivo);
}
