#include <stdio.h>
#define max 100

int main(){
	
	int m, n, lav[max][max];
	int i, j;
	int sac=0, lit=0;
	
	/*termina o programa com End Of File*/
	while(scanf("%d %d", &m, &n) != EOF){
		
		/*le a lavoura*/
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d", &lav[i][j]);
			}
		}
		
		/*calculo cafe*/
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				lit+=lav[i][j];
				if(lit>=60){
					lit-=60;
					sac++;
				}
			}
		}
		
		printf("%d saca(s) e %d litro(s)\n", sac, lit);
		
		sac=0;
		lit=0;
		
	}
	
	return 0;
	
}