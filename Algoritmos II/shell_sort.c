#include <stdio.h>
#define MAX 1000

int shell(int v[], int n){
	
	int gap, i, j, temp;
	
	for(gap=n/2;gap>0;gap/=2){
		for(i=gap;i<n;i+=1){
			
			temp=v[i];
			
			for(j=i;j>=gap && v[j-gap]>temp; j-=gap)
				v[j]=v[j-gap];
				
				
				v[j]=temp;
				

		}
	}
	
	return 0;
	
}

void printa(int v[], int n){
	
	int i;
	
	for(i=0;i<n;i++){
		printf("%d ", v[i]);
	}
	
}

int main(){
	
	int v[MAX], troca;
	int i, j, k, temp, n;
	
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &v[i]);
	}
	
	shell(v, n);
	
	printf("\n\nVetor ordenado: \n");
	printa(v, n);
	
	
}