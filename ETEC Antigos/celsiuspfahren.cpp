#include <stdio.h> 

//Exercicio numero 9 - Enzo Paschoalini - RA 221026215

int main(){
	
	float cel, fahren;
	
	printf("Insira a temperatura em graus celsius: \n");
	scanf("%f",&cel);
	
	fahren = ((cel * 9) / 5) + 32;
	
	printf("\nA temperatura equivalente em graus fahrenheit eh de: \n %.2f graus", fahren);

}
