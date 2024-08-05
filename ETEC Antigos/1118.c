#include <stdio.h>


int main(){
	
	double grade1=-1, grade2=-1;
	int cond=1, rep;
	double media=0;
	
	while(cond==1){
		
		while(grade1<0 || grade1>10){
			
			scanf("%lf", &grade1);
			
			if(grade1<0 || grade1>10)
				printf("nota invalida\n");			
		}
		
		while(grade2<0 || grade2>10){
			
			scanf("%lf", &grade2);
			
			if(grade2<0 || grade2>10)
				printf("nota invalida\n");				
		}
		
		media=(grade1+grade2)/2;
		
		printf("media = %.2lf\n", media);
		
		do{
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &rep);
			
		}while(rep!=1 && rep!=2);
		
			if(rep==2){
				cond=rep;
			}
		
		
		grade1=-1;
		grade2=-1;
		
	}
	return 0;
}
