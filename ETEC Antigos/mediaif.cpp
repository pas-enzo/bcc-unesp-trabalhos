#include <stdio.h>
 
int main() {
	
	double N1, N2, N3, N4, NE, M, MF;
	
	scanf("%lf%lf%lf%lf", &N1, &N2, &N3, &N4);
	
	M = (2*N1 + 3*N2 + 4*N3 + 1*N4)/ 10;
	
	printf("Media: %.1lf\n", M);
	
	if(M<5){
		printf("Aluno reprovado.\n");
	}
	
		else if(M>=5 && M<7){
			printf("Aluno em exame.\n");
			scanf("%lf", &NE);
			
			MF = (M + NE) / 2;
			
			if(MF>=5){
				printf("Nota do exame: %.1lf\n", NE);
				printf("Aluno aprovado.\n");
				printf("Media final: %.1lf\n", MF);
			}
			
				else{
					printf("Nota do exame: %.1lf\n", NE);
					printf("Aluno reprovado.\n");
					printf("Media final: %.1lf\n", MF);
				}
		}
		
			else{
				printf("Aluno aprovado.\n");
		}
		
    return 0;
}
