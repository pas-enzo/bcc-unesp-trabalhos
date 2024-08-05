#include <stdio.h>
#include <string.h>
#define NEED 1
#define NOT 0

int main(){
	
	char para_trabalho[6], para_casa[6];
	int n, i;
	int casaComprado=0, trabalhoComprado=0;
	int casaSobrando=0, trabalhoSobrando=0;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		fflush(stdin);
		scanf("%s", para_trabalho);
		
		fflush(stdin);
		scanf("%s", para_casa);
		
		if(strcmp(para_trabalho, "chuva")==0 && casaSobrando==0){
			casaComprado++;
        	trabalhoSobrando++;
		}
		
		if(strcmp(para_trabalho, "chuva")==0 && casaSobrando>0){
			trabalhoSobrando++;
        	casaSobrando--;
		}
		
		if(strcmp(para_casa, "chuva")==0 && trabalhoSobrando==0){
			trabalhoComprado++;
			casaSobrando++;
		}
		
		if(strcmp(para_casa, "chuva")==0 && trabalhoSobrando>0){
			casaSobrando++;
        	trabalhoSobrando--;
		}
		
	}
	
	printf("%d %d", casaComprado, trabalhoComprado);
	
	return 0;
}