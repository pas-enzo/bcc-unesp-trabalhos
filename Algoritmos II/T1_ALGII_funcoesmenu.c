//-------------------------------------------------------------------------
void ajuda (){
	
		system("cls");
		printf("\n--> DICAS E AJUDA <--\n\n");
		printf("\n<G> Utilize as setas no teclado para navegar o menu.\n");
		printf("\n<G> Pressione Enter para selecionar a opcao desejada.\n");
		printf("\n<G> Uma vez realizada a operacao desejada, podera fazer outra operacao.\n");
		printf("\n<G> Pressione Esc ou selecione a opcao 'Sair' para finalizar o programa.\n");
		printf("\n<G> Para abrir a tela de ajuda novamente, pressione F1 ou escolha a opcao 'Ajuda'.\n");
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
  char vet[][50] = {"<G> Sacar notas <G>", "<G> Preenchimento automatico de cheques <G>", 
  "<G> Ajuda - F1 <G>", "<G> Sair - Esc <G>" };
  int i;
  system ("cls");
  for (i = 0; i < 11; i++)
    escreveTexto (3+i,10,vet[i],2);
  escreveTexto (2+op,10,vet[op-1],3);  
}
//-------------------------------------------------------------------------
void sobrenos(){
	
	system("cls");
	printf("\n--> DICAS E AJUDA <--\n\n");
		printf("\n<G> O banco internacional Gullenheim foi fundado no ano\n");
		printf("\n<G> de 1922 pelos cientistas Afonso Paschoalini e Pedro Gullo, \n");
		printf("\n<G> que enxergaram no mundo financeiro uma nova maneira de revolucionar\n");
		printf("\n<G> o padrao de atendimento por meio de novas tecnologias que surgiam. Desde\n");
		printf("\n<G> entao, lideram o mundo dos negocios por meio de interfaces amigaveis e coloridas.\n");
		printf("\n<G> para atender seus clientes e garantir a satisfacao 100% das vezes.\n");
		printf("\n\nPressione as setas para continuar.\n");
		printf("\n\n");	
}

//EXEMPLO DE COMO MONTAR A MAIN SEGUNDO O MENU INTERATIVO
/*int main(){
	
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
//-------------------------------------------------------------------------*/