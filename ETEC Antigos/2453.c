#include <stdio.h>
#include <string.h>
#define max 1000



int main(){
	
	int i, tam, space=0;
	char lp[max];	
	
	gets(lp);
	tam=strlen(lp);
	
	for(i=0;i<tam;i++){
		if(lp[i]==' '){
			space+=1;
		}
		
		if(i%2!=0 && space%2==0 && lp[i]!='p'){
			printf("%c", lp[i]);
		}
		
		else if(i%2!=0 && space%2!=0 && lp[i]!='p')
				printf("%c", lp[i]);
		
		
	}		
			
	
	return 0;
}