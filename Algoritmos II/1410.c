#include <stdio.h>
#define MAX 100


int main(){
	
	int A, D;
	int i, j;
	int va[MAX], vd[MAX];
	int temp;
	
	while(1){
		
		scanf("%d%d", &A, &D);
		
		if(A==0 && D==0)
			break;
			
		for(i=0;i<A;i++){
			scanf("%d", &va[i]);
		}
		
		for(i=0;i<D;i++){
			scanf("%d", &vd[i]);
		}
		
	//fazer sorting
	
	for(i=0;i<A;i++){
		for(j=0;j<A-1;j++){
			
			if(va[j]>va[j+1]){
				
				temp=va[j];
				va[j]=va[j+1];
				va[j+1]=temp;
			}
		}
	}
	
	for(i=0;i<D;i++){
		for(j=0;j<D-1;j++){
			
			if(vd[j]>vd[j+1]){
				
				temp=vd[j];
				vd[j]=vd[j+1];
				vd[j+1]=temp;
			}
		}
	}
	
	
	
	if(va[0]>=vd[1])printf("N\n");
	
	else printf("Y\n");
	
	}
	return 0;
}