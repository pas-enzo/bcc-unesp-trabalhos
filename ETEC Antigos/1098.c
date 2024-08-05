#include <stdio.h>

int main(){
	
	double i, k;
	int j;
	
	for(i=0;i<2.1;i+=0.2){
		
		for(j=1;j<=3;j++){
			k=i+j;
			
			if(i==0 || i>1.8 || (i>0.9 && i<1.1))
				printf("I=%.lf J=%.lf\n", i, k);
				
			else
				printf("I=%.1lf J=%.1lf\n", i, k);
		}
	
	}
	
	
	return 0;
}
