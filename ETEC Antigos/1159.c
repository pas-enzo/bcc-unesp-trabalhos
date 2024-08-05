#include<stdio.h>

int main(){
	
	int x=1, sum=0, i=1;
	
	while(x!=0){
		scanf("%d", &x);
		
		do{
			if(x%2==0){
				x+=2;
				sum+=x;
				i++;
				}
				
			if(x%2!=0){
				x=(x+1)+2;
				sum+=x;
				i++;
				}
		}while(i<=5);
		
		printf("%d\n", sum);
		
	}
	
	return 0;
}
