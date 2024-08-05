#include <stdio.h>
#include <stdlib.h>
int main() {
  struct LIVROS {
      char titulo[30];
      int regnum;
      double preco;
  } livro;
  FILE *arquivo;
  if ((arquivo = fopen("livros.dat", "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo");
    exit(1);
  }
  while (fread (&livro, sizeof(livro), 1, arquivo) == 1) {
    printf ("\n Titulo: %s ", livro.titulo);
    printf ("\n Registro: %d", livro.regnum);
    printf ("\n Preco: %.2f\n",livro.preco);
  }
  fclose (arquivo);
  return 0;
}
