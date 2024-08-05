#include <stdio.h>

int main(){
	
	int n, m, p[1000], q[1000], temp;
	int i, j, k, l, conta=0;
	
	scanf("%d", &n);
	
	do{
		scanf("%d", &m);
		
		for(j=0;j<m;j++){
			scanf("%d", &p[j]);			
		}
		
		for(j=0;j<m;j++){
			q[j]=p[j];			
		}
		
		for(k=0;k<m;k++){
			for(l=0;l<m-1;l++){
				if(p[l]<p[l+1]){
					temp=p[l];
					p[l]=p[l+1];
					p[l+1]=temp;
				}
			}
		}
		
		for(j=0;j<m;j++){
			if(q[j]==p[j])
				conta++;			
		}
		
		
		printf("%d\n", conta);
		
		conta=0;
		
		for(j=0;j<m;j++){
			p[j]=0;
			q[j]=0;
		}
		
		i++;
		
	}while(i<n);
	
	
	return 0;
}