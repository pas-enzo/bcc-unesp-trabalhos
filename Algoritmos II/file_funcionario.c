#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	
	char nome[31];
	char data_adm[9];
	char data_nscm[9];
	char cargo[15];
	float salario;
	
} dados;

void menu(){
}

void cadastra(char nomearq[]){
	dados funcionario;
	char resp, strnum[6];
	FILE *arquivo;
	
	if((arquivo=fopen(nomearq,"wb")) == NULL){
		printf("Erro de abertura.\n");
	}
	
	printf("Nome do funcionario: \n");
	gets(funcionario.nome);
	
	
}

void mostra(){
	
}

void consulta(){
}

int main(){
	
	char opcao, sheet_name[20];
	
	printf("De um nome a sua planilha: \n");
	gets(sheet_name);
	
	do{
	
		switch(opcao){
		
			case'1':	cadastra(sheet_name);
						break;
					
			case'2':	mostra(sheet_name);
						break;
					
			case'3':	consulta(sheet_name);
						break;
					
			case'4':	break;
		
			case'5':	printf("Opcao invalida.\n");
						break;
					
		
		}
	}while(opcao!='4');		
	
	return 0;
}