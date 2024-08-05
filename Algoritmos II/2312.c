#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	char nome[41];
	int gol, sil, bro;
	
} pais;

int compara (const void *p1,const void *p2) {
 
	pais *i=(pais *)p1,*j=(pais *)p2;

	if(i->gol > j->gol){
		return -1;
	}
	
	else if (i->gol < j->gol) {
			return 1;
 		}
	
	else {
		if (i->sil > j->sil) {
   			return -1;
		}

	else 
		if(i->sil < j->sil){
   			return 1;
  		}		
	
	else {
		if (i->bro > j->bro) {
			return -1;
   		}
	
	else 
		if (i->bro < j->bro) {
    		return 1;
   		}
   
   else	{
    return strcmp(i->nome,j->nome);
   }
   
  }
  
 }
 
}

int main (int argc, char *argv[]) {
	
	int n, x;
	
	scanf("%d",&n);

	pais p[n];
	
	for (x=0; x<n; x++){
		scanf(" %s %d %d %d", p[x].nome, &p[x].gol, &p[x].sil, &p[x].bro);
 	}
 	
	qsort(p,n,sizeof(p[0]),compara);
	
	for (x=0; x<n; x++) {
		printf("%s %d %d %d\n", p[x].nome, p[x].gol, p[x].sil, p[x].bro);
 	}

	return 0;
	
}