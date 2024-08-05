#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

#define max 200

char palavra[max];

int convertebinario(char carac[]){
	int s;
	int dec = 0, i=0;
	s = strlen(carac);
    while( s-- ) dec = dec + pow(2, i++) * (carac[s] - 48);
    return dec;
}

int main(){
	
	char caracter[max];
	int n, i;
	
	while(scanf("%d", &n) != EOF){
		
	for(i=0; i<n; i++){
		scanf("%s", &caracter);
		palavra[i] = convertebinario(caracter);
	}
	
	for(i=0; i<n; i++){
		printf("%c", palavra[i]);
	}	
	printf("\n");
	}
	return 0;
}