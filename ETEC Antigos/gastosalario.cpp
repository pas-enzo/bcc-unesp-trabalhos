#include <stdio.h>

main() {
	
	float salario, gasto;
	
	printf("Informe o valor do salario: \n");
	scanf("%f", &salario);
	
    printf("Informe o total gasto: \n");
    scanf("%f", &gasto);
    
    if (salario >= gasto) {
    	printf("Gastos dentro do orcamento.");
	}
	  
	  else {
	printf("Orcamento estourado.");
	  }
}
