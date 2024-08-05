#include <stdio.h>

int main(){
	
	int par[5], impar[5];
	int qp, qi, i, j, x;
	
	for(i=0;i<15;i++){
		
		scanf("%d", &x);
		
		if(x%2==0){
			par[qp]= x;
			qp++;
			if(qp==5){
				for(j=0;j<5;j++)
					printf("par[%d] = %d\n", j, par[j]);
				
				qp=0;
			}
		}
		
		if(x%2!=0){
			impar[qi]= x;
			qi++;
			if(qp==5){
				for(j=0;j<5;j++)
					printf("impar[%d] = %d\n", j, impar[j]);
				
				qi=0;
			}
		}
		
	}
	
	for(j=0;j<qi;j++)
		printf("impar[%d] = %d\n", j, impar[j]);
		
	for(j=0;j<qp;j++)
		printf("par[%d] = %d\n", j, par[j]);
		
		return 0;
			
}
