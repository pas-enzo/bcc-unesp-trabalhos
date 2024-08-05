#include <stdio.h>

int main(){
	
	
	double N[100], temp, ant, X;
	int i=1, start=0;
	
	
	scanf("%lf", &X);
	
	N[0]=X;
	
	ant=N[0];
	
	printf("N[%d] = %.4lf\n", start, N[0]);
	
	for(i=1;i<=99;i++){
		temp=ant;
		
		N[i]=temp/2;
		printf("N[%d] = %.4lf\n", i, N[i]);
		
		ant = N[i];
	}
	
	return 0;
}
