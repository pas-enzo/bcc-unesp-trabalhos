#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 100

typedef struct{
	int real;
	int imaginario;
} complexo;

void mostra_complexos(int repet, complexo mostra[MAX]){
	int cont;
	system("cls");
	printf("\n\nVoce digitou os seguintes numeros complexos: \n");
	
	for(cont=0;cont<repet;cont++){
			printf("%d - Z=%d+%di\n", cont+1, mostra[cont].real, mostra[cont].imaginario);
	}
}

void soma(complexo soma[MAX]){
	int a, b; 
	int soma_real, soma_imaginario;
	
	printf("\n\nQuais numeros gostaria de somar?\n");
	scanf("%d%d", &a, &b);
	
	soma_real = soma[a-1].real + soma[b-1].real;
	soma_imaginario = soma[a-1].imaginario + soma[b-1].imaginario;
	
	printf("\nSoma de %d e %d: Z=%d+%di", a, b, soma_real, soma_imaginario);
	
}

void sub(complexo sub[MAX]){
	int a, b; 
	int sub_real, sub_imaginario;
	
	printf("\n\nQuais numeros gostaria de subtrair?\n");
	scanf("%d%d", &a, &b);
	
	sub_real = sub[a-1].real - sub[b-1].real;
	sub_imaginario = sub[a-1].imaginario - sub[b-1].imaginario;
	
	printf("\nDiferenca de %d e %d: Z=%d+%di", a, b, sub_real, sub_imaginario);
	
}

void multiplica(complexo mult[MAX]){
	int a, b; 
	int mult_real, mult_imaginario;
	
	printf("\n\nQuais numeros gostaria de multiplicar?\n");
	scanf("%d%d", &a, &b);
	
	mult_real = (mult[a-1].real * mult[b-1].real);
	mult_imaginario = (mult[a-1].real * mult[b-1].imaginario) + (mult[a-1].imaginario * mult[b-1].real) + (-1*(mult[a-1].imaginario * mult[b-1].imaginario));
	
	printf("\nSoma de %d e %d: Z=%d+%di", a, b, mult_real, mult_imaginario);
	
}

int menu(){
	
	char op;
	
	printf("\n\t>MENU<\n");
	printf(">1< Somar dois numeros complexos\n");
	printf(">2< Subtrair dois numeros complexos\n");
	printf(">3< Multiplicar dois numeros complexos\n");
	printf("\n\n\n >Opcao------------> ");
	
	fflush(stdin);
	scanf(" %c", &op);
	
	return op;
}

int main(){
	
	int i, n; 
	char op; 
	int resp;
	complexo numero[MAX];
	
	printf("\nDigite a quantidade de numeros imaginarios que gostaria de armazenar: \n");
	scanf("%d", &n);
	
	
	for(i=0;i<n;i++){
		printf("Parte real #%d: \n", i+1);
		scanf("%d", &numero[i].real);
		numero[i].real=abs(numero[i].real);
		
		printf("Parte imaginaria #%d: \n", i+1);
		scanf("%d", &numero[i].imaginario);
		numero[i].imaginario=abs(numero[i].imaginario);
	}
	
	do{
	
	mostra_complexos(n, numero);
	
	op=menu();
	
	switch(op){
		case '1':	soma(numero);  
					break;
					
		case '2':	sub(numero);  
					break;
					
		case '3':	multiplica(numero);  
					break;
					
		default: break;
		
	}
	
	do{
	printf("\nDigite 1 para realizar outra opcao ou digite 0 para sair.\n");
	scanf("%d", &resp);
	}while(resp!=0 && resp!=1);
	
	}while(resp);
	
	return 0;	
}