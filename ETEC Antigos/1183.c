#include <stdio.h>
#define lim 12

int main(){
	
	double M[lim][lim], soma, media;
	int i, j, n=11;
	char op;
	
	do{
		scanf(" %c", &op);
	}while(op!='S'&&op!='M');
	
	for(i=0;i<lim;i++){
		for(j=0;j<lim;j++){
			scanf("%lf", &M[i][j]);
		}
	}
	
	if(op=='S'){
		
	   for(i=0;i<lim;i++){
			for(j=0;j<n;j++){
				soma+=M[i][j];
				n--;
		}
	}
		
		printf("%.1lf\n", soma);
	}
	
	if(op=='M'){
		for(i=0;i<lim;i++){
			for(j=0;j<n;j++){
				soma+=M[i][j];
				n--;
		}
	}
		
		media=soma/66;
		
		printf("%.1lf\n", media);
	}
	
	
	return 0;
}
