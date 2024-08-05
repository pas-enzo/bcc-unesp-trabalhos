#include <stdio.h>
#include <math.h>

int main(){
	
	int p, q, r, resu;
	
	scanf("%i%i%i", &p, &q, &r);
	
	resu = sqrt(exp(p* log(q-1))) + p * r; 
	
	printf("Resu = %i", resu);
	
	
	return 0;
}
