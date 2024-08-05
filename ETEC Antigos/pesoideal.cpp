#include <stdio.h>

main() {
	
	int codsexo;
	float altura, pesoideal;
	
	printf("Informe o sexo; 1 para masculino e 2 para feminino: \n");
	scanf("%i", &codsexo);
	
	printf("Informe a altura, em metros: \n");
	scanf("%f", &altura);
	
	if (codsexo == 1) {
		pesoideal = (72.7 * altura) - 58;
		
		    printf("Seu peso ideal e, em kilos: %0.2f", pesoideal);
	}
	     else if (codsexo == 2) {
	     	pesoideal = (62.1 * altura) - 44.7;
			 
			    printf("Seu peso ideal e, em kilos: %0.2f", pesoideal);
		 }
		 
		    else {
		    	
		    	printf("Codigo de sexo nao reconhecido/invalido.");
			}
	
}
