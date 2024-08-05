#include <stdio.h>

int main(){
	
	int a, b, quo1, quo2;
	float quo3;
	
	scanf("%d%d", &a, &b);
	
	quo1 = (int)a / (int)b;
	quo2 = (int)b / (int)a;
	quo3 = (float)b / a;
	
	printf("A soma de %d e %d sera de: %d\n", a, b, a+b);
	printf("A diferenca entre %d e %d sera de: %d\n", a, b, a-b);
	printf("O produto entre %d e %d sera de: %d\n", a, b, a*b);
	printf("O quociente entre %d e %d sera de: %d\n", a, b, a/b);
	printf("O quociente entre %d e %d sera de: %.2f\n", b, a, quo3);
	printf("O quociente inteiro entre %d e %d sera de: %d\n", a, b, quo1);
	printf("O quociente inteiro entre %d e %d sera de: %d\n", b, a, quo2);
	printf("O resto da divisao entre %d e %d sera de: %d\n", a, b, a%b);
	printf("O resto da divisao entre %d e %d sera de: %d\n", b, a, b%a);
	
}
