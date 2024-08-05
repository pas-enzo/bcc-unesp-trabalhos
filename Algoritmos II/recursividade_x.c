#include <stdio.h>

int x (int n){
 if (n == 0)
 return 0;
 if (n == 1)
 return 1;
 if (n == 2)
 return 2;
 return x(n-1) + x(n-2) + x(n-3);
}

int main(){
	
	int num;
	
	
	scanf("%d", &num);
	
	printf("%d", x(num));
		
}