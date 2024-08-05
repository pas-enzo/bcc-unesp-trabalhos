#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *arquivo;
  char texto[100];
  int i;
  /* Arquivo ASCII, para escrita */
  arquivo = fopen ("arquivo.txt","w");
  if (!arquivo) {
    printf( "Erro na abertura do arquivo");
    exit(1);
  }
  printf ("Digite uma string a ser gravada no arquivo: \n");
  gets (texto);
  for (i=0; texto[i]; i++)
    putc (texto[i], arquivo);
  fclose(arquivo);
}
