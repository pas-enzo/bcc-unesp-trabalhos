#include <stdio.h>
#include <math.h>

int main(){
	
	int A, B, C, maior, maiorBIG;
	
	scanf("%i%i%i", &A, &B, &C);
	
	maior = (A + B + abs(A-B)) / 2;
	maiorBIG = (maior + C + abs(maior-C)) / 2;
	
	printf("%i eh o maior", maiorBIG);
	
	return 0; 
}
