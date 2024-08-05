#include <stdio.h>

int main(){
	
	int dias, anos, meses, moddias, aux1, aux2;
	
	scanf("%i", &dias);
	
	anos = dias / 365;
	aux1 = dias % 365;
	
	meses = aux1 / 30;
	aux2 = aux1 % 30;
	
	moddias = aux2;
	
	printf("%i ano(s)\n", anos);
	printf("%i mes(es)\n", meses);
	printf("%i dia(s)\n", moddias);
	
	return 0;
	
}
	
