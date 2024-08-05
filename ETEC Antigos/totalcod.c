#include <stdio.h>
 
int main() {

	int cod, quant;
	double total;
	
	scanf("%d%d", &cod, &quant);
	
	if(cod==1){
		total = 4 * (float)quant;
	}
	
		else if(cod==2){
			total = 4.5 * (float)quant;
		}
		
			else if(cod==3){
				total = 5 * (float)quant;
			}
			
				else if(cod==4){
					total = 2 * (float)quant;
			    }
				
					else if(cod==5){
						total = 1.5 * (float)quant;
					}
					
	printf("Total: R$ %.2lf\n", total);
	
    return 0;
}
