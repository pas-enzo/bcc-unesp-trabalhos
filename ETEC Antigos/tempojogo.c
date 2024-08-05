#include <stdio.h>

int main(){
	
	int in, fim, tempo;
	
	scanf("%d%d", &in, &fim);
	
	if(fim <= in){
		fim += 24;
		
		printf("O JOGO DUROU %d HORA(S)\n", fim - in);
	}
	
	else{
		tempo = fim - in;
		
		printf("O JOGO DUROU %d HORA(S)\n", tempo);
	}

	
	
	return 0;
}
