#include <stdio.h>
#define size 15

int main(){
	
	int n, a[size][size];
	int i, j, x, y;
	int find=0;
	
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
	
	for(i=0;i<n;i++){
		for(j=0;j<n && !find;j++){
			if(a[i][j]!=a[j][i])find=1;
		}
		if(find==1)break;
	}
	
	if(find==1)printf("\nA matriz nao e simetrica!\n");
	
	else printf("\nA matriz e simetrica!\n");
	
	return 0;
	
}
