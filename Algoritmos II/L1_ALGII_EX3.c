//Exercicio 3 da lista 1; ALGORITMOS II
//Enzo Campanholo Paschoalini - RA: 221026215 
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define max 100

typedef struct{
	
	int real;
	int imaginario;
	
}complexo;

void menu (char *op) {

  printf ("\n    __>M E N U<__ ");
  printf ("\n __>1 - Ler Numeros Complexos");
  printf ("\n __>2 - Somar dois Numeros Complexos");
  printf ("\n __>3 - Subtrair dois Numeros Complexos");
  printf ("\n __>4 - Multiplicar dois numeros complexos");
  printf ("\n __>5 - Sair");
  printf ("\n\n Opcao ---> ");
  do {
    *op = getch();
  } while (*op < '1' || *op > '6'); 
  printf ("%c",*op);   
  printf ("\n\n--------------------------------------------------------\n");   
}

void ler_complexo(complexo *num){
		
		printf("Digite a parte real: \n");
		scanf("%d", &(*num).real);
		
		printf("Digite a parte imaginaria: \n");
		scanf("%d", &(*num).imaginario);
		
		printf("Voce digitou o numero complexo Z=%d+%di", (*num).real, (*num).imaginario);
}

int main(){
	
	char resp;
	int op, i;
	complexo num[max];
	
	printf("Calculadora de Operacoes com Numeros Imaginarios!\n");
	
	menu(&op);
	
	switch(op){
		
		case '1':	do{
						
						ler_complexo(&num[i]);
						
						printf("\nGostaria de fazer ler mais um numero? (S/N)");
						
						do{
							resp=toupper(getch());
						}while(resp!='S' && resp!='N');
						
						i++;
						
					}while(resp=='S');
					break;
			
		case '2':
					break;
				
		case '3':
					break;
					
		case '4':
					break;
						
		case '5':
					break;
	}
	
	return 0;
	
}
