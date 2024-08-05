#include <stdio.h>

main () {
	
	int cod, sal; 
	float aum;
	
	printf("Informe o codigo do cargo: \n");
	scanf("%i", &cod);
	
	printf("Informe o salario atual: \n");
	scanf("%i", &sal);
	
	 if (cod == 1) {
	 	aum = sal * 1.1;
	 }
	 
	  else if (cod == 2) {
	  	aum = sal * 1.2;
	  }
	  
	   else {
	   	aum = sal * 1.3;
	   }
	   
	printf("O salario novo sera de R$: %0.2f \n", aum);
	
}
