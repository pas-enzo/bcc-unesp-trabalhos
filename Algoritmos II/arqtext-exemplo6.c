#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *arquivo;
  char texto[81];
  if ((arquivo = fopen("arquivo.txt","r")) == NULL){
    printf ("\n Arquivo não pode ser aberto");
    exit(1);
  }
  while (fgets(texto,80,arquivo) != NULL)
    printf ("%s", texto);
  fclose (arquivo);
}
