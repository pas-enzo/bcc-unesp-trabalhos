//GUT - Gullenheim Ultimate Team - arquivo binario

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
#define max 500
#define baixo 80 
#define cima 72 
#define dir 75
#define esq 77
#define esc 27 
#define enter 13 
#define f1 59
#define TRUE 1 
#define FALSE 0

//-------------------------------------------------------------------------------------------------------------------------------------

void gotoxy (int x, int y){
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//-------------------------------------------------------------------------------------------------------------------------------------

int SetColor (char color){
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void escreveTexto (int x, int y, char a[], int cor){
  int i;
  SetColor (cor);
  
  	for(i=0 ; a[i] !='\0' ; y++, i++){
  		gotoxy (y,x);
		printf("%c", a[i]);
		Sleep (0);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------

void escreveTextos (int x, int y, char a[], int cor){

  		SetColor (cor);
  		gotoxy (y,x);
		printf("%s", a);
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void escreveNum (int y, int x, int a, int cor){

  		SetColor (cor);
  		gotoxy (y,x);
		printf("%d", a);
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

int escreveTextoss (int y, int x, char a[], int cor){

  		SetColor (cor);
  		gotoxy (y,x);
		printf("%s", a);
	
}

//-------------------------------------------------------------------------------------------------------------------------------------

int desenhacorpo(){
	char b[]={"/"}, c[]={"\\"}, a[]={"|"}, t[]={"_"};
	int i;
	int d=48, g=0; //cima

	//cima
	for(i=0 ; i<25 ; i++, d++){
	escreveTextoss(d, g, t, 2);
	}

	//cima pro corpo
	g++;
	escreveTextoss(48, g, a, 2);
	escreveTextoss(72, g, a, 2);
	
	int e=47, f=73;
	
	for(i=0 ; i<3 ; i++){
	escreveTextoss(e--, g, t, 2);
	escreveTextoss(f++, g, t, 2);
	}

	//corpo
	for(i=0 ; i<16 ; i++){
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

	//baixo
	for(i=0 ; i<24 ; i++, d++){
	escreveTextoss(d-25, g, t, 2);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------

int desenhaperso (){
	char b[]={"/"}, c[]={"\\"}, a[]={"|"}, t[]={"_"}, z[]={"-"};
	int i;
		//cabeça
	int d=59, g=1; //cima da cabeça
	for(i=0 ; i<4 ; i++){
		escreveTextoss(d++, g, t, 2);
	}
	g++;
	int e=58, f=63; //lateral da cabeça
	for(i=0 ; i<3 ; i++, g++){
		escreveTextoss(e, g, a, 2);
		escreveTextoss(f, g, a, 2);
	}
	
	
	g--;d=59; //baixo da cabeça
	for(i=0 ; i<4 ; i++){
		escreveTextoss(d++, g, t, 2);
	}

	//camisa
	g++; d=57;
	for(i=0 ; i<8 ; i++){
		escreveTextoss(d++, g, t, 2);
	}
	
	//pescoço
	escreveTextoss(60, g, a, 2);
	escreveTextoss(61, g, a, 2);
	
	//camisa manga
	int h=56, j=65;
	g++;
	for(i=0 ; i<3 ; i++, g++){
		escreveTextoss(h--, g, b, 2);
		escreveTextoss(j++, g, c, 2);
	}
	
	g--;
	escreveTextoss(56, g, b, 2);
	escreveTextoss(65, g, c, 2);
	escreveTextoss(57, g, a, 2);
	escreveTextoss(64, g, a, 2);
	
	//faixa transitoria
	g++;
	int k=45;
	for(i=0 ; i<30 ; i++){
		escreveTextoss(k++, g, z, 2);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------

int atribu(){
	char b[]={"/"}, c[]={"\\"}, a[]={"|"}, t[]={"_"}, z[]={"-"};
	int i;
	int cor=10;
	//7 branco
	//posição
	int g=13;
	escreveTextoss(62, g, "Pos:", 10);
	
	//over
	escreveTextoss(46, g, "Over: " , cor);
	
	g+=3;
	
	//pais
	escreveTextoss(46, g, "Pais: " , cor);
	
	//time
	escreveTextoss(62, g, "Time: " , cor);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void menu (int op){
//	G u l l e n h e i m U l t i m a t e T e a m	
 char vet[][max] = {"<GUT23>  Cadastra os Jogadores        <GUT23>", "<GUT23>  Mostra os Jogadores          <GUT23>", 
 					"<GUT23>  Consulta Overall             <GUT23>","<GUT23>  Consulta Pais                <GUT23>",  "<GUT23>  Altera Atributos do Jogador  <GUT23>", 
 					"<GUT23>  Coloca jogador no Banco      <GUT23>", "<GUT23>  Mostra jogadores no banco    <GUT23>", "<GUT23>  Tira os jogadores do banco   <GUT23>" ,
 					"<GUT23>  Vender Jogador               <GUT23>","<GUT23>  Ajuda - F1                   <GUT23>","<GUT23>  Sair - esc                   <GUT23>"};
  
  int i;
 	
	 system ("cls");
	escreveTexto (1,0,"            (                                     *   )               )               )               )              )           ",11);
	escreveTexto (2,0,"            )\ )                  (             ` )  /(            ( /(            ( /(            ( /(           ( /(            ",11);
	escreveTexto (3,0,"  ___   ___(()/(   ___   ___      )\  ___   ___  ( )(_))___   ___  )(_))___   ___  )\())___   ___  )(_))___  ___  )\())___   ___ ",11);
	escreveTexto (4,0," |___| |___|/(_))_|___| |___|  _ ((_)|___| |___|(_(_())|___| |___|((_) |___| |___|((_)\|___| |___|((_) |___||___|((_)\|___| |___| ",11);
	escreveTexto (5,0,"           (_)) __|           | | | |           |_   _|           |_  )           /  (_)          |_  )         |__ (_)          ",11);
	escreveTexto (6,0,"             | (_ |           | |_| |             | |              / /           | () |            / /           |_ \             ",11);
	escreveTexto (7,0,"              \\___|            \\___/              |_|             /___|           \\__/            /___|         |___/             ",11);

  for (i = 0; i < 11; i++)
  
    escreveTextos (11+i,40,vet[i],11);
  escreveTextos (10+op,40,vet[op-1],3);  
}

//-------------------------------------------------------------------------------------------------------------------------------------

typedef struct {
	
	/*campos dos cartoes dos jogadores do time*/
	char nome[30];
	char pais[30];
	char posicao[30];
	char time[30];
	int overall;
	int numero_camisa;
	int existe;
	int apag;
	
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
    
/*Os 5 campos basicos necessarios para a existencia de um cartao de jogador no GUT: 
nome, pais, posicao, numero da camisa e coeficiente de habilidade(overall)*/
    
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
    	registra.apag=0;

        fwrite(&registra, sizeof(card), 1, arquivo);

        printf("Cadastrar mais uma carta de jogador no seu time? (s/n)\n");
		scanf(" %s",&resp );
  } while (resp[0] == 'S' || resp[0] == 's');
  
  system("cls");
  printf("--G--U--T--2--0--2--3--> Pressione as setas para continuar <--G--U--T--2--0--2--3--");

    fclose(arquivo);

}

//-------------------------------------------------------------------------------------------------------------------------------------

int conta(char arq[]){
	card jogador;
    FILE *arquivo;
   
       if((arquivo = fopen(arq, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
         getch();
     return 0;
 }
    int fim=0;
    	while (fread (&jogador, sizeof(card), 1, arquivo) == 1 ){
    
	if(jogador.existe==1){
		fim++;
	}
}

return fim;
fclose(arquivo);
}

//-------------------------------------------------------------------------------------------------------------------------------------

int contaf(char arq[]){
	card jogador;
    FILE *arquivo;
   
       if((arquivo = fopen(arq, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
         getch();
     return 0;
 }
    int fim=0;
    	while (fread (&jogador, sizeof(card), 1, arquivo) == 1 ){
    
	if(jogador.existe!=1){
		fim++;
	}
}

return fim;
fclose(arquivo);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_mostra1(char arquivo_nome[]){
	//mostra OK - sistema de setas - enzo
	system ("cls");
    card jogador;
    FILE *arquivo;
    int fim=0;
	char y;
	int cc;
	char *c, b[max], d[max];

    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
         getch();
        return;
    }
    int cont=1;
    fim=conta(arquivo_nome);
	while (fread (&jogador, sizeof(card), 1, arquivo) == 1 ){
    
	if(jogador.existe==1){
   		system("cls");	
		desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 10 , jogador.nome, 6);
		escreveNum(58, 6, jogador.numero_camisa, 8);
		escreveNum(51, 13,jogador.overall, 7);
		escreveTextoss(67, 13,jogador.posicao, 7);
		escreveTextoss(51, 16,jogador.pais, 7);
		cc=strlen(jogador.time);
		
		if(cc>8){	
	c = strtok (jogador.time," .");
	strcpy(b, c);
	c = strtok(NULL,"  .");
	
 	while (c != NULL) {
 	strcpy(d, c);
 	c = strtok(NULL,"  "); 
 	}
 		escreveTextoss(67, 16,b, 7);
 		escreveTextoss(65, 17,d, 7);
		}
		else	escreveTextoss(67, 16,jogador.time, 7);
		escreveTextoss(25, 27, "--G--U--T--2--0--2--3--> Gullenheim Ultimate Team <--G--U--T--2--0--2--3--", 11);
      	fflush(stdin);
       if(cont<=0)cont=1;
       
		escreveNum(60, 22, cont++, 7);
		  
		//setas
		if(cont!=2)
		escreveTextoss(56, 22,"< -", 7);

		if(cont!=fim+1){
		escreveTextoss(62, 22,"- >", 7);
	}
		else {
		escreveTextoss(62, 22,"   ", 7);
		escreveTextoss(46, 23, "Pressione <- ou -> para rever", 8);
		escreveTextoss(44, 24, "Pressione cima ou baixo para sair", 8);
	
}
		  y=getch();	
	   //"--G--U--T--2--0--2--3--\n"
}
 
 		if(y==75){
			cont-=3;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=1);
	}
		
		if(y==77){
			cont-=1;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=1);
		}
		
}
	
	y=getch();
	if(y==77){
	card_mostra1(arquivo_nome);
	cont=1;
}
	if(y==75){
	card_mostra1(arquivo_nome);
	cont=1;
}

    fclose(arquivo);

}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_mostra(char arquivo_nome[]){
	//mostra OK - sistema de setas - enzo
	system ("cls");
    card jogador;
    FILE *arquivo;
    int fim=0;
	char y;
	int cc;
	char *c, b[max], d[max];

    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
         getch();
        return;
    }
    int cont=1;
    fim=conta(arquivo_nome);
	while (fread (&jogador, sizeof(card), 1, arquivo) == 1 ){
    
	if(jogador.existe==1){
   		system("cls");	
		desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 10 , jogador.nome, 6);
		escreveNum(58, 6, jogador.numero_camisa, 8);
		escreveNum(51, 13,jogador.overall, 7);
		escreveTextoss(67, 13,jogador.posicao, 7);
		escreveTextoss(51, 16,jogador.pais, 7);
		cc=strlen(jogador.time);
		
		if(cc>8){	
	c = strtok (jogador.time," .");
	strcpy(b, c);
	c = strtok(NULL,"  .");
	
 	while (c != NULL) {
 	strcpy(d, c);
 	c = strtok(NULL,"  "); 
 	}
 		escreveTextoss(67, 16,b, 7);
 		escreveTextoss(65, 17,d, 7);
		}
		else	escreveTextoss(67, 16,jogador.time, 7);
		escreveTextoss(25, 27, "--G--U--T--2--0--2--3--> Gullenheim Ultimate Team <--G--U--T--2--0--2--3--", 11);
      	fflush(stdin);
       if(cont<=0)cont=1;
       
		escreveNum(60, 22, cont++, 7);
		  
		//setas
		if(cont!=2)
		escreveTextoss(56, 22,"< -", 7);

		if(cont!=fim+1){
		escreveTextoss(62, 22,"- >", 7);
	}
		else {
		escreveTextoss(62, 22,"   ", 7);
		escreveTextoss(46, 23, "Pressione <- ou -> para rever", 8);
		escreveTextoss(44, 24, "Pressione cima ou baixo para sair", 8);
}
		  y=getch();	
	   //"--G--U--T--2--0--2--3--\n"
}
 
 		if(y==75){
			cont-=3;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=1);
	}
		
		if(y==77){
			cont-=1;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=1);
		}
		
}
	
	y=getch();
	if(y==77){
	card_mostra(arquivo_nome);
	cont=1;
}
	if(y==75){
	card_mostra(arquivo_nome);
	cont=1;
}

    fclose(arquivo);

}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_sultaover(char arquivo_nome[]){
	//consulta de overall OK - sisteam de setas - enzo
	system ("cls");
    card jogador;
    FILE *arquivo;
	char y;
	int cc;
	char *c, b[max], d[max];
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
    int cont=1;
    int fim=0;
    fim=conta(arquivo_nome);
    while(fread(&jogador, sizeof(card), 1, arquivo) == 1){
        if((jogador.overall>over_low && jogador.overall<over_high) && jogador.existe) {
   		system("cls");	
		desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 10 , jogador.nome, 6);
		escreveNum(58, 6, jogador.numero_camisa, 8);
		escreveNum(51, 13,jogador.overall, 7);
		escreveTextoss(67, 13,jogador.posicao, 7);
		escreveTextoss(51, 16,jogador.pais, 7);
			cc=strlen(jogador.time);
		
		if(cc>8){	
	c = strtok (jogador.time," .");
	strcpy(b, c);
	c = strtok(NULL,"  .");
	
 	while (c != NULL) {
 	strcpy(d, c);
 	c = strtok(NULL,"  "); 
 	}
 		escreveTextoss(67, 16,b, 7);
 		escreveTextoss(65, 17,d, 7);
		}
		else	escreveTextoss(67, 16,jogador.time, 7);
		escreveTextoss(25, 25, "--G--U--T--2--0--2--3--> Gullenheim Ultimate Team <--G--U--T--2--0--2--3--", 11);

      	fflush(stdin);
       if(cont<=0)cont=1;
       
		escreveNum(60, 22, cont++, 7);
		  
		//setas
		if(cont!=2)
		escreveTextoss(56, 22,"< -", 7);

		if(cont!=fim+1){
		escreveTextoss(62, 22,"- >", 7);
	}
		else{
		 escreveTextoss(62, 22,"   ", 7);
		escreveTextoss(46, 23, "Pressione <- ou -> para rever", 8);
		escreveTextoss(44, 24, "Pressione cima ou baixo para sair", 8);
}
		  y=getch();	
	 

		if(y==75){
			cont-=3;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=1);
	}
		
		if(y==77){
			cont-=1;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=1);
		}
		
}
	escreveTextoss(62, 22,"    ", 7);
	y=getch();
	if(y==77){
	card_mostra(arquivo_nome);
	cont=1;
}
	if(y==75){
	card_mostra(arquivo_nome);
	cont=1;
}
}

    fclose(arquivo);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_sultapais(char arquivo_nome[]){
    system ("cls");
	card jogador;
    FILE *arquivo;
	int cc;
	char *c, b[max], d[max];
    char busca[30];
    char y;
    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        getch();
        return;
    }

    printf("De qual pais gostaria de consultar seus jogadores?\n");
    fflush(stdin);
    gets(busca);
    
    system("cls");
    int cont=1;
    int fim=0 ;
    fim=contaf(arquivo_nome);
    while(fread(&jogador, sizeof(card), 1, arquivo) == 1){
	
        if(stricmp(jogador.pais,busca)==0 && jogador.existe==1) {
   		system("cls");	
		desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 10 , jogador.nome, 6);
		escreveNum(58, 6, jogador.numero_camisa, 8);
		escreveNum(51, 13,jogador.overall, 7);
		escreveTextoss(67, 13,jogador.posicao, 7);
		escreveTextoss(51, 16,jogador.pais, 7);
		cc=strlen(jogador.time);
		
		if(cc>8){	
		c = strtok (jogador.time," .");
		strcpy(b, c);
		c = strtok(NULL,"  .");
	
 	while (c != NULL) {
 		strcpy(d, c);
 		c = strtok(NULL,"  "); 
}
 		escreveTextoss(67, 16,b, 7);
 		escreveTextoss(65, 17,d, 7);
		}
		else	escreveTextoss(67, 16,jogador.time, 7);
		
		escreveTextoss(25, 25, "--G--U--T--2--0--2--3--> Gullenheim Ultimate Team <--G--U--T--2--0--2--3--", 11);

      	fflush(stdin);
       if(cont<=0)cont=1;
       
		escreveNum(60, 22, cont++, 7);
		  
		//setas
		if(cont!=2)
		escreveTextoss(56, 22,"< -", 7);

		if(cont!=fim+1){
		escreveTextoss(62, 22,"- >", 7);
	}
		else{
		 escreveTextoss(62, 22,"   ", 7);
		escreveTextoss(46, 23, "Pressione <- ou -> para rever", 8);
}
		  y=getch();	
	   //"--G--U--T--2--0--2--3--\n"

		if(y==75){
			cont-=3;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=1);
	}
		
		if(y==77){
			cont-=1;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=1);
		}
		
}
	escreveTextoss(62, 22,"    ", 7);
	y=getch();
	if(y==77){
	card_mostra(arquivo_nome);
	cont=1;
}
	if(y==75){
	card_mostra(arquivo_nome);
	cont=1;
}
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

    escreveTextoss(35, 25,"Digite o numero da camisa do jogador que ira alterar: ", 11 );
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
    

    if(!achou){
    	
    	escreveTextoss(43, 26,"Nao existe jogador com esse numero.", 11 );
    	escreveTextoss(20, 27, "--G--U--T--2--0--2--3--> Pressione as setas para continuar <--G--U--T--2--0--2--3--", 11);
	}
    
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


    int busca_camisa, achou=0;

	
    if((arquivo = fopen(arquivo_nome, "r+b")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }

	card_mostra1(arquivo_nome);
    
   	escreveTextoss(32, 25,"Digite o numero da camisa do jogador que ira por no banco: ", 11 );
	scanf("%d", &busca_camisa);

    while(fread (&jogador, sizeof(card), 1, arquivo) == 1){
        if(jogador.numero_camisa == busca_camisa){
    	    jogador.existe = 0;
    	    fseek(arquivo,-sizeof(card),SEEK_CUR);// Volta o ponteiro
    	    fwrite(&jogador,sizeof(card),1,arquivo);// Grava os dados lidos - alterados
    	    fflush (arquivo);
		    achou = 1;
    }
}
    
    if(!achou) {
	escreveTextoss(43, 26,"Nenhum jogador tem o numero digitado", 11 );
    
}
    escreveTextoss(20, 28,"--G--U--T--2--0--2--3--> Pressione as setas para continuar <--G--U--T--2--0--2--3--", 11);

    fclose(arquivo);
 	
}

//-------------------------------------------------------------------------------------------------------------------------------------

void card_mostrabanco(char arquivo_nome[]){
	system ("cls");
    card jogador;
    FILE *arquivo;

    int fim=0;
    char y;
    int cc;
	char *c, b[max], d[max];
    
    if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        return;
    }
     int cont=1;
    fim=contaf(arquivo_nome);
    
while (fread (&jogador, sizeof(card), 1, arquivo) == 1){

    if(jogador.existe==0){
   		system("cls");	
		desenhacorpo();
		desenhaperso();
		atribu();
		
		escreveTextoss(55, 10 , jogador.nome, 6);
		escreveNum(58, 6, jogador.numero_camisa, 8);
		escreveNum(51, 13,jogador.overall, 7);
		escreveTextoss(67, 13,jogador.posicao, 7);
		escreveTextoss(51, 16,jogador.pais, 7);
		cc=strlen(jogador.time);
		
		if(cc>8){	
	c = strtok (jogador.time," .");
	strcpy(b, c);
	c = strtok(NULL,"  .");
	
 	while (c != NULL) {
 	strcpy(d, c);
 	c = strtok(NULL,"  "); 
 	}
 		escreveTextoss(67, 16,b, 7);
 		escreveTextoss(65, 17,d, 7);
		}
		else	escreveTextoss(67, 16,jogador.time, 7);
		escreveTextoss(25, 27, "--G--U--T--2--0--2--3--> Gullenheim Ultimate Team <--G--U--T--2--0--2--3--", 11);

      	fflush(stdin);
       if(cont<=0)cont=1;
       
		escreveNum(60, 22, cont++, 7);
		  
		//setas
		if(cont!=2)
		escreveTextoss(56, 22,"< -", 7);

		if(cont!=fim+1){
		escreveTextoss(62, 22,"- >", 7);
	}
		else {
		escreveTextoss(62, 22,"   ", 7);
		escreveTextoss(46, 23, "Pressione <- ou -> para rever", 8);
		escreveTextoss(44, 24, "Pressione cima ou baixo para sair", 8);
}
		  y=getch();	
	   //"--G--U--T--2--0--2--3--\n"

		if(y==75){
			cont-=3;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=0);
	}
		
		if(y==77){
			cont-=1;
			do{
			fseek(arquivo,-sizeof(card),SEEK_CUR);
		}while(jogador.existe!=0);
		}
		
}

}
	
	y=getch();
	if(y==77){
	card_mostrabanco(arquivo_nome);
	cont=1;
}
	if(y==75){
	card_mostrabanco(arquivo_nome);
	cont=1;
}

    

    fclose(arquivo);

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

	escreveTextoss(24, 25,"Digite o numero da camisa do jogador que ira escalar para o time principal: ", 11 );

    scanf("%d", &busca_camisa);

    while(fread (&jogador, sizeof(card), 1, arquivo) == 1 && !achou)
        if(jogador.numero_camisa == busca_camisa && !jogador.existe){
    	    jogador.existe = TRUE;
    	    fseek(arquivo,-sizeof(card),SEEK_CUR);
    	    fwrite(&jogador,sizeof(card),1,arquivo);
    	    fflush (arquivo);
		    achou = 1;
        }
    
    if(!achou) escreveTextoss(39, 26,"Nenhum jogador do banco tem o numero digitado", 11 );
    
    	escreveTextoss(20, 27,"--G--U--T--2--0--2--3--> Pressione as setas para continuar <--G--U--T--2--0--2--3--",11);
    fclose(arquivo);
 //   getch();
}

//-------------------------------------------------------------------------------------------------------------------------------------

int card_demissao(char arquivo_nome[]){
	FILE *arquivo, *arquivo1;
	card jog, jog1;
	char numstr[30], nome[30];
	
	if((arquivo = fopen(arquivo_nome, "rb")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        getch();
        return 0;
    }
    
    if((arquivo = fopen("NOME.BAK", "w+b")) == NULL){
        printf ("\n Erro de abertura de arquivo.\n\n");
        getch();
        return 0;
    }
    
    system("cls");
    
    printf("Digite o nome do jogador que sera vendido: \n");
    fflush(stdin);
	gets(nome);
    
  // Leitura dos registros  
  while (fread (&jog, sizeof(card), 1, arquivo) == 1){

    if (stricmp(jog.nome,nome)==0)jog.apag=1;

	if(!jog.apag){
      // Grava os dados lidos - alterados
      fwrite(&jog1,sizeof(card),1,arquivo1);
      fclose(arquivo);
      fclose(arquivo1);
    //  remove(arquivo);
      rename("NOME.BAK", arquivo_nome);
      fflush (arquivo);
    }
    
	}
    
    fclose(arquivo);
    fclose(arquivo1);
}

//-------------------------------------------------------------------------------------------------------------------------------------

void ajuda(){
	FILE *arquivo;
	char caracter;
	int i;
  
    
	if ((arquivo = fopen( "ajudacrpfin.txt", "rt")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
     exit(1);
  }
	
	system("cls");
  
	//ler arquivo
	for (i=0; i<=808 ; i++){
	
	if(i==64 || i==132 || i==205 || i==265 || i==266 || i==294 || i==324 || i==377 || i==448 || i==499 || i==541 || i==565 || i==566 || i==616 || i==679
	|| i==723 || i==724)
		printf("\n");
	
	caracter = getc(arquivo);
	fflush(stdin);
    printf("%c", caracter-2);
} 
  fclose(arquivo);

}

//-------------------------------------------------------------------------------------------------------------------------------------

int main() {
  char opcao, nome_arquivo[30];
  	int x=8, y=40;
  	char a[max*max];
	
	strcat(a,"Trabalho 2 - Algoritmos II");
	escreveTexto(x,y,a, 3);
	strcpy(a,"Enzo Campanholo Paschoalini - RA 221026215");
	escreveTexto(x+1,y-8,a, 11);
	strcpy(a,"Thiago Bigotte Gullo - RA 221026241");
	escreveTexto(x+2,y-4,a, 3);
	strcpy(a,"GUT - Gullenheim Ultimate Team");
	escreveTexto(x+3,y,a, 11);	
	Sleep (3900);
	system("cls");
	
	SetColor(2);
	
	int verif;
	//char repro[200];
	int reproi;
	int op;
  	char t;
  	op = 1;
  	int ado;
  	do{
	  system("cls");
	escreveTexto (1,0,"            (                                     *   )               )               )               )              )           ",11);
	escreveTexto (2,0,"            )\ )                  (             ` )  /(            ( /(            ( /(            ( /(           ( /(            ",11);
	escreveTexto (3,0,"  ___   ___(()/(   ___   ___      )\  ___   ___  ( )(_))___   ___  )(_))___   ___  )\())___   ___  )(_))___  ___  )\())___   ___ ",11);
	escreveTexto (4,0," |___| |___|/(_))_|___| |___|  _ ((_)|___| |___|(_(_())|___| |___|((_) |___| |___|((_)\|___| |___|((_) |___||___|((_)\|___| |___| ",11);
	escreveTexto (5,0,"           (_)) __|           | | | |           |_   _|           |_  )           /  (_)          |_  )         |__ (_)          ",11);
	escreveTexto (6,0,"             | (_ |           | |_| |             | |              / /           | () |            / /           |_ \             ",11);
	escreveTexto (7,0,"              \\___|            \\___/              |_|             /___|           \\__/            /___|         |___/             ",11);
	escreveTexto (23,0," (             (   (                 )                            (     )                      )         *   )                    ",11);
	escreveTexto (24,0," )\\ )      (   )\\  )\\   (         ( /(    (   (      )        (   )\\ ( /( (      )       )  ( /(   (   ` )  /(   (     )     )   ",11);
	escreveTexto (25,0,"(()/(     ))\\ ((_)((_) ))\\  (     )\\())  ))\\  )\\    (         )\\ ((_))\\()))\\    (     ( /(  )\\()) ))\\   ( )(_)) ))\\ ( /(    (     ",11);
	escreveTexto (26,0," /(_))_  /((_) _   _  /((_) )\\ ) ((_)\  /((_)((_)   )\\  '  _ ((_) _ (_))/((_)   )\\  ' )(_))(_))/ /((_) (_(_()) /((_))(_))   )\\  ' ",11);
	escreveTexto (27,0,"(_)) __|(_))( | | | |(_))  _(_/( | |(_)(_))   (_) _((_))  | | | || || |_  (_) _((_)) ((_)_ | |_ (_))   |_   _|(_)) ((_)_  _((_))  ",11);
	escreveTexto (28,0,"  | (_ || || || | | |/ -_)| ' \\))| ' \\ / -_)  | || '  \\() | |_| || ||  _| | || '  \\()/ _` ||  _|/ -_)    | |  / -_)/ _` || '  \\() ",11);
	escreveTexto (29,0,"   \\___| \\_,_||_| |_|\\___||_||_| |_||_|\\___|  |_||_|_|_|   \\___/ |_| \\__| |_||_|_|_| \\__,_| \\__|\\___|    |_|  \\___|\\__,_||_|_|_|  ",11);
  
  escreveTextos(11,20, "Nome do arquivo a ser manipulado: ", 11);
  scanf(" %s", &nome_arquivo);
  
escreveTextos(20, 20, "--G--U--T--2--0--2--3--> Pressione as setas para continuar <--G--U--T--2--0--2--3--", 11);

  
   do{
	t = getch();
	// se for caracter especial
	if (t <= 0){
	  t = getch();
	  if (t == baixo){
	    if (op != 11) op++;
		else op = 1;
		menu (op);
	  }
	  else if (t == cima) {
	  	if (op != 1) op--;
		else op = 11;
		menu (op);
	  }
	  else if (t == f1)ajuda();
	  
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
				card_demissao(nome_arquivo);
			}
			
			if(op==10){
				ajuda();
			}
			
			if(op==11){
				t=esc;
			}
		}
	}
	
	} while (t != esc);
		
        system("cls");
		
        printf("\n\nPressione 0 se gostaria de reiniciar o programa.\n");
		scanf("%d", &reproi);
		//reproi=atoi(repro);
		printf("\n\n");
		
		system("cls");
		
		printf("\nReiniciando!\n");
		
		printf("\n\n");

	}while(reproi == 0);
	
	system("cls");
	
	printf("\nMuito obrigado por jogar Gullenheim Ultimate Team!\n");	
	
	printf("\n\n");
	
	return 0;
}
