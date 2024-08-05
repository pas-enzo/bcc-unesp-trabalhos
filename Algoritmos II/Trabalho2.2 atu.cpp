//GUT - Gullenheim Ultimate Team - arquivo binario

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
#define max 200
#define baixo 80 
#define cima 72 
#define esc 27 
#define enter 13 
#define f1 59
#define TRUE 1 
#define FALSE 0

void gotoxy (int x, int y){
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int SetColor (char color){
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}

void escreveTexto (int x, int y, char a[], int cor){
  int i;
  SetColor (cor);
  
  	for(i=0 ; a[i] !='\0' ; y++, i++){
  		gotoxy (y,x);
		printf("%c", a[i]);
		Sleep (0);
	}
}

void escreveTextos (int x, int y, char a[], int cor){

  		SetColor (cor);
  		gotoxy (y,x);
		printf("%s", a);
	
}
void escreveNum (int y, int x, int a, int cor){

  		SetColor (cor);
  		gotoxy (y,x);
		printf("%d", a);
	
}
int escreveTextoss (int y, int x, char a[], int cor){

  		SetColor (cor);
  		gotoxy (y,x);
		printf("%s", a);
	
}

int desenhacorpo(){
	char b[]={"/"}, c[]={"\\"}, a[]={"|"}, t[]={"_"};
	int i;
	int d=48, g=0; //cima

	//cima
	for(i=0 ; i<21 ; i++, d++){
	escreveTextoss(d, g, t, 2);
	}

	//cima pro corpo
	g++;
	escreveTextoss(48, g, a, 2);
	escreveTextoss(68, g, a, 2);
	
	int e=47, f=69;
	
	for(i=0 ; i<3 ; i++){
	escreveTextoss(e--, g, t, 2);
	escreveTextoss(f++, g, t, 2);
	}

	//corpo
	for(i=0 ; i<21 ; i++){
	g++;
	escreveTextoss(e, g, a, 2);
	escreveTextoss(f, g, a, 2);
	}
	
	//corpo pro baixo
	for(i=0 ; i<4 ; i++){
	escreveTextoss(e++, g++, c, 2);
}

	g-=4;
	
	//corpo pro baixo
	for(i=0 ; i<3 ; i++){
	escreveTextoss(f--, g++, b, 2);
}

	escreveTextoss(f--, g, b, 2);

	//cima
	for(i=0 ; i<21 ; i++, d++){
	escreveTextoss(d-21, g, t, 2);
	}
}

int desenhaperso (){
	char b[]={"/"}, c[]={"\\"}, a[]={"|"}, t[]={"_"}, z[]={"-"};
	int i;
		//cabeça
	int d=56, g=1; //cima da cabeça
	for(i=0 ; i<4 ; i++){
		escreveTextoss(d++, g, t, 2);
	}
	g++;
	int e=55, f=60; //lateral da cabeça
	for(i=0 ; i<3 ; i++, g++){
		escreveTextoss(e, g, a, 2);
		escreveTextoss(f, g, a, 2);
	}
	
	
	g--;d=56; //baixo da cabeça
	for(i=0 ; i<4 ; i++){
		escreveTextoss(d++, g, t, 2);
	}

	//camisa
	g++; d=54;
	for(i=0 ; i<8 ; i++){
		escreveTextoss(d++, g, t, 2);
	}
	
	//pescoço
	escreveTextoss(57, g, a, 2);
	escreveTextoss(58, g, a, 2);
	
	//camisa manga
	int h=53, j=62;
	g++;
	for(i=0 ; i<3 ; i++, g++){
		escreveTextoss(h--, g, b, 2);
		escreveTextoss(j++, g, c, 2);
	}
	
	g--;
	escreveTextoss(53, g, b, 2);
	escreveTextoss(62, g, c, 2);
	escreveTextoss(54, g, a, 2);
	escreveTextoss(61, g, a, 2);
	
	//faixa transitoria
	g++;
	int k=45;
	for(i=0 ; i<27 ; i++){
		escreveTextoss(k++, g, z, 2);
	}
}

int atribu(){
	char b[]={"/"}, c[]={"\\"}, a[]={"|"}, t[]={"_"}, z[]={"-"};
	int i;
	int cor=10;
	//7 branco
	//posição
	int g=13;
	escreveTextoss(61, g, "Pos:", 10);
	
	//over
	escreveTextoss(46, g, "Over: " , cor);
	
	g+=3;
	
	//pais
	escreveTextoss(46, g, "Pais: " , cor);
	
	//time
	escreveTextoss(62, g, "Time: " , cor);
}
  void menu (int op){
  char vet[][max] = {"Cadastra os Jogadores", "Mostra os Jogadores", "Consulta Overall","Consulta Pais",
   "Altera Atributos do Jogador", "Coloca jogador no Banco", "Mostra jogadores no banco", "Tira os jogadores do banco" };
  int i;
  system ("cls");
  for (i = 0; i < 9; i++)
    escreveTextos (3+i,10,vet[i],2);
  escreveTextos (2+op,10,vet[op-1],3);  
}
//-------------------------------------------------------------------------------------------------------------------------------------

/// @brief 
typedef struct {
	
	/*campos dos cartoes dos jogadores do time*/
	char nome[30];
	char pais[30];
	char posicao[30];
	char time[30];
	int overall;
	int numero_camisa;
	int existe;
	
} card;

//-------------------------------------------------------------------------------------------------------------------------------------

void card_astra(char arquivo_nome[]){
	//cadastro OK - enzo
	system ("cls");
    card registra;

    char resp[max];
    FILE *arquivo;

    if((arquivo = fopen(arquivo_nome, "a+b")) == NULL){
      printf ("\nErro da abertura do arquivo.\n\n");
      return;
}   
    
    /*Os 5 campos basicos necessarios para a existencia de um cartao de jogador no GUT: nome, pais, posicao, numero da camisa e coeficiente de habilidade(overall)*/
    
    do{

        fflush(stdin);
        printf("Digite o nome do jogador que gostaria de cadastrar:\n");
        gets(registra.nome);

		fflush(stdin);
        printf("Pais de origem:\n");
        gets(registra.pais);
		
		fflush(stdin);
        printf("Posicao em campo:    (A) - Atacante / (G) - Goleiro / (M) - Meio-Campista / (Z) -Zagueiro\n");
        gets(registra.posicao);

		fflush(stdin);
		printf("Time atual:\n");
        gets(registra.time);
        
        fflush(stdin);
        printf("Numero da camisa: \n");
        scanf("%d", &registra.numero_camisa);

		fflush(stdin);
        printf("Overall - pontos de habilidade na escala de 0 a 100: \n");
        scanf("%d", &registra.overall);

        registra.existe=1;

        fwrite(&registra, sizeof(card), 1, arquivo);

        printf("Cadastrar mais uma carta de jogador no seu time? (s/n)\n");
		scanf(" %s",&resp );
  } while (resp[0] == 'S' || resp[0] == 's');
  
  system("cls");
  printf("--G--U--T--2--0--2--3--> Pressione as setas para continuar <--G--U--T--2--0--2--3--");

    fclose(arquivo);

}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_mostra(char arquivo_nome[]){
	//mostra OK - sistema de setas - enzo
	system ("cls");
    card jogador;
    FILE *arquivo;
	char y;
	
    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
         getch();
        return;
    }
	while (fread (&jogador, sizeof(card), 1, arquivo) == 1){
    if(jogador.existe==1){
    	desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 11 , jogador.nome, 6);
		escreveNum(55, 6, jogador.numero_camisa, 8);
		escreveNum(52, 13,jogador.overall, 7);
		escreveTextoss(66, 13,jogador.posicao, 7);
		escreveTextoss(52, 16,jogador.pais, 7);
		escreveTextoss(66, 16,jogador.time, 7);
      	getch();
      		

	   //"--G--U--T--2--0--2--3--\n"

}
}
    fclose(arquivo);
//	getch();

}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_sultaover(char arquivo_nome[]){
	//consulta de overall OK - sisteam de setas - enzo
	system ("cls");
    card jogador;
    FILE *arquivo;

    int over_high, over_low;

    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        getch();
        return;
    }

    printf("Qual faixa de Overall Gostaria de consultar?\n");
    printf("Menor Overall da consulta: ");
    scanf("%d", &over_low);
    printf("\nMaior Overall da consulta: ");
    scanf("%d", &over_high);

    while(fread(&jogador, sizeof(card), 1, arquivo) == 1)
        if((jogador.overall>over_low && jogador.overall<over_high) && jogador.existe) {

    	desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 11 , jogador.nome, 6);
		escreveNum(55, 6, jogador.numero_camisa, 8);
		escreveNum(52, 13,jogador.overall, 7);
		escreveTextoss(66, 13,jogador.posicao, 7);
		escreveTextoss(52, 16,jogador.pais, 7);
		escreveTextoss(66, 16,jogador.time, 7);
      	getch();
        }

    fclose(arquivo);
   // getch();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_sultapais(char arquivo_nome[]){
    system ("cls");
	card jogador;
    FILE *arquivo;

    char busca[30];
    
    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        getch();
        return;
    }

    printf("De qual pais gostaria de consultar seus jogadores?\n");
    fflush(stdin);
    gets(busca);
    
    system("cls");

    while(fread(&jogador, sizeof(card), 1, arquivo) == 1)
        if(stricmp(jogador.pais,busca)==0 && jogador.existe==1) {
  
    	desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 11 , jogador.nome, 6);
		escreveNum(55, 6, jogador.numero_camisa, 8);
		escreveNum(52, 13,jogador.overall, 7);
		escreveTextoss(66, 13,jogador.posicao, 7);
		escreveTextoss(52, 16,jogador.pais, 7);
		escreveTextoss(66, 16,jogador.time, 7);
      	getch();
        }

    fclose(arquivo);
  //  getch();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_ltera(char arquivo_nome[]){
    system ("cls");
	card jogador;
    FILE *arquivo;

    card_mostra(arquivo_nome);

    int busca_camisa, achou=0;

    if((arquivo = fopen(arquivo_nome, "r+b")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }
    
    system ("cls");

    printf("Digite o numero da camisa do jogador que ira alterar: ");
    scanf("%d", &busca_camisa);
    
    system ("cls");

    while(fread (&jogador, sizeof(card), 1, arquivo) == 1 && !achou)
        if(jogador.numero_camisa==busca_camisa){
           fflush(stdin);

            printf("%s\n\n", jogador.nome);

			fflush(stdin);
      		printf("Pais de origem:\n");
      		gets(jogador.pais);
		
			fflush(stdin);
       		printf("Posicao em campo:    (A) - Atacante / (G) - Goleiro / (M) - Meio-Campista / (Z) -Zagueiro\n");
      		gets(jogador.posicao);

			fflush(stdin);
			printf("Time atual:\n");
        	gets(jogador.time);
        
        	fflush(stdin);
        	printf("Numero da camisa: \n");
        	scanf("%d", &jogador.numero_camisa);

			fflush(stdin);
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
 //   getch();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_banco(char arquivo_nome[]){
	  system ("cls");
/*para a exclusao logica, o jogador sera colocado no banco de reservas, podendo ser consultado usando a 
funcao card_mostrabanco*/
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
    	    jogador.existe = FALSE;
    	    fseek(arquivo,-sizeof(card),SEEK_CUR);// Volta o ponteiro
    	    fwrite(&jogador,sizeof(card),1,arquivo);// Grava os dados lidos - alterados
    	    fflush (arquivo);
		    achou = 1;
    }
    
    if(!achou) printf ("Nao existe jogador registrado com o numero %d.\n\n", busca_camisa);
    fclose(arquivo);
  //  getch();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_mostrabanco(char arquivo_nome[]){
	system ("cls");
    card jogador;
    FILE *arquivo;

    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }
while (fread (&jogador, sizeof(card), 1, arquivo) == 1)
    if(jogador.existe==0){

    	desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 11 , jogador.nome, 6);
		escreveNum(55, 6, jogador.numero_camisa, 8);
		escreveNum(52, 13,jogador.overall, 7);
		escreveTextoss(66, 13,jogador.posicao, 7);
		escreveTextoss(52, 16,jogador.pais, 7);
		escreveTextoss(66, 16,jogador.time, 7);
      	getch();
    }

    fclose(arquivo);
   // getch();

}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_desbanco(char arquivo_nome[]){
    system ("cls");
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
        if(jogador.numero_camisa == busca_camisa && !jogador.existe){
    	    jogador.existe = TRUE;
    	    fseek(arquivo,-sizeof(card),SEEK_CUR);
    	    fwrite(&jogador,sizeof(card),1,arquivo);
    	    fflush (arquivo);
		    achou = 1;
        }
    
    if(!achou)printf ("Nao existe jogador registrado com o numero %d no banco.\n\n", busca_camisa);
    fclose(arquivo);
 //   getch();
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_demissao(char arquivo_nome[]){
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

int main() {
  char opcao, nome_arquivo[30];
  	int x=8, y=40;
  	char a[max*max];
	
	strcat(a,"Trabalho 2 - Algoritmos II");
	escreveTexto(x,y,a, 2);
	strcpy(a,"Enzo Campanholo Paschoalini - RA 221026215");
	escreveTexto(x+1,y-8,a, 2);
	strcpy(a,"Thiago Bigotte Gullo - RA 221026241");
	escreveTexto(x+2,y-4,a, 2);
	strcpy(a,"GUT - Gullenheim Ultimate Team");
	escreveTexto(x+3,y,a, 2);	
	Sleep (10000);
	system("cls");
	
	SetColor(2);
	
	int verif;
	int repro;
	int op;
  	char t;
  	op = 1;
  	
  	do{
	  
  printf("Nome do arquivo a ser manipulado: ");
  gets (nome_arquivo);
  
  printf ("\n\n\n\n\n\n\n\n\n\t\t--G--U--T--2--0--2--3--> Pressione as setas para continuar <--G--U--T--2--0--2--3--");
  
  
   do{
	t = getch();
	// se for caracter especial
	if (t <= 0){
	  t = getch();
	  if (t == baixo){
	    if (op != 9) op++;
		else op = 1;
		menu (op);
	  }
	  else if (t == cima) {
	  	if (op != 1) op--;
		else op = 9;
		menu (op);
	  }
	  else if (t == f1);
	  
	       // ajuda();
    }
    else{
    	if (t == enter){
    		if(op==1){
    			card_astra(nome_arquivo);
    		
			}
			
			if(op==2){
				card_mostra(nome_arquivo);
			}
			
			if(op==3){
				card_sultaover(nome_arquivo);
			}
			
			if(op==4){
				card_sultapais(nome_arquivo);
			}
			
			if(op==5){
				card_ltera(nome_arquivo);
			}
			
			if(op==6){
				card_banco(nome_arquivo);
			}
			
			if(op==7){
				card_mostrabanco(nome_arquivo);
			}
			
			if(op==8){
				card_desbanco(nome_arquivo);
			}
			
			if(op==9){
				t=esc;
			}
		}
	}
	
	} while (t != esc);
	
		printf("\n\nPressione 0 se gostaria de reiniciar o programa.\n");
		scanf("%d", &repro);
		
		printf("\n\n");
		
		system("cls");
		
		printf("\nReiniciando!\n");
		
		printf("\n\n");

	}while(repro==0);
	
	system("cls");
	
	printf("\nMuito Obrigado!\n");	
	
	printf("\n\n");
	
	return 0;

}
