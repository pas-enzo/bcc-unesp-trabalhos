#include <stdio.h>

int main(){
	
	double A[10];
	int i;
	
	for(i=0;i<=9;i++){
		scanf("%lf", &A[i]);
	}
	
	for(i=0;i<=9;i++){
		if(A[i]<=10){
			printf("A[%d] = %.1lf\n", i, A[i]);
		}
	}
	

	return 0;
}
