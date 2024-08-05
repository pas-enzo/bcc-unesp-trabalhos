#include <stdio.h>
#define size 100

int main(){
	
	int vet[size];
	int dist[size], pos[size];
	int p, s, i=0;
	int posic=0;
	
	scanf("%d%d", &p, &s);
	
	for(i=1;i<=p;i++){
		vet[i]=0;
	}
	
	for(i=1;i<=s;i++){
		scanf("%d%d", &pos[i], &dist[i]);
	}
	
	for(i=1;i<=s;i++){
		posic=pos[i];
		vet[posic]=1;
	
	do{
		
		if(posic<=p && posic>0){
			vet[posic]=1;
		}
		
		posic+=dist[i];
		
	}while(posic<=p && posic>0);
	
}
	for(i=1;i<=s;i++){
		posic=pos[i];
		vet[posic]=1;
	
		do{
			if(posic<=p && posic>0){
			vet[posic]=1;
		}
		
		posic-=dist[i];	
	
		}while(posic<=p && posic > 0);
	}
	
	
	
	for(i=1;i<=p;i++){
		printf("%d\n", vet[i]);
	}
	
	return 0;
}
