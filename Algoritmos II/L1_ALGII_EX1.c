//Exercicio 1 - a, b, c, d - da lista 1; ALGORITMOS II
//Enzo Campanholo Paschoalini - RA: 221026215 
#include <stdio.h>
#include <string.h>
#define max 30

enum ESTILOS{
	Rock=1, Pop=2, Funk=3, Sertanejo=4, Eletronica=5
};

typedef struct{
	
	char nome[max];
	int integrantes, posicao, estilo;
	
}tipo;


void cadastra(int quant){
	
	int i;
	tipo banda; // 1 "filho" da struct
	tipo bandas[max]; //30 'filhos' da struct
	
	bandas[3].integrantes;
	
	
		
		fflush(stdin);
		printf("Nome da banda: ");
		gets(banda.nome);
		
		do{
			printf("Estilo Musical:\n {1 - Rock, 2 - Pop, 3 - Funk, Sertanejo, 5 - Eletronica}\n");
			scanf("%d", &banda.estilo);
			
		}while(banda.estilo<0 || banda.estilo>5);
		
		printf("Integrantes: \n");
		scanf("%d", &banda.integrantes);
		
		printf("Posicao no ranking: \n");
		scanf("%d", &banda.posicao);			
}

void busca_rank(int quant){
	
	int j, rank;
	tipo banda;
	
	system("cls");
	
	printf("Digite o rank da busca: \n");
	scanf("%d", &rank);
	
	for(j=0;j<quant;j++){
		if(banda.posicao[j]==rank){
			printf("\t%s\n", banda.nome[max][j]);
			printf("\t%d\n", banda.estilo[j]);
			printf("\t%d\n", banda.integrantes[j]);
			printf("\t%d\n", banda.posicao[j]);
		}
	}	
}

void busca_estilo(int quant){
	
	int estilo;
	int k;
	tipo banda;
	
	do{
			printf("Estilo Musical da busca:\n {1 - Rock, 2 - Pop, 3 - Funk, Sertanejo, 5 - Eletronica}\n");
			scanf("%d", &estilo);
			
		}while(estilo<0 || estilo>5);
	
	system("cls");
	
	printf("Bandas do estilo %d: \n{1 - Rock, 2 - Pop, 3 - Funk, Sertanejo, 5 - Eletronica}\n", estilo);
	
	for(k=0;k<quant;k++){
		if(banda.estilo[k]==estilo){
			printf("\t%s\n", banda.nome[max][k]);
			printf("\t%d\n", banda.estilo[k]);
			printf("\t%d\n", banda.integrantes[k]);
			printf("\t%d\n", banda.posicao[k]);
		}
	}	
}

void consulta_nome(int quant){
	
	char band[max];
	int l;
	tipo banda;
	
	system("cls");
	
	printf("Digite a o nome da banda da busca: ");
	gets(band);
	
	for(l=0;l<quant;l++){
		if((stricmp(banda.nome[l],band)==0) && (banda.posicao[l])){
			printf("\t%s\n", banda.nome[max][l]);
			printf("\t%d\n", banda.estilo[l]);
			printf("\t%d\n", banda.integrantes[l]);
			printf("\t%d\n", banda.posicao[l]);
		}
	}
}

int main(){
	
	int op, num_bandas;
	char resp;
	tipo banda;
	
	printf("Digite a quantidade de bandas: \n");
	scanf("%d", &num_bandas);
	
	system("cls");
	
	do{
		
		printf("__>MENU<__\n");
		printf("__>1<Cadastrar %d Bandas\n", num_bandas);
		printf("__>2<Buscar por Rank\n");
		printf("__>3<Buscar por Estilo\n");
		printf("__>4<Consultar Rank por Nome\n");
		
		do{
		scanf("%d", &op);
		}while(op>4 || op<1);
		
		switch(op){
			case '1': cadastra(num_bandas);
					  break;				
					
			case '2': busca_rank(num_bandas);
					  break;
				
			case '3': busca_estilo(num_bandas);
					  break;
					  
			case '4': consulta_nome(num_bandas);
					  break;
		}
		
		
		printf("\nGostaria de fazer uma nova operacao? (S/N)");
		
		do{
			resp=toupper(getch());
		}while(resp!='S' && resp!='N');
		
		system("cls");
		
	}while(resp=='S');
	
	
	return 0;
}

