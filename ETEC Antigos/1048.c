#include <stdio.h>

int main(){
	
	double sal, reaj, novo;
	
	scanf("%lf", &sal);
	
	if(sal <= 400){
		reaj = sal*0.15;
		novo = sal+reaj;
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", reaj);
		printf("Em percentual: 15 %%\n");
	}
	
	if(sal > 400 && sal <= 800){
		reaj = sal*0.12;
		novo = sal+reaj;
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", reaj);
		printf("Em percentual: 12 %%\n");
	}
	
	if(sal > 800 && sal <= 1200){
		reaj = sal*0.10;
		novo = sal+reaj;
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", reaj);
		printf("Em percentual: 10 %%\n");
	}
	
	if(sal > 1200 && sal <= 2000){
		reaj = sal*0.07;
		novo = sal+reaj;
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", reaj);
		printf("Em percentual: 7 %%\n");
	}
	
	if(sal > 2000){
		reaj = sal*0.04;
		novo = sal+reaj;
		
		printf("Novo salario: %.2lf\n", novo);
		printf("Reajuste ganho: %.2lf\n", reaj);
		printf("Em percentual: 4 %%\n");
	}
	
	
	return 0;
}
