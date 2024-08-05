#include <stdio.h>

int main () {
	
	int numero = 0;  			// Numero que o usuario vai digitar
	int contador = 0; 			// Contador que sera usado para controlar o loop for();
	
	printf("Seu numero aqui: ");
	scanf("%d", &numero); 		// Recebe o numero digitado pelo usuario
	
	/* O loop for sera feito da seguinte maneira:
		Como voce precisa imprimir o valor 1 inicialmente, 
		inicia-se o valor do contador no loop como 1. O final da
		repeticao e' o numero que o usuario digitou, entao o for deve
		executar enquanto o contador for MENOR ou IGUAL ao numero, incrementando
		de 1 em um conforme descrito abaixo. Para cada iteracao, imprime-se o valor
		atual da variavel "contador", solucionando o problema. */
	for(contador=1; contador<=numero; contador++) { 
		printf("%d \n", contador);
	}	
	
	return 0;
	
}