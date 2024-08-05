#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#define size 30

typedef struct{
	char nome[size];
	float saldo;
	int numero_conta;
	char data_ultop[size];
}dados;


void cadastra(char arq_name[]){
	
	dados usuario;
	char valid, numstr[size];
	int i=1;
	
	FILE *arquivo;
	
	if((arquivo = fopen(arq_name, "wb")) == NULL){
		printf("Erro na abertura do arquivo.\n\n");
		exit(1);
	}
	
	do{
		
		printf("Cliente #%d", i);
		
		fflush(stdin);
		printf("\n\nNumero da conta: ");
		gets(numstr);
		usuario.numero_conta = atoi(numstr);
		
		printf("Nome do cliente: ");
		gets(usuario.nome);
		
		printf("Saldo: ");
		gets(numstr);
		usuario.saldo = atof(numstr);
		
		printf("Data da ultima operacao: ");
		gets(usuario.data_ultop);
		
		fwrite(&usuario,sizeof(usuario),1,arquivo);
		
		printf("Gostaria de cadastrar outro cliente?(S/N)\n");
		
		do{
 			
			 valid=toupper(getch());
			 
 		}while(valid!='S' && valid!='N');
 
 		system("cls");
 		
 		i++;

	}while(valid=='S');
	
	fclose(arquivo);

}

void consulta(char arq_name[]){
	
	FILE *arquivo;
	dados usuario;
	
	if ((arquivo = fopen(arq_name, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
	}
    
    system("cls");
    
    printf("Clientes Cadastrados:\n");
    printf("\tNumero da conta \tNome do cliente \tSaldo \t\tData da ultima operacao\n");
    
    while(fread(&usuario, sizeof(dados), 1, arquivo) == 1){
    printf("\t\t%d \t\t%s \t\t%.2f \t\t%s \n", usuario.numero_conta, usuario.nome, usuario.saldo, usuario.data_ultop);	
	}
	
	fclose(arquivo);	
}

int main(){
	
	char nome_planilha[size];
	
	printf("Digite o nome da planilha: ");
	gets(nome_planilha);
	
	cadastra(nome_planilha);
	
	consulta(nome_planilha);
	
	return 0;
}