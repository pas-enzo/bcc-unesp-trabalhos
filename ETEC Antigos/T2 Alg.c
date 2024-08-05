#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define size 15 
#define TRUE 1
#define FALSE 0
#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59

/*Funcoes para as operacoes*/
int lermatriz(int a[][size], int n);
	
void printmatriz(int a[][size], int n);	

int linesxy(int a[][size], int n);

int columnsxy(int a[][size], int n);

int diagonalswap(int a[][size], int n);

void symetrytest(int a[][size], int n);

void magico(int a[][size], int n);

void permuta(int a[][size], int n);

void latino(int a[][size], int n);
//-------------------------------------------------------------------------



/*Funcoes para o menu interativo*/
void ajuda ();

void gotoxy (int x, int y);

int SetColor (char color);

void escreveTexto (int x, int y, char texto[], int cor);

void menu (int op);

/*int func_menu(int a[][size], int n);*/
//-------------------------------------------------------------------------



int main(){
	
	int a[size][size];
	int n;
	int repro=0;
	
	SetColor(2);
	
	printf("Trabalho 2 - Algoritmos 1\n");
	printf("Enzo Campanholo Paschoalini - RA 221026215\n");
	printf("Operacoes com Matrizes utilizando Funcoes\n");
	printf("\nEM CORES!\n");
	
	do{
		do{
			printf("\nDigite a dimensao da matriz quadrada entre 1 e 15: \n");
			scanf("%d", &n);
		}while(n<1 || n>15);
		
		printf("\n\n");
		
		lermatriz(a, n);
	
		  	int op;
  	char t;
  	op = 1;
  	menu (op);
  	
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
	  else if (t == f1)
	         ajuda();
    }
    else{
    	if (t == enter){
    		if(op==1){
    			lermatriz(a, n);
    			//break;
			}
			
			if(op==2){
				printmatriz(a, n);
				//break;
			}
			
			if(op==3){
				linesxy(a, n);
				//break;
			}
			
			if(op==4){
				columnsxy(a, n);
				//break;
			}
			
			if(op==5){
				diagonalswap(a, n);
				//break;
			}
			
			if(op==6){
				symetrytest(a, n);
				//break;
			}
			
			if(op==7){
				magico(a, n);
				//break;
			}
			
			if(op==8){
				latino(a, n);
				//break;
			}
			
			if(op==9){
				permuta(a, n);
				//break;
			}
			
			if(op==10){
				ajuda();
				//break;
			}
			
			if(op==11){
				t = esc;
				//break;
			}
		}
	}
	
	} while (t != esc);
	
		printf("\n\nPressione 0 se gostaria de criar outra matriz.\n");
		scanf("%d", &repro);
		
		printf("\n\n");
		
		system("cls");
		
		printf("\nReiniciando!\n");
		
		printf("\n\n");

	}while(repro==0);
	
	system("cls");
	
	printf("\nMuito Obrigado!\n");	
	
	printf("\nAte o proximo semestre!\n");
	
	
	return 0;
}
//-------------------------------------------------------------------------


int lermatriz(int a[][size], int n){
	
	int i, j;
	
	system ("cls");
	
	printf("\nInsira os valores da matriz: \n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j]=fabs(a[i][j]);
		}
	}
	
	printf("\nMatriz lida com sucesso!\n");
	
	printf("\nOs elementos da matriz estarao sempre em modulo!\n");
	
	printf("\nPressione enter para ler novamente ou pressione as setas para continuar.\n");

	printf("\n\n");
	
	return a[size][size];
}

void printmatriz(int a[][size], int n){

	int i, j;
	
	system ("cls");
	
	printf("\nMatriz: \n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPressione as setas para continuar.\n");
	
}
//-------------------------------------------------------------------------
int linesxy(int a[][size], int n){
	
	int i, j, x, y;
	int temp;
	
	system ("cls");
	
	do{
		printf("\nDigite as linhas a serem trocadas:\n");
		scanf("%d%d", &x, &y);
			x--;
			y--;
			
			if(y<x){
				temp = x;
				x = y;
				y = temp;
			}
					
	}while((x<0 || x>n-1) || (y<0 || y>n-1));
	
	temp=0;
	
	for(j=0;j<n;j++){
		temp = a[x][j];
		a[x][j] = a[y][j];
		a[y][j] = temp;
	}
	
	printf("\nLinhas trocadas com sucesso!\n");
	
	printf("\nPressione enter para trocar novamente ou pressione as setas para continuar.\n");
	
	printf("\n\n");
	
	return a[size][size];
	
}
//-------------------------------------------------------------------------
int columnsxy(int a[][size], int n){

	int i, j, x, y;
	int temp;
	
	system ("cls");
	
	do{
		printf("\nDigite as colunas a serem trocadas:\n");
		scanf("%d%d", &x, &y);
			x--;
			y--;
			
			if(y<x){
				temp = x;
				x = y;
				y = temp;
			}
					
	}while((x<0 || x>n-1) || (y<0 || y>n-1));
	
	temp=0;
	
	for(i=0;i<n;i++){
		temp = a[i][x];
		a[i][x] = a[i][y];
		a[i][y] = temp;
	}
	
	printf("\nColunas trocadas com sucesso!\n");
	
	printf("\nPressione enter para trocar novamente ou pressione as setas para continuar.\n");
	
	printf("\n\n");
	
	return a[size][size];
}
//-------------------------------------------------------------------------
int diagonalswap(int a[][size], int n){

	int i, j, skip;
	int temp;
	
	system ("cls");
	
	skip=n-1;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				temp=a[i][j];
				a[i][j]=a[i][j+skip];
				a[i][j+skip]=temp;
				skip-=2;
			}
		}
	}
	
	printf("\nDiagonais trocadas com sucesso!\n");
	
	printf("\nPressione enter para trocar novamente ou pressione as setas para continuar.\n");
	
	printf("\n\n");
	
	return a[size][size];
}
//-------------------------------------------------------------------------
void symetrytest(int a[][size], int n){

	int i, j;
	int find=0;
	
	system ("cls");
	
	for(i=0;i<n;i++){
		for(j=0;j<n && !find;j++){
			if(a[i][j]!=a[j][i])find=1;
		}
		if(find==1)break;
	}
	
	if(find==1)printf("\nA matriz nao eh simetrica!\n");
	
	else printf("\nA matriz eh simetrica!\n");
	
	printf("\nPressione as setas para continuar.\n");
	
	printf("\n\n");
	
}
//-------------------------------------------------------------------------
void magico(int a[][size], int n){
	
	int i, j, soma_inicial, soma1, soma2, igual = TRUE;
	
	system ("cls");
	
	soma_inicial = 0;
    soma2 = 0;
    
    for (j = 0; j < n; j++){
        soma_inicial += a[0][j];
        soma2 += a[j][0];
    }

    igual = soma_inicial == soma2;

    for (i = 1; igual && i < n; i++) {
        // soma1 --> soma da linha i
        // soma2 --> soma da coluna i 
        
        soma1 = 0;
        soma2 = 0;
        for (j = 0; j < n; j++){
            soma1 += a[i][j];
            soma2 += a[j][i];
        }

        igual = (soma1 == soma2 && soma2 == soma_inicial);
    }

    if (igual){
        //Calcula a soma das diagonais
        soma1 = 0;
        soma2 = 0;
        for (j = 0; j < n; j++){
            soma1 += a[j][j];
            soma2 += a[j][n-j-1];
        }
        igual = (soma1 == soma2 && soma2 == soma_inicial);
    }
    
    if (igual)
        printf("\nA matriz eh um quadrado magico!\n");
    else
        printf("\nA matriz nao eh um quadrado magico!\n");
        
        printf("\nPressione as setas para continuar.\n");
        
    	printf("\n\n");
}
//-------------------------------------------------------------------------
void permuta(int a[][size], int n){
	
	int i, j, soma_inicial, soma1, soma2, igual = TRUE;
	
	system ("cls");
	
	soma_inicial = 0;
    soma2 = 0;
    
    for (j = 0; j < n; j++){
        soma_inicial += a[0][j];
        soma2 += a[j][0];
    }
    
    if(soma_inicial!=TRUE){
    	printf("\n A matriz nao eh de permutacao!\n");
	}
	
	else{

    igual = soma_inicial == soma2;

    for (i = 1; igual && i < n; i++) {
        // soma1 --> soma da linha i
        // soma2 --> soma da coluna i 
        
        soma1 = 0;
        soma2 = 0;
        for (j = 0; j < n; j++){
            soma1 += a[i][j];
            soma2 += a[j][i];
        }

        igual = (soma1 == soma2 && soma2 == soma_inicial);
    }


    if (igual)
        printf("\nA matriz eh de permutacao!\n");
    else
        printf("\nA matriz nao eh de permutacao!\n");
	}
	
	printf("\nPressione as setas para continuar.\n");
	
	printf("\n\n");
	
}
//-------------------------------------------------------------------------
void latino(int a[][size], int n){
	
    int i, j, k, vet[n], flag=0;
    
    system ("cls");

    for (i = 0; i < n; i++) {
        vet[i] = 0;
        for (j = 0; j < n; j++) {
            vet[i] += a[i][j];
            for (k = 0; k < n; k++)
                if (a[i][j] == a[i][k] && j != k) flag++;
        }
    }
	
    for (i = 0; i < n - 1; i++)
        if (vet[i] != vet[i + 1]) flag++;

    for (j = 0; j < n; j++) {
        vet[j] = 0;
        for (i = 0; i < n; i++) {
            vet[j] += a[i][j];
            for (k = 0; k < n; k++)
                if (a[i][j] == a[k][j] && i != k) flag++;
        }
    }

    for (i = 0; i < n - 1; i++)
    if (vet[i] != vet[i + 1]) flag++;
        
    if(flag >=1){
    	printf("\nA matriz nao eh quadrado latino\n");
	}
   	else
   	printf("\nA matriz eh quadrado latino\n");
   	
   	printf("\nPressione as setas para continuar.\n");
   	
   	printf("\n\n");
}
//-------------------------------------------------------------------------
void ajuda (){
	system("cls");
	printf("\n--> DICAS E AJUDA <--\n\n");
	printf("\n<^> Utilize as setas no teclado para navegar o menu.\n");
	printf("\n<^> Pressione Enter para selecionar a opcao desejada.\n");
	printf("\n<^> Quando o programa confirmar a operacao, podera realizar uma nova operacao.\n");
	printf("\n<^> Pressione Esc ou selecione a opcao 'Sair' para finalizar o programa.\n");
	printf("\n<^> Para abrir a tela de ajuda novamente, pressione F1 ou escolha a opcao 'Ajuda'.\n");
	printf("\n\nPressione as setas para continuar.\n");
	printf("\n\n");
	
}
//-------------------------------------------------------------------------
void gotoxy (int x, int y){
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//-------------------------------------------------------------------------
int SetColor (char color){
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}
//-------------------------------------------------------------------------
void escreveTexto (int x, int y, char texto[], int cor){
  SetColor (cor);
  gotoxy (y,x);
  printf ("%s",texto);
}
//-------------------------------------------------------------------------
void menu (int op){
  char vet[][50] = {"<^> Ler matriz <^>", "<^> Imprimir Matriz <^>", "<^> Trocar 2 linhas <^>"
  , "<^> Trocar 2 Colunas <^>", "<^> Trocar as diagonais <^>", "<^> Verificar simetria <^>", 
  "<^> Verificar o quadrado magico <^>", "<^> Verificar quadrado latino <^>", "<^> Verificar matriz de permutacao <^>", 
  "<^> Ajuda - F1 <^>", "<^> Sair - Esc <^>" };
  int i;
  system ("cls");
  for (i = 0; i < 11; i++)
    escreveTexto (3+i,10,vet[i],2);
  escreveTexto (2+op,10,vet[op-1],3);  
}
//-------------------------------------------------------------------------
/*int func_menu(int a[][size], int n){
	
  	int op;
  	char t;
  	op = 1;
  	menu (op);
  	
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
	  else if (t == f1)
	         ajuda();
    }
    else{
    	if (t == enter){
    		if(op==1){
    			lermatriz(a, n);
    			break;
			}
			
			if(op==2){
				printmatriz(a, n);
				break;
			}
			
			if(op==3){
				linesxy(a, n);
				break;
			}
			
			if(op==4){
				columnsxy(a, n);
				break;
			}
			
			if(op==5){
				diagonalswap(a, n);
				break;
			}
			
			if(op==6){
				symetrytest(a, n);
				break;
			}
			
			if(op==7){
				magico(a, n);
				break;
			}
			
			if(op==8){
				latino(a, n);
				break;
			}
			
			if(op==9){
				permuta(a, n);
				break;
			}
			
			if(op==10){
				ajuda();
				break;
			}
			
			if(op==11){
				t = esc;
				break;
			}
		}
	}
	
	} while (t != esc);
}*/
