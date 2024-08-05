#include <stdio.h>

int main(){
	
	int x, i;
	
	scanf("%d", &x);
	
	if(x>=1 && x<=1000){
	
	for(i=1;i<=x;i++){
		
		if(i%2!=0){
			printf("%d\n", i);
		}
		
	}
}
else
	return 0;
}
