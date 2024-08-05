#include <stdio.h>
#include <string.h>

int main(){
	
	int t, i, R, G, B, caso;
	float p;
	char opera[100];
	
	scanf("%d", &t);
	
	for(i=1;i<=t;i++){
		
		fflush(stdin);
		scanf("%s", opera);
		
		scanf("%d%d%d", &R, &G, &B);
		
		if(strcmp(opera,"eye")==0){
			p = 0.3*R + 0.59*G + 0.11*B;
			caso=(int)p;
			printf("Caso #%d: %d\n", i, caso);
		}
		
		if(strcmp(opera,"mean")==0){
			p = (R+G+B)/(float)3;
			caso=(int)p;
			printf("Caso #%d: %d\n", i, caso);
		}
		
		if(strcmp(opera,"min")==0){
			if(R<=G && R<=B)
				caso=R;
			
			if(G<=R && G<=B)
				caso=G;
			
			if(B<=R && B<=G)	
				caso=B;
			printf("Caso #%d: %d\n", i, caso);
		}
		
		if(strcmp(opera,"max")==0){
			if(R>=G && R>=B)
				caso=R;
			
			if(G>=R && G>=B)
				caso=G;
			
			if(B>=R && B>=G)	
				caso=B;
			printf("Caso #%d: %d\n", i, caso);
		}
		
	}
	
	return 0;
}