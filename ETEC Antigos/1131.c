#include <stdio.h>

	
int main(){
	
	int interg=0, gremg=0, wi=0, wg=0;
	int valid=0, emp=0, partidas=0;
	
	do{
		scanf("%d %d", &interg, &gremg);
		
		if(interg>gremg)
			wi++;
			
		if(interg<gremg)
			wg++;
			
		if(interg==gremg)
			emp++;
			
		partidas++;
		
		interg=0;
		gremg=0;
			
		
		printf("Novo grenal (1-sim 2-nao)\n");
		scanf("%d", &valid);
		
		if(valid==2)
			break;	
	
	}while(valid==1);
	
	printf("%d grenais\n", partidas);
	printf("Inter:%d\n", wi);
	printf("Gremio:%d\n", wg);
	
	if(wi>wg){
		printf("Inter venceu mais\n");
	}
	
	if(wi<wg){
		printf("Inter venceu mais\n");
	}
	
	if(wi==wg){
		printf("Nao houve vencedor\n");
	}

	return 0;
}
