#include <stdio.h>
#include <stdlib.h>
int main() {
  int i, v[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
  int v2[20];
  FILE *arq; // ponteiro para arquivo
  int n = 20;
  // cria��o do arquivo para grava��o e leitura
  arq = fopen ("vetor2.dat", "w+b"); 
  // grava��o do "n" na primeira posi��o do arquivo
  fwrite (&n, sizeof(int), 1, arq);
  // grava��o do vetor todo de uma vez
  fwrite (&v, sizeof(v), 1, arq);
  // retorno do ponteiro para a primeira posi��o do arquivo
  rewind (arq);
  // leitura da primeira posi��o com a quantidade de elementos do vetor
  fread (&n, sizeof(int),1,arq);
  // impress�o da quantidade na tela
  printf ("%d\n",n);
  fread (&v2, sizeof(v), 1, arq);
  // leitura do vetor todo e armazeno em v2
  for (i=0; i<n; i++)
    printf("%d ",v2[i]);
  return 0;
}
