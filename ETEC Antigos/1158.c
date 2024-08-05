#include<stdio.h>

int main(){
	
	int n, x, y, i=1;
	int sum=0, j, fim;
	
	scanf("%d", &n);	
	
	for(i=1;i<=n;i++){
		scanf("%d %d", &x, &y);
		
		if(x%2==0){
			for(j=x+1;j<x+(y*2);j+=2){
				sum+=j;
			}
		}
		
		if(x%2!=0){
			for(j=x;j<x+(y*2);j+=2){
				sum+=j;
			}
		}
		
		printf("%d\n", sum);
		sum=0;		
		
	}
	
	return 0;
}
