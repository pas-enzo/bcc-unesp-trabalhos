#include <stdio.h>
#include <stdlib.h>
int main() {
  int i, j, m[4][5] = {{0,1,2,3,4},
                       {5,6,7,8,9},
                       {10,11,12,13,14},
                       {15,16,17,18,19}};
  int m2[4][5];
  FILE *arq; // ponteiro para arquivo
  int l = 4;
  int c = 5;
  // cria��o do arquivo para grava��o e leitura
  arq = fopen ("matriz.dat", "w+b"); 
  // grava��o de l na primeira posi��o do arquivo
  fwrite (&l, sizeof(int), 1, arq); 
  // grava��o de c na segunda posi��o do arquivo
  fwrite (&c, sizeof(int), 1, arq);
  // grava��o da matriz toda de uma vez
  fwrite (m, sizeof(m), 1, arq);
  // retorno do ponteiro para a primeira posi��o do arquivo
  rewind (arq); 
  // leitura de "l" da primeira posi��o do arquivo
  fread (&l, sizeof(int), 1, arq); 
  // leitura de "c" da segunda posi��o do arquivo
  fread (&c,sizeof(int),1,arq); 
  // impress�o do cabe�alho da matriz na tela
  printf ("Matriz m[%d][%d] =\n",l,c); 
  // leitura da matriz toda e armazeno em m2
  fread (m2, sizeof(m), 1, arq); 
  for (i=0; i<l; i++) {
    for (j=0;j<c;j++)
      printf("%3d ",m2[i][j]); //imprime cada posi��o de m2 na tela
      printf("\n");
  }
  return 0;
}
