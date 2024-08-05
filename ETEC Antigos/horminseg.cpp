#include <stdio.h>

//Exercicio numero 5 - Enzo Paschoalini - RA 221026215

int main(){
	
	int hor, min, seg, total;
	
	printf("Insira a quantidade de horas: \n");
	scanf("%i",&hor);
	
	printf("\nInsira a quantidade de minutos: \n");
	scanf("%i",&min);
	
	printf("\nInsira a quantidade de segundos: \n");
	scanf("%i",&seg);
	
	total = ((hor * 60) * 60) + (min * 60) + seg;
	
	printf("\nA quantidade total de segundos eh de: %i", total);
	
}
