#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int main () {
	
	char d[MAX], s[MAX];
	char *compara;
		
	while (scanf("%s %s", d, s) != EOF) {
		
		compara = strstr(d, s);
		
		if (compara != NULL) {
			
			printf("Resistente\n");
			
		}
		
		else 
			printf("Nao resistente\n");
		
		
	}
	
	return 0;
	
}