#include <stdio.h>

//Exercicio numero 7 - Enzo Paschoalini - RA 221026215

int main (){
	
	float km, lit, rend;
	
	printf("Insira a quantidade de kilometros rodados: \n");
	scanf("%f",&km);
	
	printf("\nInsira a quantidade de litros consumidos no trajeto: \n");
	scanf("%f",&lit);
	
	rend = lit / km;
	
	printf("\nO rendimento do litro de combustivel por kilometro eh de: \n %.2f l/km", rend);
	
	
}
