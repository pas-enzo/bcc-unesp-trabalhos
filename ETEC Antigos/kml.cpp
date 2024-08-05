#include <stdio.h>

int main(){
	
	int X;
	double Y, kml;
	
	scanf("%i%lf", &X, &Y);
	
	kml = X / Y;
	
	printf("%.3lf km/l\n", kml);
	
	return 0;
}
