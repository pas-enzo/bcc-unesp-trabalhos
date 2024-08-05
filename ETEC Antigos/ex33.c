#include <stdio.h>

int main(){
	
	float salario, imp;
	
	printf("Informe seu salario: \n");
	scanf("%f", &salario);
	
	imp = salario * 0.05;
	
	printf("Seu imposto de renda sera de: %.2f\n", imp);
}
