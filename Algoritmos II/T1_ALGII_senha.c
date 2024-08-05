#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 30

int main(){
	
	char senha[max], entrada[max];
	char nomeusuario[max];
	int value, tries=0;
	
	strcpy(senha,"ggwpgullo13");
	
	printf("Digite o nome do proprietario da conta:\n");
	gets(nomeusuario);
	
	printf("\n");
	
	do{
		
		printf("Senha:\n");
		gets(entrada);
		
		value=(stricmp(entrada,senha));
		
		if(value!=0){
			printf("\nSenha incorreta\n");
			tries++;
		}
		
		else
			printf("\nAcesso permitido; senha correta.\n");
			printf("Seja bem-vindo(a), ");
			printf("%s", nomeusuario);
			
		
	}while(value && tries<=2);
	
	
	return 0;
}