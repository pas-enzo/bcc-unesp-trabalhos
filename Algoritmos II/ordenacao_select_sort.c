#include <stdio.h>
#define MAX 100

/*int select_sort(int *v[], int n){
	
	int j, k, menor, aux;
	
	
	for(j=0;j<n-1;j++){
		
		menorpos=j;
		
			for(k=j+1;k<n;k++){
				
				if(v[k]<v[menorpos]){
					menorpos=k;
				}
				
			}
	
		if(menorpos != i){
		aux = v[j];
		v[j] = v[menorpos];
		v[menorpos] = aux;
		}
		
		return v;
}*/

int main(){
	
	
	int v[MAX], n, i, aux,
	    j, k, menor, menorpos;
	
	printf("De o tamanho do vetor: ");
	scanf("%d", &n);
	
	printf("Digite o vetor: \n");
	for(i=0;i<n;i++){
		scanf("%d", &v[i]);
	}
	
	for(j=0;j<n-1;j++){
		
		menorpos=j;
		
			for(k=j+1;k<n;k++){
				
				if(v[k]<v[menorpos]){
					menorpos=k;
				}
				
			}
	
		if(menorpos != i){
		aux = v[j];
		v[j] = v[menorpos];
		v[menorpos] = aux;
		}
		
	}
	
	for(i=0;i<n;i++){
		printf("%d ", v[i]);
	}
	
	
	return 0;
}