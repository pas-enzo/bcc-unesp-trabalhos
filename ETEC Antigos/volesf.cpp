#include <stdio.h>
#include <math.h>

int main(){
	
	double vol, R, pi = 3.14159;
	
	scanf("%lf", &R);
	
	vol = (4.0/3) * pi * pow(R,3);
	
	printf("VOLUME = %.lf\n", vol);
	
	
	return 0;
}
