#include <stdio.h>

main() {
	
	int gola, golb;
	
	printf("Infomre a quantidade de gols do time A: \n");
	scanf("%i", &gola);
	
	printf("Informe a quantidade de gols do time B: \n");
	scanf("%i", &golb);
	
	if (gola > golb) {
		printf("Vitoria do time A.");
		
	}
	
	  else if (gola < golb) {
	  	  printf("Vitoria do time B.");
	  }
	  
	    else {
	    	  printf("Empate.");
		}
}
