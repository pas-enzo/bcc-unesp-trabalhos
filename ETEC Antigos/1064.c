#include <stdio.h>

int main(){
	
	int i, pos=0;
	double soma=0, media, x;
	
	
	for(i=1;i<=6;i++){
		scanf("%lf", &x);
		
		if(x>0){
			pos++;
			soma = soma + x;
		}
	}
	
	media = soma / pos;
	
	printf("%d valores positivos\n", pos);
	printf("%.1lf\n", media);
	
	return 0;
}
