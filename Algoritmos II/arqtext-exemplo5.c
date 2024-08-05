#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *original,*copia;
  char caracter, nome[13], nome_novo[13];
  printf("\nDigite o nome do arquivo: ");
  gets (nome);
  printf("\nDigite o nome do arquivo copia: ");
  gets (nome_novo);
  if ((original = fopen(nome,"r")) == NULL){
    printf("\nErro ao abrir o arquivo original.\n\n");
    exit(1);
  }
  if ((copia = fopen(nome_novo,"w")) == NULL){
    printf("\nErro ao abrir o arquivo cópia.\n\n");
    exit(1);
  }
  while(!feof(original)){
    caracter = getc (original);
    if (!feof(original))
      putc (caracter,copia);
  }
  fclose(original);
  fclose(copia);
  printf("\n%s copiado com sucesso com o nome de %s.\n\n",nome,nome_novo);
}
