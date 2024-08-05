#include <stdio.h>

int main(){
	
	int i, par=0, pos=0, neg=0, imp=0, x;
	
	
	for(i=1;i<=5;i++){
		scanf("%d", &x);
		
		if(x%2==0)
			par++;
			
		if(x%2!=0)
			imp++;
			
		if(x>0)
			pos++;
			
		if(x<0)
			neg++;
	}	
	
	printf("%d valor(es) par(es)\n", par);
	printf("%d valor(es) impar(es)\n", imp);
	printf("%d valor(es) positivo(s)\n", pos);
	printf("%d valor(es) negativo(s)\n", neg);
	
	return 0;
}
