#include <stdio.h>
#include <math.h>

int main(){
	
	float ang, senang, cosang, tanang;
	
	printf("Insira o valor do angulo: \n");
	scanf("%f", &ang);
	
	senang = sin(ang);
	
	cosang = cos(ang);
	
	tanang = tan(ang);
	
	printf("O seno de %.2f sera de: %.2f \n", ang, senang);
	printf("O cosseno de %.2f sera de: %.2f \n", ang, cosang);
	printf("A tangente de %.2f sera de: %.2f \n", ang, tanang);
	
	
	
	
	return 0;
}
