#include <stdio.h>
 
int main() {
	
	double N1, N2, N3, N4, NE, M, MF;
	
	scanf("%lf%lf%lf%lf", &N1, &N2, &N3, &N4);
	
	M = 2*(N1) + 3*(N2) + 4*(N3) + 1*(N4);
	
	printf("Media: %.1lf\n");
	
	if(M<5){
		print("Aluno reprovado.\n");
	}
	
		else if(M>=5 && M<7){
			printf("Aluno em Exame.\n");
			scanf("%lf", &NE);
			
			MF = (M + NE) / 2;
			
			if(MF>=5){
				printf("Aluno aprovado.\n");
			}
			
				else{
					printf("Aluno reprovado.\n");
				}
		}
		
			else{
				printf("Aluno aprovado.\n");
			}
	
    return 0;
}
