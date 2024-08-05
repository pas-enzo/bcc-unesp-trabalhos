#include <stdio.h>

main() {
	int nivel, hora, salario;
	
	do{
		printf("Informe o nivel: \n");
		scanf("%i", &nivel);
	}
	  while((nivel < 1) || (nivel > 3));
	  
	     printf("Informe a quantidade de horas trabalhadas: \n");
	     scanf("%i", &hora);
	 
    if(nivel == 1) {
    	salario = 12 * hora;
    	
    	printf("Seu salario e %i reais", salario);
	}	 
	
	  else if(nivel == 2) {
	  	       salario = 17 * hora;
	  	       
	  	       printf("Seu salario e %i reais", salario);
	  }
	  
	    else {
	    	       salario = 25 * hora;
	    	       
	    	       printf("Seu salario e %i reais", salario);
	    	    
	    	    
		}
	 
}
