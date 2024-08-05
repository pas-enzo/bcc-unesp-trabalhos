#include <stdio.h>
#include <math.h>

int main(){
	
	double A, B, C, aux;
	
	scanf("%lf%lf%lf", &A, &B, &C);
	
	if(A>=B && A>=C){
		A = A;
		
			if(A>=B+C){
				printf("NAO FORMA TRIANGULO\n");	
			}
				
				else if(pow(A,2)==pow(B,2) + pow(C,2)){
					printf("TRIANGULO RETANGULO\n");
				}
				
					else if(pow(A,2)>pow(B,2) + pow(C,2)){
						printf("TRIANGULO OBTUSANGULO\n");
					}
					
						else if(pow(A,2)<pow(B,2) + pow(C,2)){
							printf("TRIANGULO ACUTANGULO\n");
						}
						
							else if(A==B && B==C){
								printf("TRIANGULO EQUILATERO\n");
							}
							
								else if((A==B && B!=C) || (A==C && C!=B) || (B==C && C!=A)){
									printf("TRIANGULO ISOCELES\n");
								}
	}
	
	if(B>A && B>C){
		A = aux;
		aux = B;
		
			if(A>=B+C){
				printf("NAO FORMA TRIANGULO\n");	
			}
				
				else if(pow(A,2)==pow(B,2) + pow(C,2)){
					printf("TRIANGULO RETANGULO\n");
				}
				
					else if(pow(A,2)>pow(B,2) + pow(C,2)){
						printf("TRIANGULO OBTUSANGULO\n");
					}
					
						else if(pow(A,2)<pow(B,2) + pow(C,2)){
							printf("TRIANGULO ACUTANGULO\n");
						}
						
							else if(A==B && B==C){
								printf("TRIANGULO EQUILATERO\n");
							}
							
								else if((A==B && B!=C) || (A==C && C!=B) || (B==C && C!=A)){
									printf("TRIANGULO ISOCELES\n");
								}
	}
	
	if(C>A && C>B){
		A = aux;
		aux = C;
		
			if(A>=B+C){
				printf("NAO FORMA TRIANGULO\n");	
			}
				
				else if(pow(A,2)==pow(B,2) + pow(C,2)){
					printf("TRIANGULO RETANGULO\n");
				}
				
					else if(pow(A,2)>pow(B,2) + pow(C,2)){
						printf("TRIANGULO OBTUSANGULO\n");
					}
					
						else if(pow(A,2)<pow(B,2) + pow(C,2)){
							printf("TRIANGULO ACUTANGULO\n");
						}
						
							else if(A==B && B==C){
								printf("TRIANGULO EQUILATERO\n");
							}
							
								else if((A==B && B!=C) || (A==C && C!=B) || (B==C && C!=A)){
									printf("TRIANGULO ISOCELES\n");
								}
	}
	
	return 0;
}
