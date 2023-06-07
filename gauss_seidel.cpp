#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

double precisao = 0.0001;
int max_iteracoes = 100;

void gauss_seidel(int ordem, double matriz[][MAX], double vetor_independente[], double aprox_inicial[], double precisao, int max_iteracoes, double solucao[], int* num_iteracoes) {
    double *aprox_atual = (double*)malloc(ordem * sizeof(double));
    double *aprox_anterior = (double*)malloc(ordem * sizeof(double));
    double diferenca;
    int iteracao;

    for (int i = 0; i < ordem; i++) {
        aprox_atual[i] = aprox_inicial[i];
    }

    for (iteracao = 0; iteracao < max_iteracoes; iteracao++) {
        for (int i = 0; i < ordem; i++) {
            aprox_anterior[i] = aprox_atual[i];
        }

        for (int i = 0; i < ordem; i++) {
            double soma = 0.0;
            for (int j = 0; j < ordem; j++) {
                if (j != i) {
                    soma += matriz[i][j] * aprox_atual[j];
                }
            }
            aprox_atual[i] = (vetor_independente[i] - soma) / matriz[i][i];
        }

        diferenca = 0.0;
        for (int i = 0; i < ordem; i++) {
            diferenca += fabs(aprox_atual[i] - aprox_anterior[i]);
        }

        if (diferenca < precisao) {
            break;
        }
    }

    for (int i = 0; i < ordem; i++) {
        solucao[i] = aprox_atual[i];
    }

    *num_iteracoes = iteracao;

    free(aprox_atual);
    free(aprox_anterior);
}

int main() {
    int ordem = 0;
    double matriz[MAX][MAX];
    double vetor_independente[MAX];
    double aprox_inicial[MAX];
    double solucao[MAX];
    int num_iteracoes = 0;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);
    
    printf("\nDigite os valores da matriz %d X %d: \n", ordem, ordem);
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    
    printf("\n\nDigite o vetor independente (B): ");
    for (int i = 0; i < ordem; i++)
        scanf("%lf", &vetor_independente[i]);
    
    printf("\n\nDigite os valores da aproximacao inicial: ");
    for (int i = 0; i < ordem; i++)
        scanf("%lf", &aprox_inicial[i]);
                
    gauss_seidel(ordem, matriz, vetor_independente, aprox_inicial, precisao, max_iteracoes, solucao, &num_iteracoes);

    printf("\n\nSolucao:\n");
    for (int i = 0; i < ordem; i++)
        printf("%.5lf\n", solucao[i]);

    printf("\nNumero de iteracoes: %d\n", num_iteracoes);

    return 0;
}