#include <stdio.h>

void swap(int *xj, int *xj1){
	
	int temp;
	
	temp=*xj;
	*xj=*xj1;
	*xj1=temp;
	
}

void bubble(int v[], n){
	
	int i, j;
	int troca;
	
	for(i=0;i<n-1 && troca;i++){
		troca=0;
		for(j=0;j<n-i-1;j++){
			if(v[j]>v[j+1]){
				swap(&v[j], &v[j+1]);
				troca=1;
			}
		}
	}
	
}

void printa(int v[], n){
	
	
	
}

int main(){
	
	int v[MAX], i, n;
	
	printf("Digite a ordem do vetor: ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++)
		scanf("%d", &v[i]);
	
	bubble(v, n);
	
	
	
}