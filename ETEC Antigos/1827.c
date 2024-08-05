#include <stdio.h>
#define max 102

int main(){
	
	int n, mat[max][max];
	int i, j, k, m;
	
	while((scanf("%d", &n) != EOF)){
		
		k=n-1;
		m=n/3;
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				
				if(i==j)mat[i][j]=2;
					
					else mat[i][j]=0;
					
				if(j==k)mat[i][j]=3;
				
			}k--;
		}
		
		for(i=m;i<n-m;i++){
			for(j=m;j<n-m;j++){
				mat[i][j]=1;
				
				if(i==n/2 && j==n/2)
					mat[i][j]=4;
				
				
			}
		}
		
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d", mat[i][j]);
			}printf("\n");
		}printf("\n");
		
	}	
	
	return 0;
}
