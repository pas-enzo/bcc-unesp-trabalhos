#include <stdio.h>
 
int main() {
 
	int N, i;
	float a, b, c, media;
	
	scanf("%d", &N);
	
		for(i=1;i<=N;i++){
			
			scanf("%f%f%f", &a, &b, &c);
			media = ((a*2) + (b*3) + (c*5)) / 10;
			printf("%.1f\n", media);
			
		}
 
    return 0;
}
