#include <stdio.h>
#define MAX 101

int main(){
	
	int v[MAX], n, i, j, aux_m;
	    
	    
	printf("De o tamanho do vetor: ");
	scanf("%d", &n);
	
	printf("Digite o vetor: \n");
	for(i=0;i<n;i++){
		scanf("%d", &v[i]);
	}
	
	for(i=1;i<n;i++){
		
		aux_m = v[i];
		j = i-1;
		
		while(j>=0 && v[j]>aux_m){
			v[j+1]=v[j];
			j--;
		}
		
		v[j+1] = aux_m;
		
	}
	
	for(i=0;i<n;i++){
		printf("%d ", v[i]);
	}
	
}