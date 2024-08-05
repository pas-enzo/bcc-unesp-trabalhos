#include <stdio.h>

int main(){
	
	int N; 
	
	scanf("%d", &N);
	
	printf("%d\n", N);
	
	printf("%d nota(s) de R$ 100,00\n", (int)N / 100);
	N = N % 100;
	printf("%d nota(s) de R$ 50,00\n", (int)N / 50);
	N = N % 50;
	printf("%d nota(s) de R$ 20,00\n", (int)N / 20);
	N = N % 20;
	printf("%d nota(s) de R$ 10,00\n", (int)N / 10);
	N = N % 10;
	printf("%d nota(s) de R$ 5,00\n", (int)N / 5);
	N = N % 5;
	printf("%d nota(s) de R$ 2,00\n", (int)N / 2);
	N = N % 2;
	printf("%d nota(s) de R$ 1,00\n", (int)N / 1);
	N = N % 1;
	
	

	return 0;
}
