#include <stdio.h>

int main(){
	
	float peso, alt, imc;
	
	printf("Insira seu peso: \n ");
	scanf("%f",&peso);
	
	printf("\nInsira sua altura: \n ");
	scanf("%f",&alt);
	
	imc = peso / (alt * alt);
	
	printf("\n O seu IMC eh de: %.2f \n", imc);
	
}
