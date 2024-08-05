#include <stdio.h>
#define size 15

int main(){
	
	int n, a[size][size];
	int i, j, skip;
	int temp;
	
	scanf("%d", &n);
	skip=n-1;
	
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
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				temp=a[i][j];
				a[i][j]=a[i][j+skip];
				a[i][j+skip]=temp;
				skip-=2;
			}
		}
	}
	
	printf("\n\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	
}
