#include <stdio.h>

main() {
	int cont;
	float media, nota, soma=0;
	
	for(cont=1; cont<=4; cont++) {
		
		printf("Informe o valor da media %i: \n", cont);
		scanf("%f", &nota);
		
		soma = soma + nota;
	}
	
	media = soma / 4;
	
	if(media >= 6) {
		printf("\nSua media e %0.2f, aprovado.", media);
	}
	  
	  else if(media < 5) {
	  	       printf("\nSua media e %0.2f, reprovado.", media);
	  }
	    
	     else {
	    	      printf("\nSua media e %0.2f, recuperacao.", media);
		}
}
