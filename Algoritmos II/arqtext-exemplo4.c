#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *arquivo;
  int cont = 0;
  char ch;
  if ((arquivo = fopen ("arquivo.txt","r")) == NULL){
    printf ("\n Arquivo n�o pode ser aberto.");
   exit (0);
  }
  while ((ch = getc(arquivo)) != EOF)
    cont++;
  fclose (arquivo);
  printf ("\nO arquivo cont�m %d caracteres.\n",cont);
}

