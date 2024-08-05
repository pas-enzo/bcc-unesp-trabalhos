#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *arquivo;
  int cont = 0;
  char ch;
  if ((arquivo = fopen ("arquivo.txt","r")) == NULL){
    printf ("\n Arquivo não pode ser aberto.");
   exit (0);
  }
  while ((ch = getc(arquivo)) != EOF)
    cont++;
  fclose (arquivo);
  printf ("\nO arquivo contém %d caracteres.\n",cont);
}

