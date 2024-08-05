#include <stdio.h>

main() {
	
	float codigo, salario, novo;
	
	do{
		printf("Informe o codigo do cargo: \n");
		scanf("%f", &codigo);
	}
	
	while((codigo < 1) || (codigo > 3));
	 
	  printf("Informe o salario: ");
	  scanf("%f", &salario);
	  
	  if(codigo == 1) {
	  	novo = salario * 1.1;
	  	
	  	printf("\nO novo salario e de %0.2f reais.", novo);
	  }
	  
	    else if(codigo == 2) {
	    novo = salario * 1.2;
	    	   
    	printf("\nO novo salario e de %0.2f reais.", novo);
	    	   }
	    	   
	      else {
	      	novo = salario * 1.3;
	      	
	      	printf("\nO novo salario e de %0.2f reais.", novo); 
			  
	} 
}
