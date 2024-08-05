#include <stdio.h>

main() {
	int numa, numb;
	
	printf("Informe o valor do primeiro numero: \n");
	scanf("%i", &numa);
	
	printf("Informe o valor do segundo numero: \n");
	scanf("%i", &numb);
	
	if (numa == numb) {
		printf("Os numeros sao iguais.");	}
		
		else {
			printf("Os numeros sao diferentes.");
		}
}
