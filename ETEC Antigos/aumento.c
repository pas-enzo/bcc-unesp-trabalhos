#include <stdio.h>

int main(){
	
	double salario, aumento, novo;
	char por;
	
	scanf("%lf", &salario);
	
	if(salario <= 400){
		aumento = salario * 0.15;
		novo = salario + aumento;
		por = '%';
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", aumento);
		printf("Em percentual: 15%\n", por);
	}
	
	if(salario >= 400.01 && salario <=800){
		aumento = salario * 0.12;
		novo = salario + aumento;
		por = '%';
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", aumento);
		printf("Em percentual: 12%c\n", por);
	}
	
	if(salario >= 800.01 && salario <= 1200){
		aumento = salario * 0.10;
		novo = salario + aumento;
		por = '%';
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", aumento);
		printf("Em percentual: 10%c\n", por);
	}
	
	if(salario >= 1200.01 && salario <= 2000){
		aumento = salario * 0.07;
		novo = salario + aumento;
		por = '%';
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", aumento);
		printf("Em percentual: 7%c\n", por);
	}
	
	if(salario > 2000){
		aumento = salario * 0.04;
		novo = salario + aumento;
		por = '%';
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", aumento);
		printf("Em percentual: 4%c\n", por);
	}
	
	
	return 0;
}
