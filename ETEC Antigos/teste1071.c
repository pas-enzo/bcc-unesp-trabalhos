#include <stdio.h>

int main(){
	
	int x, y, aux;
	
	scanf("%d%d", &x, &y);
	
	if(y>x){
		aux = x;
		x = y;
		y = aux;
	}
	
	printf("x sera: %d\n", x);
	printf("y sera: %d\n", y);
	
	
	
	return 0;
}
