#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 200

int compara (const void* a, const void* b) {

	return strcmp((char*)a, (char*)b);

}

int main() {
	
	int n, i;
	char livro[1001][5];

	while(scanf("%d", &n) != EOF){

		for	(i=0; i<n; i++) {

			scanf("%s", &livro[i]);
	
		}

		qsort(livro, n, sizeof(char) * 5, compara);

		for	(i=0; i<n; i++) {
		
			printf("%s\n", livro[i]);
		
		}
	
  	}
  
  	return 0;
  
}
