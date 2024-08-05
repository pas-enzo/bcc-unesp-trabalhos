#include <stdio.h>

int main(){
	
	int n=1, v[10001], i;
	int pico=0, mxl=0, mnl=0;
	
	
	do{
		
		scanf("%d", &n);
		
		pico=0;
		
		for(i=0;i<n;i++){
			scanf("%d", &v[i]);
		}
		
		for(i=0;i<n;i++){
			if(v[i]<v[(i+1)%n]){
				if(v[i+1]>v[(i+2)%n]){
					pico++;
				}
			}
			
			if(v[i]>v[(i+1)%n]){
				if(v[i+1]<v[(i+2)%n]){
					pico++;
				}
			}
		}
	
	printf("%d\n", pico);
	scanf("%d", &n);
		
	}while(n!=0);
	
	return 0;
}