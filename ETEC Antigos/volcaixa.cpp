#include <stdio.h>

main(){

  float vol, l, w, h;
  
  printf("Informe o valor do comprimento: \n");
  scanf("%f", &l);
  
  printf("Informe o valor da largura: \n");
  scanf("%f", &w);
  
  printf("Informe o valor da altura: \n");
  scanf("%f", &h);
  
  vol = l * w * h;
  
  printf("O volume da caixa e: %f", vol);
  
} 
