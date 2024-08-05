#include <stdio.h>


int main(){
	
	char nome[30], sexo[30];
	int n, contm=0, contf=0, i;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		fflush(stdin);
		scanf(" %s %s", nome, sexo);
		
		if(sexo[0]=='F')
			contf++;
			
		if(sexo[0]=='M')
			contm++;
	}
	
	printf("%d carrinhos\n", contm);
	printf("%d bonecas\n", contf);
	
	
	return 0;
}