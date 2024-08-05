#include <stdio.h>
#include <math.h>


int main(){
	
	
	int tipo, tipo3, confirm=0, caso, repro1=0; 
	double s, c, tg, ang, angrad; 
	double cotg, cossec, sec;
	double carc, arcsen, arccos, arctg;
	
	printf("Calculadora das funcoes trigonometricas!\n");
	printf("Enzo Paschoalini - RA 221026215\n\n");
	
	do{
	
		
		do{
			printf("\nSelecione o tipo de entrada: \n1 - radianos;\n2 - graus;\n3 - calculo de Arco\n");
			scanf("%d", &tipo);
		}while(tipo!=1&&tipo!=2&&tipo!=3);
		
		if(tipo==3){
			
			do{
				printf("\nDefina o parametro do calculo\n1 - arco-seno\n2 - arco-cosseno\n3 - arco-tangente \n");
				scanf("%d", &tipo3);
			}while(tipo3!=1&&tipo3!=2&&tipo3!=3);
			
			if(tipo3==1){
				printf("\nDigite o valor do seno: \n");
				scanf("%lf", &carc);
				
				arcsen=asin(carc);
				
				printf("\n--> O arco, em radianos, cujo seno eh %.4lf, eh: %.4lf \n", carc, arcsen);
			}
			
			if(tipo3==2){
				printf("\nDigite o valor do cosseno: \n");
				scanf("%lf", &carc);
				
				arccos=acos(carc);
				
				printf("\n--> O arco, em radianos, cujo cosseno eh %.4lf, eh: %.4lf \n", carc, arccos);
			}
			
			if(tipo3==3){
				printf("\nDigite o valor da tangente: \n");
				scanf("%lf", &carc);
				
				arctg=atan(carc);
				
				printf("\n--> O arco, em radianos, cuja tangente eh %.4lf, eh: %.4lf \n", carc, arctg);
			}
			
		}
		
		else{
		
		printf("\nDigite o valor do angulo na unidade escolhida: \n");
		scanf("%lf", &ang);
		
		if(tipo==2){
			angrad=(ang*M_PI)/180;
		}
		
		else
		angrad=ang;
		
		printf("\nO valor digitado, em radianos, foi: %.2lfrd \n", angrad);
		
		s=sin(angrad);
		
		c=cos(angrad);
		
		tg=tan(angrad);
		
		sec=pow(s,-1);
		
		cossec=pow(c,-1);
		
		cotg=pow(tg,-1);
		
		
		
		
			
		do{
			
			printf("\n\nSelecione qual funcao gostaria de calcular: \n");
			printf("1 - Seno; \n");
			printf("2 - Cosseno; \n");
			printf("3 - Tangente; \n");
			printf("4 - Secante; \n");
			printf("5 - Cossecante; \n");
			printf("6 - Cotangente; \n");
			scanf("%d", &caso);
			
			
			switch(caso){
				
				case 1:
					printf("--> Seno de %.2lf radianos sera: %.4lf\n", angrad, s);
					repro1=1;
					break;
					
				case 2:
					printf("--> Cosseno de %.2lf radianos sera: %.4lf\n", angrad, c);
					repro1=1;
					break;
					
				case 3:
					printf("--> Tangante de %.2lf radianos sera: %.4lf\n", angrad, tg);
					repro1=1;
					break;
					
				case 4:
					printf("--> Secante de %.2lf radianos sera: %.4lf\n", angrad, sec);
					repro1=1;
					break;
					
				case 5:
					printf("--> Cossecante de %.2lf radianos sera: %.4lf\n", angrad, cossec);
					repro1=1;
					break;
					
				case 6:
					printf("--> Cotangente de %.2lf radianos sera: %.4lf\n", angrad, cotg);
					repro1=1;
					break;
					
					
				default:
					repro1=0;
					break;
		
			} 
				
				if(repro1){
					printf("\n<>Digite 1 para calcular outra funcao para esse angulo.<> \n");
					scanf("%d", &repro1);
				}
				
				else{
					printf("\nEntrada invalida!\n");
				}
				
		
		}while(repro1==1);
		
	}
		
	printf("\n<>Digite 0 para realizar um novo calculo!<>\n");
	scanf("%d", &confirm);
		
		
		
	}while(confirm==0);
	
		
	return 0;
}
