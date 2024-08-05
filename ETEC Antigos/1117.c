#include <stdio.h>

int main(){
	
	double n1=-1, n2=-1, media;
	
	while(n1<0 || n1>10){
		scanf("%lf", &n1);
		
		if(n1>=0 && n1<=10)
			break;
		
		else{
			printf("nota invalida\n");
		}
	}
	
	while(n2<0 || n2>10){
		scanf("%lf", &n2);
		
		if(n2>=0 && n2<=10)
			break;
			
		else{
			printf("nota invalida\n");
		}
	}
	
	media = (n1+n2)/2;
	
	printf("media = %.2lf\n", media);
	
	return 0;
}
