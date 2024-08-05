#include <stdio.h>

int perfeito (int numero){
	int soma=0;
	int i;
	for(i=1;i<numero;i++)
		if(numero%i==0)
			soma+=i;
	if(soma==numero) return 1;
	else return 0;
}

int main(){
		
	int n, i, x;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		
		scanf("%d", &x);
		
		if(perfeito(x)==1)
			printf("%d eh perfeito\n", x);
			
		else printf("%d nao eh perfeito\n", x);	
	}
	
	return 0;
}
