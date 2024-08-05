#include <stdio.h>
#define size 15

int main(){
	
	int n, a[size][size];
	int i, j, x, y;
	int temp;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("\n\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	
	do{
		printf("\nDigite as colunas a serem trocadas:\n");
		scanf("%d%d", &x, &y);
			x--;
			y--;
			
			if(y<x){
				temp = x;
				x = y;
				y = temp;
			}
					
	}while((x<0 || x>n-1) || (y<0 || y>n-1));
	
	temp=0;
	
	for(i=0;i<n;i++){
		temp = a[i][x];
		a[i][x] = a[i][y];
		a[i][y] = temp;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}


