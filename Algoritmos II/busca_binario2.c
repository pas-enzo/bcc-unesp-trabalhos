#include <stdio.h>


int buscabi(*v, n, n0, num){
	
	int obj=(n+n0)/2;
	
}

//------------------------------------------------------------------------

int main(){
	
	int n, v[100], num;
	int i, j, ord;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%d", &v[i]);
	}
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(v[j]>v[j+1]){
				ord=v[j+1];
				v[j+1]=v[j];
				v[j]=ord;
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d ", v[i]);
	}
	
	printf("Qual numero gostaria de buscar?");
	scanf("%d", &num);
	
}