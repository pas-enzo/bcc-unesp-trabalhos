#include <stdio.h>

int main(){
	
	int temp, velo, distancia;
	double litros;
	
	scanf("%i%i", &temp, &velo);
	
	distancia = temp * velo;
	
	litros = (double)distancia / 12;
	
	printf("%.3lf\n", litros);

	return 0;
	
}
