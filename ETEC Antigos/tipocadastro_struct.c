#include <stdio.h>

typedef struct{
	int quantidade, cpf, salario;
	char nome_funcionario[50];
	int id;
	
}TipoCadastro;

void IniciaCadastro(){
	TipoCadastro inicia;
	
	inicia.quantidade=0;
}
			/*n sendo a quantidade de funcionarios*/
void ListaFuncionario(TipoCadastro Lista){
	int i;
	
	for(i=0;i<Lista.quantidade;i++){
		printf("\n\n\n--------------------------\n");
		printf("Nome: %s\n", Lista[i].nome_funcionario);
		printf("CPF: %d\n", Lista[i].cpf);
		printf("ID da empresa: %d\n", Lista[i].id);
		printf("Salario em R$: %d\n", Lista[i].salario);
		printf("--------------------------\n\n\n");
	}
	
}

void SalarioIntervalo(int v1, int v2, TipoCadastro iv){
	
	int soma_media, q_media; i;
	float media;
	
	for(i=0<iv.quantidade<i++){
		if(iv[i].salario>v1 && iv[i].salario<v2){
			printf("\n\n\n--------------------------\n");
			printf("Nome: %s\n", iv[i].nome_funcionario);
			printf("CPF: %d\n", iv[i].cpf);
			printf("ID da empresa: %d\n", iv[i].id);
			printf("Salario em R$: %d\n", iv[i].salario);
			printf("--------------------------\n\n\n");
			soma_media+=iv[i].salario;
			q_media++;
		}	
	}
			
			media = (float)soma_media/q_media;
			
			printf("\n\n\n--------------------------\n");
			printf("A media dos salarios na faixa pesquisada foi de R$ %s\n", iv);
			printf("--------------------------\n\n\n");
	
}

int ListaMaraja(TipoCadastro maraja){
		
		typedef struct{
			char nome_maiorsalario[50];
			int cpf_maiorsalario, id_maiorsalario, salario_maiorsalario;
		}TOPG;
		
		TOPG sal;
		
		int i, maior=0;
		
		for(i=0;i<maraja.quantidade;i++){
			if(maraja[i].salario>maior){
				strcpy(sal.nome_maiorsalario, maraja[i].nome_funcionario);
				sal.cpf_maiorsalario = maraja[i].cpf;
				sal.id_maiorsalario = maraja[i].id;
				sal.salario_maiorsalario = maraja[i].salario;
				
				maior = maraja[i].salario;
			}
		}
		
		return sal;
		
}