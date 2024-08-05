//GUT - Gullenheim Ultimate Team - arquivo binario

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1 
#define FALSE 0

/// @brief 
typedef struct {
	
	/*campos dos cartoes dos jogadores do time*/
	char nome[30];
	char pais[30];
	char posicao;
	int overall;
	int numero_camisa;
	short int exist;
	
} card;

//-------------------------------------------------------------------------------------------------------------------------------------

void card_astra(char arquivo_nome[]){
    card registra;

    char resp;
    FILE *arquivo;

    if((arquivo = fopen(arquivo_nome, "a+b")) == NULL){
      printf ("\nErro da abertura do arquivo.\n\n");
      return;
    }   
    
    /*Os 5 campos basicos necessarios para a existencia de um cartao de jogador no GUT: nome, pais, posicao, numero da camisa e coeficiente de habilidade(overall)*/
    
    do{

        fflush(stdin);
        printf("Digite o nome do jogador que gostaria de cadastrar:\n");
        scanf("%s", registra.nome);

        printf("Pais de origem:\n");
        scanf(" %s", registra.pais);

        printf("Posicao em campo:    (A) - Atacante / (G) - Goleiro / (M) - Meio-Campista / (Z) -Zagueiro\n");
        scanf(" %c", registra.posicao);

        printf("Numero da camisa: \n");
        scanf("%d", &registra.numero_camisa);

        printf("Overall - pontos de habilidade na escala de 0 a 100: \n");
        scanf("%d", &registra.overall);

        registra.existe=TRUE;

        fwrite(&registra, sizeof(registra), 1, arquivo);

        printf("Cadastrar mais uma carta de jogador no seu time? (s/n)\n");

        do{
            resp=toupper(getch());
        }while(resp!='S' && resp!='N');

    }while(resp=='S');

    fclose(arquivo);

}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_mostra(char arquivo_nome[]){

    card jogador;
    FILE *arquivo;

    if((arquivo = fopen(nomearq, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }

    if(jogador.exist){
        printf("\n\n");
        printf("--G--U--T--2--0--2--3--\n");
        printf("\nNome: %s\n", jogador.nome);
        printf("Pais: %s\n", jogador.pais);
        printf("Posicao: %c\n", jogador.posicao);
        printf("Numero: %d\n", jogador.numero_camisa);
        printf("Overall: %d\n", jogador.overall);
        printf("--G--U--T--2--0--2--3--\n");
        printf("\n\n");
    }

    fclose(arquivo);

}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_sultaover(char arquivo_nome[]){

    card jogador;
    FILE *arquivo;

    int over_high, over_low;

    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }

    prinft("Qual faixa de Overall Gostaria de consultar?\n");
    printf("Menor Overall da consulta: ");
    scanf("%d", &over_low);
    printf("\nMaior Overall da consulta: ");
    scanf("%d", &over_high);

    while(fread(&jogador, sizeof(card), 1, arquivo) == 1)
        if((jogador.overall>over_low && jogador.overall<over_high) && aluno.existe) {
        	printf("\n\n");
            printf("--G--U--T--2--0--2--3--\n");
            printf("\nNome: %s\n", jogador.nome);
            printf("Pais: %s\n", jogador.pais);
            printf("Posicao: %c\n", jogador.posicao);
            printf("Numero: %d\n", jogador.numero_camisa);
            printf("Overall: %d\n", jogador.overall);
            printf("--G--U--T--2--0--2--3--\n");
            printf("\n\n");
        }

    fclose(arquivo);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_sultapais(char arquivo_nome[]){
    card jogador;
    FILE *aqruivo;

    char busca_pais[30];
    
    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }

    printf("De qual pais gostaria de consultar seus jogadores?\n");
    fflush(stdin);
    gets(busca);

    while(fread(&jogador, sizeof(card), 1, arquivo) == 1)
        if(stricmp(jogador.pais,busca_pais)==0 && aluno.existe) {
        	printf("\n\n");
            printf("--G--U--T--2--0--2--3--\n");
            printf("\nNome: %s\n", jogador.nome);
            printf("Pais: %s\n", jogador.pais);
            printf("Posicao: %c\n", jogador.posicao);
            printf("Numero: %d\n", jogador.numero_camisa);
            printf("Overall: %d\n", jogador.overall);
            printf("--G--U--T--2--0--2--3--\n");
            printf("\n\n");
        }

    fclose(arquivo);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_ltera(char arquivo_nome[]){
    card jogador;
    FILE *arquivo;

    card_mostra(arquivo_nome);

    int busca_camisa, achou=0;

    if((arquivo = fopen(arquivo_nome, "r+b")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }

    printf("Digite o numero da camisa do jogador que ira alterar: ");
    scanf("%d", &busca_camisa);

    while(fread (&jogador, sizeof(card), 1, arquivo) == 1 && !achou)
        if(jogador.numero_camisa==busca_camisa){
           fflush(stdin);

            printf("Digite o nome do jogador que gostaria de cadastrar:\n");
            scanf("%s", jogador.nome);

            printf("Pais de origem:\n");
            scanf(" %s", jogador.pais);

            printf("Posicao em campo:    (A) - Atacante / (G) - Goleiro / (M) - Meio-Campista / (Z) - Zagueiro\n");
            scanf(" %c", jogador.posicao);

            printf("Numero da camisa: \n");
            scanf("%d", &jogador.numero_camisa);

            printf("Overall - pontos de habilidade na escala de 0 a 100: \n");
            scanf("%d", &jogador.overall);

            jogador.existe=TRUE;
        
            fseek(arquivo,-sizeof(card),SEEK_CUR);
        
            fwrite(&jogador,sizeof(card),1,arquivo);
        
            fflush(arquivo);
            achou = 1;
        }
    

    if(!achou) printf ("Nao existe jogador registrado com o numero %d.\n\n", busca_camisa);
    
    fclose(arquivo);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_banco(char arquivo_nome[]){
    /*para a exclusao logica, o jogador sera colocado no banco de reservas, podendo ser consultado usando a funcao card_mostrabanco*/
    card jogador;
    FILE *arquivo;

    card_mostra(arquivo_nome);

    int busca_camisa, achou=0;

    if((arquivo = fopen(arquivo_nome, "r+b")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }

    printf("Digite o numero da camisa do jogador que ira por no banco: ");
    scanf("%d", &busca_camisa);

    while(fread (&jogador, sizeof(card), 1, arquivo) == 1 && !achou)
        if(jogador.numero_camisa == busca_camisa){
    	    jogador.exist = FALSE;
    	    fseek(arquivo,-sizeof(card),SEEK_CUR);// Volta o ponteiro
    	    fwrite(&aluno,sizeof(card),1,arquivo);// Grava os dados lidos - alterados
    	    fflush (arquivo);
		    achou = 1;
    }
    
    if(!achou)printf ("Nao ha aluno cadastrado com RA %d.\n\n",numero);
    fclose(arquivo);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_mostrabanco(char arquivo_nome[]){

    card jogador;
    FILE *arquivo;

    if((arquivo = fopen(nomearq, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }

    if(!jogador.exist){
        printf("\n\n");
        printf("--G--U--T--2--0--2--3--\n");
        printf("\nNome: %s\n", jogador.nome);
        printf("Pais: %s\n", jogador.pais);
        printf("Posicao: %c\n", jogador.posicao);
        printf("Numero: %d\n", jogador.numero_camisa);
        printf("Overall: %d\n", jogador.overall);
        printf("--G--U--T--2--0--2--3--\n");
        printf("\n\n");
    }

    fclose(arquivo);

}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_desbanco(char arquivo_nome[]){
    
    card jogador;
    FILE *arquivo;

    card_mostrabanco(arquivo_nome);

    int busca_camisa, achou=0;

    if((arquivo = fopen(arquivo_nome, "r+b")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }

    printf("Digite o numero da camisa do jogador que ira escalar para o time principal: ");
    scanf("%d", &busca_camisa);

    while(fread (&jogador, sizeof(card), 1, arquivo) == 1 && !achou)
        if(jogador.numero_camisa == busca_camisa && !jogador.exist){
    	    jogador.exist = TRUE;
    	    fseek(arquivo,-sizeof(card),SEEK_CUR);
    	    fwrite(&aluno,sizeof(card),1,arquivo);
    	    fflush (arquivo);
		    achou = 1;
        }
    
    if(!achou)printf ("Nao existe jogador registrado com o numero %d no banco.\n\n", busca_camisa);
    fclose(arquivo);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_demissao(arquivo_nome[]){
    
}


























