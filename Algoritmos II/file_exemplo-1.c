#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

struct LIVROS {
       char titulo[30];
       int regnum;
       double preco;
};

int main() {
  struct LIVROS livro;
  char numstr[81], resp;
  FILE *arquivo;
  if ((arquivo = fopen("livros.dat", "wb")) == NULL) {
     printf("\n Erro de abertura de arquivo");
     exit(1); 
  }
  do {
     printf("\n\n Titulo: ");
     gets(livro.titulo);
     printf("\n Registro: ");
     gets(numstr);
     livro.regnum = atoi(numstr);
     printf("\n Preco: ");
     gets(numstr);
     livro.preco = atof(numstr);
     // obs: sizeof retorna o tamanho da estrutura livro
     fwrite(&livro, sizeof(livro), 1, arquivo);
     printf("\n Adicionar outro livro (s/n)?: ");
     do {
         resp = toupper(getch());
     } while (resp != 'S' && resp != 'N');
  } while (resp == 'S');
  fclose (arquivo);
  return 0;
}
