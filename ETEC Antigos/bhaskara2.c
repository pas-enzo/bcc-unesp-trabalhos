#include <stdio.h>
#include <math.h>

int main(){
	
	double a, b, c, x1, x2, delta;
	
	printf("De os valores de a, b e c, respectivamente: \n");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	if(a == 0){
		printf("Nao eh uma equacao do segundo grau.");
	}
	
	else{
	
	delta = b*b - 4*a*c;
	
	if(delta < 0){
		printf("Nao existem raizes reais. \n");
	}
	
	if(delta == 0){
		x1 = x2;
		
		x1 = (-1)*b / (2*a);
		printf("As raizes sao iguais a %.2lf e %.2lf", x1, x2);
	}
	
	if(delta > 0){
		
		x1 = ((-1)*b + sqrt(delta))/ (2*a);
		x2 = ((-1)*b - sqrt(delta))/ (2*a);
		printf("As raizes sao iguais a %.2lf e %.2lf", x1, x2);
	}
	
}
	
	
	return 0;
}
