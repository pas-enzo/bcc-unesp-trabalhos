#include <stdio.h>
#include <stdlib.h>
int main () {
  int i, v[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
  int v2[20]; 
  FILE *arq; //ponteiro para arquivo
  int n = 20;

  // Gravação do arquivo
  //criação do arquivo para gravação
  arq = fopen ("vetor.dat", "wb"); 
  //gravação de "n" na 1ª posição do arquivo
  fwrite (&n, sizeof(int), 1, arq);
  //gravação do vetor 
  fwrite (v, sizeof(int), n, arq); 
  //fechamento do arquivo
  fclose (arq); 

  // Leitura do arquivo 
  // abertura novamente do arquivo para leitura
  arq = fopen ("vetor.dat", "rb");
  // leitura da 1ª posição que contem a quantidade de elementos do vetor
  fread (&n,sizeof(int),1,arq); 
  // impressão da quantidade na tela
  printf ("%d\n",n);
  // leitura de cada posição do vetor e armazeno em v2 na tela
  fread (v2,sizeof(int),n,arq); 
  // impressão de cada posição de v2
  for (i=0; i<n; i++)
    printf("%d ",v2[i]); 
  //fechamento do arquivo    
  fclose (arq);
  return 0;
}
