#include <stdio.h>

main() {
 
  int niv, hor;
  float sal;
  
  printf("Informe o nivel: \n");
  scanf("%i", &niv);
  
  printf("Informe a quantidade de horas trabalhadas: \n");
  scanf("%i", &hor);
  
  if (niv == 1) {
  	  sal = hor * 12;
  }  	
  
   else if (niv == 2) {
   	  sal = hor * 17; 
   }
   
    else {
   	  sal = hor * 25;
   }
   
   printf("Seu salario e: %0.2f \n", sal);
   
}
