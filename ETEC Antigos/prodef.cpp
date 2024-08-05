#include <stdio.h>



main() {
	
	float prod, prodef;
	
	printf("Informe o total de producao: ");
	scanf("%f", &prod);
	
	printf("Informe o total de pecas defeituosas: ");
	scanf("%f", &prodef);
	
	if (prodef > prod * 0.1) {
	
		
		printf("Maquina necessita de manutencao!");
	}
	
	else {
		printf("Maquina nao necessita de manutencao.");
	}
	
}
