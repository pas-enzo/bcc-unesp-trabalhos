#include <stdio.h>


int main(){
    
	double n, d=1 , c, S=0;
    	
		for(n=1;n<=39;n+=2){
        	c=n/d;
        	S+=c;
        	d*=2;
    }
    
    printf("%.2lf\n",S);
    
	return 0;
}
