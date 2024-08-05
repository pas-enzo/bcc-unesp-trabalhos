#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
	
	int nbil, mpes;
	int cont = 0, i, j, k;
	
	while (1) {
		
		scanf("%d %d", &nbil, &mpes);
		
		if(nbil == 0 && mpes == 0) break;
		
		int bilhete[mpes], cpy[mpes];
		
		for (i = 0; i < mpes; i++)
			scanf("%d", &bilhete[i]);

		
		for (i = 0; i < mpes; i++)
			cpy[i] = bilhete[i];
			
		for (i = 0; i < mpes; i++) {	
			
			for (j = 0; j < mpes; j++) {	

				if (i != j)
				
					if (bilhete[i] == cpy[j]) {
						
						cont++;
						cpy[j] = 0;
						
						
						for (k = j; k < mpes; k++)
							if (bilhete[i] == cpy[k])
								cpy[k] = 0;

					
						break;

					}
				
				cpy[i] = 0;
			
			}
		}
		
		printf("%d\n", cont);
		cont = 0;
		
	}
	

	
	
	return 0;
	
}