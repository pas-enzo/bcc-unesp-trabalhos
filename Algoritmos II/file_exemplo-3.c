#include <stdio.h>
#include <stdlib.h>
int main () {
  int i, v[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
  int v2[20]; 
  FILE *arq; //ponteiro para arquivo
  int n = 20;

  // Grava��o do arquivo
  //cria��o do arquivo para grava��o
  arq = fopen ("vetor.dat", "wb"); 
  //grava��o de "n" na 1� posi��o do arquivo
  fwrite (&n, sizeof(int), 1, arq);
  //grava��o do vetor 
  fwrite (v, sizeof(int), n, arq); 
  //fechamento do arquivo
  fclose (arq); 

  // Leitura do arquivo 
  // abertura novamente do arquivo para leitura
  arq = fopen ("vetor.dat", "rb");
  // leitura da 1� posi��o que contem a quantidade de elementos do vetor
  fread (&n,sizeof(int),1,arq); 
  // impress�o da quantidade na tela
  printf ("%d\n",n);
  // leitura de cada posi��o do vetor e armazeno em v2 na tela
  fread (v2,sizeof(int),n,arq); 
  // impress�o de cada posi��o de v2
  for (i=0; i<n; i++)
    printf("%d ",v2[i]); 
  //fechamento do arquivo    
  fclose (arq);
  return 0;
}
