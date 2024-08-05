#include<stdio.h>

main(){
	float bme, bma, alt;
	
	printf("\n Informe o valor da base menor, em metros: ");
	scanf("%f",&bme);
	
	printf("\n Informe o valor da base maior, em metros: ");
	scanf("%f",&bma);
	
	printf("\n Informe o valor da altura, em metros: ");
	scanf("%f",&alt);
	
	float area;
	
	area = ((bme + bma) * alt) / 2;
	
	printf("\n A area do trapezio eh, em metros: %f", area);

}
