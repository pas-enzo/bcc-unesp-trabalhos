#include <stdio.h>
#define size 15
#define TRUE 1
#define FALSE 0

void le_matriz(int M[size][size], int nl, int nc);
void le_vetor(int V[size], int nc);


int main(){
    int n, i, j, soma_inicial, soma1, soma2, igual = TRUE;
    int a[size][size];

    printf("Digite a ordem da matriz A: ");
    scanf("%d", &n);

    if (n == 0)
        return 0;

    printf("Entrada dos elementos da matriz A\n");
    le_matriz(a, n, n);

    soma_inicial = 0;
    soma2 = 0;

    for (j = 0; j < n; j++){
        soma_inicial += a[0][j];
        soma2 += a[j][0];
    }

    igual = soma_inicial == soma2;

    for (i = 1; igual && i < n; i++) {
        /* soma1 => contem a soma da linha i
           soma2 => contem a soma da coluna i */
        soma1 = 0;
        soma2 = 0;
        for (j = 0; j < n; j++){
            soma1 += a[i][j];
            soma2 += a[j][i];
        }

        igual = (soma1 == soma2 && soma2 == soma_inicial);
    }

    if (igual){
        /* Calcula a soma das diagonais*/
        soma1 = 0;
        soma2 = 0;
        for (j = 0; j < n; j++){
            soma1 += a[j][j];
            soma2 += a[j][n-j-1];
        }
        igual = (soma1 == soma2 && soma2 == soma_inicial);
    }

    if (igual)
        printf("A eh um quadrado magico!\n");
    else
        printf("A nao eh um quadrado magico!\n");

    return 0;
}


void le_vetor(int V[size], int nc){
    int i;

    printf("Digite %d numeros: ", nc);
    for (i = 0; i < nc; i++)
        scanf("%d", &V[i]);
}


void le_matriz(int M[size][size], int nl, int nc){
    int i;

    for(i = 0; i < nl; i++) {
        printf("Linha %d da matriz\n", i);
        le_vetor(M[i], nc);
    }
}
