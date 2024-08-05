#include <stdio.h>
#include <math.h>

int main(){
	
	double raio, area;
	
	scanf("%lf", &raio);
	
	area = M_PI * pow(raio,2);
	
	printf("A=%.4lf\n", area);
	
	return 0;
}