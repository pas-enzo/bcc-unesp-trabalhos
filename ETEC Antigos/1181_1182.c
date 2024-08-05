#include <stdio.h>
#define lim 4

int main(){
	
	double M[lim][lim], soma, media;
	int i, j, L;
	char op;
	
	for(i=0;i<lim;i++){
		for(j=0;j<lim;j++){
			scanf("%lf", &M[i][j]);
		}
	}
	
	for(i=0;i<lim;i++){
		for(j=0;j<lim;j++){
			printf("%.1lf\t", M[i][j]);
		}
		printf("\n\n");
	}
	
	do{
		printf("Selecione a linha da operacao: \n");
		scanf("%d", &L);
	}while(L<1||L>lim);
	
	do{
		printf("Selecione o tipo de operacao a ser realizada: \n");
		scanf(" %c", &op);
	}while(op!='S'&&op!='s'&&op!='M'&&op!='m');
	
	if(op=='S'||op=='s'){
		for(j=0;j<lim;j++){
			soma+=M[L][j];
		}
		
		printf("%.1lf\n", soma);
	}
	
	if(op=='M'||op=='m'){
		for(j=0;j<lim;j++){
			soma+=M[L][j];
		}
		
		media=soma/lim;
		
		printf("%.1lf\n", media);
	}
	
	
	return 0;
}
