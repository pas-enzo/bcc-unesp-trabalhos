//Sistemas Lineares - Métodos Numéricos Computacionais
/*Trabalho feito por:
	Enzo Campanholo Paschoalini - RA: 221026215
	Manuele S. Christófalo - RA: 221029261
	Paulo Henrique de Camargo Dionysio Martins - RA: 221026169
	Thiago Bigotte Gullo - RA: 221026241
*/
//UNESP Bauru - 11/06/2023

#include <bits/stdc++.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
using namespace std;

#define ESC 27
#define ENTER 13
#define BACKSPACE 8
#define UP 72
#define DOWN 80

#define BRANCO 15
#define CINZA_ESCURO 8
#define CINZA 7
#define VERDE 10
#define AZUL 9
#define CIANO 11
#define VERMELHO 12

#define MAX 10

int n;
double M[MAX][MAX], B[MAX], X[MAX], inversa[MAX][MAX];

//FORMATAÇÃO ==========================================================================================================
void gotoxy(int x, int y){ //Posição do cursor
	COORD pos={x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursor(bool val){ //Esconde o cursor
   HANDLE consoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize=10;
   info.bVisible=val;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int SetColor(char color){ //Cor
	HANDLE h;
	h=GetStdHandle(STD_OUTPUT_HANDLE);
	return SetConsoleTextAttribute(h,color);
}

void limpaTela(){ //Limpa a tela
	system("cls");
	SetColor(CINZA);
}

void menuSelecao(int pos){ //Menu de Seleção
	limpaTela();
	SetColor(CINZA); cout << "\n Qual a operacao desejada?\n\n\n"; SetColor(BRANCO);
	cout << "  Calcular o determinante" << endl;
	cout << "  Resolver sistema triangular inferior" << endl;
	cout << "  Resolver sistema triangular superior" << endl;
	cout << "  Resolver por Decomposicao LU" << endl;
	cout << "  Resolver por Cholesky" << endl;
	cout << "  Resolver por Gauss Compacto" << endl;
	cout << "  Resolver por Gauss-Jordan" << endl;
	cout << "  Resolver por Jacobi" << endl;
	cout << "  Resolver por Gauss-Seidel" << endl;
	cout << "  Calcular matriz inversa por Decomposicao LU" << endl;
	cout << "  Calcular matriz inversa por Gauss Compacto" << endl;
	cout << "  SAIR";

	switch(pos){
		case 1: gotoxy(2, 4); SetColor(CINZA); cout << "  Calcular o determinante" << endl; break;
		case 2: gotoxy(2, 5); SetColor(CINZA); cout << "  Resolver sistema triangular inferior" << endl; break;
		case 3: gotoxy(2, 6); SetColor(CINZA); cout << "  Resolver sistema triangular superior" << endl; break;
		case 4: gotoxy(2, 7); SetColor(CINZA); cout << "  Resolver por Decomposicao LU" << endl; break;
		case 5: gotoxy(2, 8); SetColor(CINZA); cout << "  Resolver por Cholesky" << endl; break;
		case 6: gotoxy(2, 9); SetColor(CINZA); cout << "  Resolver por Gauss Compacto" << endl; break;
		case 7: gotoxy(2, 10); SetColor(CINZA); cout << "  Resolver por Gauss-Jordan" << endl; break;
		case 8: gotoxy(2, 11); SetColor(CINZA); cout << "  Resolver por Jacobi" << endl; break;
		case 9: gotoxy(2, 12); SetColor(CINZA); cout << "  Resolver por Gauss-Seidel" << endl; break;
		case 10: gotoxy(2, 13); SetColor(CINZA); cout << "  Calcular matriz inversa por Decomposicao LU" << endl; break;
		case 11: gotoxy(2, 14); SetColor(CINZA); cout << "  Calcular matriz inversa por Gauss Compacto" << endl; break;
		case 12: gotoxy(2, 15); SetColor(VERMELHO); cout << "  SAIR"; break;
	}
}

bool voltaMenu(){ //Opção tentar ou voltar
	char saida='a'; cursor(false);
	SetColor(BRANCO); cout << endl << endl << endl << endl << "Pressione ";
	SetColor(AZUL); cout << "<ENTER>"; SetColor(BRANCO); cout << " para tentar com outros valores ou ";
	SetColor(AZUL); cout << "<ESC>"; SetColor(BRANCO); cout << " para voltar ao menu de opcoes.";
	while(saida!=ENTER && saida!=ESC) saida=getch();

	if(saida==ESC) return 1;
	return 0;
}


//FUNÇÕES BASE ========================================================================================================
void insereMatriz(){ //Inserção da matriz para cada opção
	n=11; 
	SetColor(BRANCO); cout << endl << endl << endl << "Digite a ordem da sua matriz (max. " << MAX << "): ";
	while(n>10 || n<1){
		gotoxy(40, 3); cout << "          "; gotoxy(40, 3);
		SetColor(CINZA); cin >> n;
	}

	SetColor(BRANCO); cout << endl << "Insira a sua matriz (" << n << "x" << n << "):" << endl; SetColor(CINZA);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> M[i][j];
		}
	}
}

double Determinante(int n, double matriz[][MAX]){ //Calcula determinante
	if(n==1) return matriz[0][0]; //Matriz de n 1
	else{
		double resp=0;
		int jj, ii;

		for(int i=0; i<n; i++){
			if(matriz[0][i]!=0){ //Sempre escolhe a linha 0 para calcular
				double matrizAux[10][10];
				ii=jj=0;
				
				for(int linha=1; linha<n; linha++){ //Como escolheu a linha 0, compara com linha 1 da inicial
					for(int col=0; col<n; col++){
						if(col!=i){ //Exclusão da coluna 
							matrizAux[ii][jj]=matriz[linha][col];
							jj++;
						}
					}

					ii++;	//Linha montada -> soma para a próxima coluna
					jj=0;
				}

				double pivo=(i%2==0)? matriz[0][i] : -matriz[0][i];
				resp=resp+pivo*Determinante(n-1, matrizAux);
			}
		}

		return resp;
	}
}

bool simetrica(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) if(M[i][j]!=M[j][i]) return false;
	}

	return true;
}

void printaX(){
	SetColor(VERDE); cout << endl << endl << "Vetor X (solucao):" << endl; SetColor(VERDE);
	cout << "X=(";
	for(int i=0; i<n; i++){
		if(X[i]>=0.001 || X[i]<=-0.001) cout << fixed << setprecision(3) << X[i];
		else cout << 0;

		if(i!=n-1) cout << "  ";
	}
	cout << ")";
}

bool CriterioLinhas(){
	for(int i=0; i<n; i++){
        double soma=0;
        for(int j=0; j<n; j++){
            if(j!=i) soma+=M[i][j];
        }
        if(M[i][i]<=soma) return false;
    }
    return true;
}

bool CriterioColunas(){
	for(int j=0; j<n; j++){
        double soma=0;
        for(int i=0; i<n; i++){
            if(i!=j) soma+=M[i][j];
        }
        if(M[j][j]<=soma) return false;
    }
    return true;
}

bool CriterioSassenfield(){
    double beta[MAX];
    double soma;

    for(int i=0; i<n; i++){
        soma=0;
        for(int j=0; j<n; j++){
            if(j!=i) soma+=fabs(M[i][j]);
        }
        beta[i]=soma/fabs(M[i][i]);
    }

    float maiorBeta=beta[0];
    for(int i=1; i<n; i++){
        if(beta[i] > maiorBeta) maiorBeta=beta[i];
    }

    if(maiorBeta<1) return true;
    return false;
}


//TRIANGULO INFERIOR E SUPERIOR =======================================================================================
void TriInferior(int n, double M[][MAX], double B[], double X[]){
	for(int i=0 ; i<n ; i++){
			if(i==0) X[0]=B[0]/M[0][0];
			else{
				double soma=0;
				for(int j=0; j<i; j++) soma+=M[i][j]*X[j];
				X[i]=(B[i]-soma)/M[i][i];
			}
	}
}

void TriSuperior(int n, double M[][MAX], double B[], double X[]){
	for(int i=n-1; i>=0; i--){
		if(i==n-1) X[i]=B[i]/M[i][i];
		else{
			double soma=0;
			for(int j=i+1; j<n; j++) soma+=M[i][j]*X[j];
			X[i]=(B[i]-soma)/M[i][i];
		}
	}
}


//DECOMPOSIÇÃO LU =====================================================================================================	
void MatrizU(int i, int n, double M[][MAX], double L[][MAX], double U[][MAX]){
    for(int j=0; j<n; j++){
        if(i==0) U[i][j]=M[i][j];

        else{
			double soma=0;
			for(int k=0; k<i; k++) soma+=L[i][k]*U[k][j];
            U[i][j]=M[i][j]-soma;
        }
    }
}

void MatrizL(int j, int n, double M[][MAX], double L[][MAX], double U[][MAX]){
    for(int i=0; i<n; i++){
        if(j==0) L[i][j]=M[i][j]/U[j][j];
        else{
			double soma=0;
			for(int k=0; k<j; k++) soma+=L[i][k]*U[k][j];
            L[i][j]=(M[i][j]-soma)/U[j][j];
        }
    }
}

void SistemaLU(int n, double L[][MAX], double U[][MAX], double B[], double X[]){
    int i, j;
    double Y[MAX];

    //Ly=B
    Y[0]=B[0] / L[0][0];
    for(i=1; i<n; i++){
        double soma=0;
        for(j=0; j<i; j++) soma += L[i][j] * Y[j];
        Y[i]=(B[i] - soma) / L[i][i];
    }

    //Ux=y
    X[n - 1]=Y[n - 1] / U[n - 1][n - 1];
    for(i=n - 2; i >= 0; i--){
        double soma=0;
        for(j=i + 1; j<n; j++) soma += U[i][j] * X[j];
        X[i]=(Y[i] - soma) / U[i][i];
    }
}

void DecomposicaoLU(int n, double M[][MAX], double B[], double X[]){
    double U[MAX][MAX], L[MAX][MAX];

    for(int i=0; i<n; i++){
        MatrizU(i, n, M, L, U);
        MatrizL(i, n, M, L, U);
    }

	SetColor(CINZA); cout << endl << endl << endl << "Matriz L:" << endl; SetColor(BRANCO);
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++) cout << fixed << setprecision(3) << L[i][j] << "  ";

        cout << endl;
    }

	SetColor(CINZA); cout << endl << endl << endl << "Matriz U:" << endl; SetColor(BRANCO);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
			if(i>j) cout << "       ";
			else cout << fixed << setprecision(3) << U[i][j] << "  ";
		}

        cout << endl;
    }

    SistemaLU(n, L, U, B, X);
}


//CHOLENSKY ===========================================================================================================
void DiagPrincipal(int i, double matriz[][MAX], double L[][MAX]){
    if(i==0) L[0][0]=sqrt(matriz[0][0]);
	
	else{
		double soma=0;
		for(int k=0; k<i; k++) soma+=pow(L[i][k], 2);
		L[i][i]=sqrt(matriz[i][i]-soma);
	}
}

void OutrosElem(int i, int j, double matriz[][MAX], double L[][MAX]){
    if(i==0){
        L[i][j]=matriz[i][j] / L[i][i];
        L[j][i]=L[i][j];
    }
	
	else{
		double soma=0;
		for(int k=0; k<j; k++) soma+=L[i][k]*L[j][k];
		L[i][j]=(matriz[i][j]-soma)/L[j][j];
	}
}

void EquacaoLY(int n, double L[][MAX], double Y[], double B[]){
	SetColor(CINZA); cout << endl << "Vetor Y:" << endl; SetColor(BRANCO);

    for(int i=0; i<n; i++){
        double soma=B[i];

        for(int j=0; j<i; j++) soma-=L[i][j]*Y[j];

        Y[i]=soma/L[i][i];
		cout << fixed << setprecision(3) << Y[i] << "  ";
    }
}

void EquacaoXY(double n, double Lt[][MAX], double X[], double Y[]){
    for(int i=n-1; i>=0; i--){
        double soma=Y[i];
        for(int j=n-1; j>i; j--) soma-=Lt[i][j]*X[j];

        X[i]=soma/Lt[i][i];
    }
}

void Cholesky(int n, double matriz[][MAX], double B[], double X[]){
    double L[10][10];

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++) OutrosElem(i, j, matriz, L);
        DiagPrincipal(i, matriz, L);
    }


    double Y[10];
    EquacaoLY(n, L, Y, B);

	SetColor(CINZA); cout << endl << endl << endl << "Matriz L:" << endl; SetColor(BRANCO);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << fixed << setprecision(3) << L[i][j] << "  ";

        cout << endl;
    }


    double Lt[10][10];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Lt[i][j]=L[j][i];
        }
    }

	SetColor(CINZA); cout << endl << endl << "L Transposta:" << endl; SetColor(BRANCO);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << fixed << setprecision(3) << Lt[i][j] << "  ";

        cout << endl;
    }

    EquacaoXY(n, Lt, X, Y);
}


//GAUSS COMPACTO ======================================================================================================
void GaussCompacto(int n, double M[][MAX], double B[], double X[]){
    double aux;

    for(int k=0; k<n-1; k++){
        for(int i=k+1; i<n; i++){
            aux=M[i][k]/M[k][k];
            B[i]-=aux*B[k];

            for(int j=k; j<n; j++) M[i][j]-=aux*M[k][j];
        }
    }

	SetColor(CINZA); cout << endl << endl << endl << "Matriz LU:" << endl; SetColor(BRANCO);
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
			if(j==n) cout << fixed << setprecision(3) << B[i] << endl;
			else cout << fixed << setprecision(3) << M[i][j] << "  ";
		}
    }

	X[n-1]=B[n-1]/M[n-1][n-1];

    for(int i=n-2; i>=0; i--){
        aux=B[i];
        for(int j=i+1; j<n; j++) aux-=M[i][j]*X[j];

        X[i]=aux/M[i][i];
    }
}


//GAUSS JORDAN ========================================================================================================
bool GaussJordan(int n, double M[][MAX], double B[MAX], double X[MAX]){
    double matrizAumentada[MAX][MAX+1];

    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            if(j==n) matrizAumentada[i][j]=B[i];
            else matrizAumentada[i][j]=M[i][j];
        }
    }

    for(int i=0; i<n; i++){
        double pivo=matrizAumentada[i][i];

        if(pivo==0) return 0; //Sistema indeterminado
		else{
            for(int j=i; j<=n; j++) matrizAumentada[i][j]/=pivo;

            for(int k=0; k<n; k++){
                if(k!=i){
                    double fator=matrizAumentada[k][i];
                    for(int j=i; j<=n; j++) matrizAumentada[k][j]-=fator*matrizAumentada[i][j];
                }
            }
        }
    }

    for(int i=0; i<n; i++) X[i]=matrizAumentada[i][n];
	return 1;
}


//JACOBI ==============================================================================================================
void Jacobi(int n, double M[][MAX], double vetorB[], double aproximacao[], double e, int maxIter, double X[], int* iteracoes){
    double temp[MAX];
    int i, j, iter;

    for(iter=1; iter<=maxIter; iter++){
        double erro=0.0;

        for(i=0; i<n; i++){
            temp[i]=vetorB[i];
            for(j=0; j<n; j++){
                if(i!=j) temp[i]-=M[i][j]*aproximacao[j];
            }
            temp[i]/=M[i][i];
        }

        for(i=0; i<n; i++) erro+=(temp[i]-aproximacao[i]) *(temp[i] - aproximacao[i]);

        for(i=0; i<n; i++) aproximacao[i]=temp[i];

        if(erro<e) break;
    }

    for(i=0; i<n; i++) X[i]=aproximacao[i];

    *iteracoes=iter;
}


//GAUSS SEIDEL ========================================================================================================
void GaussSeidel(int ordem, double matriz[][MAX], double B[], double aproximacao[], double e, int maxIter, double X[], int* iteracoes){
    double aprox_atual[MAX], aprox_anterior[MAX];
    double diferenca;
    int iteracao;

    for(int i=0; i<ordem; i++) aprox_atual[i]=aproximacao[i];

    for(iteracao=0; iteracao<maxIter; iteracao++){
        for(int i=0; i<ordem; i++) aprox_anterior[i]=aprox_atual[i];

        for(int i=0; i<ordem; i++){
            double soma=0;
            for(int j=0; j<ordem; j++){
                if(j != i) soma += matriz[i][j] * aprox_atual[j];
            }

            aprox_atual[i]=(B[i] - soma) / matriz[i][i];
        }

        diferenca=0;
        for(int i=0; i<ordem; i++) diferenca += fabs(aprox_atual[i] - aprox_anterior[i]);

        if(diferenca<e) break;
    }

    for(int i=0; i<ordem; i++) X[i]=aprox_atual[i];

    *iteracoes=iteracao;
}

//MATRIZ INVERSA =======================================================================================================
void SistInversaLU(int ordem, double matriz[][MAX], double L[][MAX], double U[][MAX]){
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            U[i][j]=matriz[i][j];
        }
    }

    for(int k=0; k<ordem; k++){
        L[k][k]=1.0;

        for(int i=k + 1; i<ordem; i++){
            L[i][k]=U[i][k] / U[k][k];
            for(int j=k; j<ordem; j++){
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
    }
}

void InversaLU(int ordem, double matriz[][MAX], double inversa[][MAX]){
    double L[MAX][MAX];
    double U[MAX][MAX];
    double identidade[MAX][MAX];

    //Inicialização da identidade
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            if(i==j) identidade[i][j]=1;
        	else identidade[i][j]=0;
        }
    }

    SistInversaLU(ordem, matriz, L, U);

    //Ssistema Ly=I
    for(int k=0; k<ordem; k++){
        double y[MAX];

        for(int i=0; i<ordem; i++){
            double soma=0;
            for(int j=0; j<i; j++) soma+=L[i][j]*y[j];

            y[i]=(identidade[i][k]-soma)/L[i][i];
        }

        //Sistema Ux=y
        for(int i=ordem-1; i>=0; i--){
            double soma=0;
            for(int j=i+1; j<ordem; j++) soma+=U[i][j]*inversa[j][k];
            
            inversa[i][k]=(y[i]-soma)/U[i][i];
        }
    }

	SetColor(CINZA); cout << endl << endl << endl << "Matriz L:" << endl; SetColor(BRANCO);
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++) cout << fixed << setprecision(3) << L[i][j] << "  ";

        cout << endl;
    }

	SetColor(CINZA); cout << endl << endl << endl << "Matriz U:" << endl; SetColor(BRANCO);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
			if(i>j) cout << "       ";
			else cout << fixed << setprecision(3) << U[i][j] << "  ";
		}

        cout << endl;
    }
}

void InversaGauss(int ordem, double matriz[][MAX], double inversa[][MAX]){
    double matriz_aumentada[MAX][2*MAX];
    
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            matriz_aumentada[i][j]=matriz[i][j];
            matriz_aumentada[i][j+ordem]=(i==j) ? 1.0 : 0.0;
        }
    }

	SetColor(CINZA); cout << endl << endl << endl << "Matriz aumentada:" << endl; SetColor(BRANCO);
    for(int i=0; i<n; i++){
        for(int j=0; j<n*2; j++) cout << fixed << setprecision(3) << matriz_aumentada[i][j] << "  ";
		cout << endl;
    }

    //Gauss compacto:
    for(int i=0; i<ordem; i++){
        double pivo=matriz_aumentada[i][i];

        if(pivo==0){
            int troca=0;

            for(int j=i+1; j<ordem; j++){
                if(matriz_aumentada[j][i]!=0){
                    troca=1;
                    for(int k=0; k<2 * ordem; k++){
                        double aux=matriz_aumentada[i][k];
                        matriz_aumentada[i][k]=matriz_aumentada[j][k];
                        matriz_aumentada[j][k]=aux;
                    }
                    break;
                }
            }

            if(troca==0){
                SetColor(VERMELHO);
				cout << "A matriz nao eh invertivel";
                return;
            }

            pivo=matriz_aumentada[i][i];
        }

        for(int j=0; j<2 * ordem; j++) matriz_aumentada[i][j] /= pivo;

        for(int k=0; k<ordem; k++){
            if(k!=i){
                double fator=matriz_aumentada[k][i];
                for(int j=0; j<2 * ordem; j++) matriz_aumentada[k][j] -= fator * matriz_aumentada[i][j];
            }
        }
    }

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++) inversa[i][j]=matriz_aumentada[i][j+ordem];
    }
}

//MAIN ================================================================================================================
int main(){
	HWND console=GetConsoleWindow();
 	RECT r;
  	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 400, TRUE);
	setlocale(LC_ALL, "Portuguese_Brasil");

	bool ON=true;
	int pos;
	char selecao;
	

	//PARTE 1: PROGRAMA
	while(ON==true){
		selecao='a'; pos=1;

		while(selecao!=ENTER){ //1.0 - Controle do menu
			cursor(false);
			menuSelecao(pos);

			if(pos==12) SetColor(VERMELHO);
			else SetColor(AZUL);

			gotoxy(0, 3+pos); cout << ">";

			selecao=getch();
			if(pos!=12) if(selecao==DOWN) pos++;
			if(pos!=1) if(selecao==UP) pos--;
		}
			
		

		//PARTE 2: SELEÇÃO FEITA
		while(pos==1){ //2.1 - Calcular determinante
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Calcular o determinante"; SetColor(BRANCO);

			insereMatriz(); //Leitura da matriz

			SetColor(VERDE); cout << endl << endl << endl << "-> ";
			SetColor(BRANCO); cout << "O determinante eh: ";

			SetColor(VERDE); cout << "det(M)=" << Determinante(n, M); //Calculo do determinante

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==2){ //2.2 - Sistema Triangular Inferior
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Resolver sistema triangular inferior"; SetColor(BRANCO);

			n=11;
			SetColor(BRANCO); cout << endl << endl << endl << "Digite a ordem da sua matriz (max. " << MAX << "): ";;
			while(n>10 || n<1){
				gotoxy(40, 3); cout << "          "; gotoxy(40, 3);
				SetColor(CINZA); cin >> n;
			}

			SetColor(BRANCO); cout << endl << "Insira a sua matriz triangular inferior:" << endl; SetColor(CINZA);
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					cin >> M[i][j];
				}
			}

			SetColor(BRANCO); cout << endl << "Insira o vetor B: " << endl; SetColor(CINZA);
			for(int i=0; i<n; i++) cin >> B[i];

			TriInferior(n, M, B, X);

			printaX();

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==3){ //2.3 - Sistema Triangular Superior
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Resolver sistema triangular superior"; SetColor(BRANCO);

			n=11;
			SetColor(BRANCO); cout << endl << endl << endl << "Digite a ordem da sua matriz (max. " << MAX << "): ";
			while(n>10 || n<1){
				gotoxy(40, 3); cout << "          "; gotoxy(40, 3);
				SetColor(CINZA); cin >> n;
			}

			SetColor(BRANCO); cout << endl << "Insira a sua matriz triangular superior:" << endl; SetColor(CINZA);
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					cin >> M[i][j];
				}
			}

			SetColor(BRANCO); cout << endl << "Insira o vetor B: " << endl; SetColor(CINZA);
			for(int i=0; i<n; i++) cin >> B[i];

			TriSuperior(n, M, B, X);

			printaX();

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==4){ //2.4 - Decomposição LU
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Resolver por Decomposicao LU"; SetColor(BRANCO);

			insereMatriz(); //Inserção da matriz

			int flag=0; //Teste de convergência
			for(int ordem=1; ordem<=n; ordem++) if(Determinante(ordem, M)==0){flag=ordem; break;}

			if(flag!=0){
				SetColor(VERMELHO); cout << endl << endl << "A matriz inserida nao converge -> ";
				SetColor(BRANCO); cout << "o determinante para A(" << flag << ") eh igual a zero.";
			}

			else{ //Converge :)
				SetColor(BRANCO); cout << endl << "Insira o vetor B: " << endl; SetColor(CINZA);
				for(int i=0; i<n; i++) cin >> B[i];

				SetColor(CINZA); cout << endl; for(int loop=0; loop<80; loop++) cout << "=";
				DecomposicaoLU(n, M, B, X);
				printaX();
			}

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==5){ //2.5 - Cholesky
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Resolver por Cholesky"; SetColor(BRANCO);

			insereMatriz(); //Inserção da matriz

			int flag=1; //Teste de convergência
			if(simetrica()==false) flag=-1;
			for(int ordem=1; ordem<=n; ordem++) if(Determinante(ordem, M)<=0) flag=0;

			if(flag<1){
				SetColor(VERMELHO); cout << endl << endl << "A matriz inserida nao converge -> ";
				SetColor(BRANCO);
				if(flag==-1) cout << "ela nao eh simetrica.";
				else cout << "ela nao eh positiva.";
			}

			else{ //Converge :)
				SetColor(BRANCO); cout << endl << "Insira o vetor B: " << endl; SetColor(CINZA);
				for(int i=0; i<n; i++) cin >> B[i];

				SetColor(CINZA); cout << endl; for(int loop=0; loop<80; loop++) cout << "=";
				Cholesky(n, M, B, X);
				printaX();
			}


			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==6){ //2.6 - Gauss Compacto
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Resolver por Gauss Compacto"; SetColor(BRANCO);

			insereMatriz(); //Inserção da matriz

			int flag=0; //Teste de convergência
			for(int ordem=1; ordem<=n; ordem++) if(Determinante(ordem, M)==0){flag=ordem; break;}

			if(flag!=0){
				SetColor(VERMELHO); cout << endl << endl << "A matriz inserida nao converge -> ";
				SetColor(BRANCO); cout << "o determinante para A (" << flag << ") eh igual a zero.";
			}

			else{ //Converge :)
				SetColor(BRANCO); cout << endl << "Insira o vetor B: " << endl; SetColor(CINZA);
				for(int i=0; i<n; i++) cin >> B[i];

				SetColor(CINZA); cout << endl; for(int loop=0; loop<80; loop++) cout << "=";
				GaussCompacto(n, M, B, X);
				printaX();
			}

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==7){ //2.7 - Gauss-Jordan
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Resolver por Gauss-Jordan"; SetColor(BRANCO);

			insereMatriz(); //Inserção da matriz

			int flag=0; //Teste de convergência
			for(int ordem=1; ordem<=n; ordem++) if(Determinante(ordem, M)==0){flag=ordem; break;}

			if(flag!=0){
				SetColor(VERMELHO); cout << endl << endl << "A matriz inserida nao converge -> ";
				SetColor(BRANCO); cout << "o determinante para A (" << flag << ") eh igual a zero.";
			}

			else{ //Converge :)
				SetColor(BRANCO); cout << endl << "Insira o vetor B: " << endl; SetColor(CINZA);
				for(int i=0; i<n; i++) cin >> B[i];

				SetColor(CINZA); cout << endl; for(int loop=0; loop<80; loop++) cout << "=";
				if(GaussJordan(n, M, B, X)==0){
					SetColor(VERMELHO); cout << endl << endl << "O sistema gerado eh inderminado." << endl;
				}
				else printaX();
			}

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==8){ //2.8 - Jacobi
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Resolver por Jacobi"; SetColor(BRANCO);

			insereMatriz(); //Inserção da matriz

			if(CriterioColunas()==0 && CriterioLinhas()==0){ //Teste de convergência
				SetColor(VERMELHO); cout << endl << endl << "A matriz inserida nao converge -> ";
				SetColor(BRANCO); cout << "ela nao satisfaz nem o Criterio das Linhas nem o Criterio das Colunas";
			}

			else{ //Converge :)
				int iteracoes=0, maxIteracoes;
				double aprox[MAX], e;

				SetColor(BRANCO); cout << endl << "Insira o vetor B: " << endl; SetColor(CINZA);
				for(int i=0; i<n; i++) cin >> B[i];

				SetColor(BRANCO); cout << endl << "Insira o vetor de aproximacao: " << endl; SetColor(CINZA);
				for(int i=0; i<n; i++) cin >> aprox[i];

				SetColor(BRANCO); cout << endl << "Insira a precisao desejada (e): " << endl; SetColor(CINZA);
				cin >> e;

				SetColor(BRANCO); cout << endl << "Insira o numero maximo de iteracoes: " << endl; SetColor(CINZA);
				cin >> maxIteracoes;

				SetColor(CINZA); cout << endl; for(int loop=0; loop<80; loop++) cout << "=";
				Jacobi(n, M, B, aprox, e, maxIteracoes, X, &iteracoes);
				printaX(); SetColor(VERDE);
				cout << endl << endl << "Numero de iteracoes realizadas: " << iteracoes;
			}

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==9){ //2.9 - Gauss-Seidel
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Resolver por Gauss-Seidel"; SetColor(BRANCO);

			insereMatriz(); //Inserção da matriz

			if(CriterioLinhas()==0 && CriterioSassenfield()==0){ //Teste de convergência
				SetColor(VERMELHO); cout << endl << endl << "A matriz inserida nao converge -> ";
				SetColor(BRANCO); cout << "ela nao satisfaz nem o Criterio das Linhas nem o Criterio de Sassenfield";
			}

			else{ //Converge :)
				int iteracoes=0, maxIteracoes;
				double aprox[MAX], e;

				SetColor(BRANCO); cout << endl << "Insira o vetor B: " << endl; SetColor(CINZA);
				for(int i=0; i<n; i++) cin >> B[i];

				SetColor(BRANCO); cout << endl << "Insira o vetor de aproximacao: " << endl; SetColor(CINZA);
				for(int i=0; i<n; i++) cin >> aprox[i];

				SetColor(BRANCO); cout << endl << "Insira a precisao desejada (e): " << endl; SetColor(CINZA);
				cin >> e;

				SetColor(BRANCO); cout << endl << "Insira o numero maximo de iteracoes: " << endl; SetColor(CINZA);
				cin >> maxIteracoes;

				SetColor(CINZA); cout << endl; for(int loop=0; loop<80; loop++) cout << "=";
				GaussSeidel(n, M, B, aprox, e, maxIteracoes, X, &iteracoes);
				printaX(); SetColor(VERDE);
				cout << endl << endl << "Numero de iteracoes realizadas: " << iteracoes;
			}

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==10){ //2.10 - Matriz inversa por LU
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Calcular matriz inversa por Decomposicao LU"; SetColor(BRANCO);

			insereMatriz(); //Inserção da matriz

			int flag=0; //Teste de convergência
			for(int ordem=1; ordem<=n; ordem++) if(Determinante(ordem, M)==0){flag=ordem; break;}

			if(flag!=0){
				SetColor(VERMELHO); cout << endl << endl << "A matriz inserida nao converge -> ";
				SetColor(BRANCO); cout << "o determinante para A(" << flag << ") eh igual a zero.";
			}

			else{ //Converge :)
				SetColor(CINZA); cout << endl; for(int loop=0; loop<80; loop++) cout << "=";
				InversaLU(n, M, inversa);
				SetColor(VERDE);
				cout << endl << endl << "Matriz inversa:" << endl;
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++) cout << inversa[i][j] << "  ";
					cout << endl;
				}
			}

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}
		
		while(pos==11){ //2.11 - Matriz inversa Gauss Compacto
			limpaTela(); cursor(true);
			SetColor(CINZA); cout << "-> ";
			SetColor(CINZA); cout << "Opcao selecionada: ";
			SetColor(VERDE); cout << "Calcular matriz inversa por Gauss Compacto"; SetColor(BRANCO);

			insereMatriz(); //Inserção da matriz

			int flag=0; //Teste de convergência
			for(int ordem=1; ordem<=n; ordem++) if(Determinante(ordem, M)==0){flag=ordem; break;}

			if(flag!=0){
				SetColor(VERMELHO); cout << endl << endl << "A matriz inserida nao converge -> ";
				SetColor(BRANCO); cout << "o determinante para A (" << flag << ") eh igual a zero.";
			}

			else{ //Converge :)
				SetColor(CINZA); cout << endl; for(int loop=0; loop<80; loop++) cout << "=";
				InversaGauss(n, M, inversa);
				SetColor(VERDE);
				cout << endl << endl << "Matriz inversa:" << endl;
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++) cout << inversa[i][j] << "  ";
					cout << endl;
				}
			}

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}
		
		if(pos==12){ //2.12 - SAIR
			SetColor(AZUL); cout << "\n\nAgradecemos por ver o nosso trabalho. Espero que tenha gostado :)\n";
			ON=false;
			system("pause");
		}
	}
}