#include <stdio.h>
#include <math.h>

void substituicaoProgressiva(int n, double L[][n], double b[], double x[]) {
    for (int i = 0; i < n; i++) {
        x[i] = b[i];
        for (int j = 0; j < i; j++) {
            x[i] -= L[i][j] * x[j];
        }
        x[i] /= L[i][i];
    }
}

void substituicaoRegressiva(int n, double U[][n], double y[], double x[]) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

void decomposicaoLU(int n, double A[][n], double L[][n], double U[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                L[j][i] = 0;
            } else {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++) {
                    L[j][i] -= L[j][k] * U[k][i];
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (j < i) {
                U[i][j] = 0;
            } else if (j == i) {
                U[i][j] = 1;
            } else {
                U[i][j] = A[i][j] / L[i][i];
                for (int k = 0; k < i; k++) {
                    U[i][j] -= (L[i][k] * U[k][j]) / L[i][i];
                }
            }
        }
    }
}

double CoefDeterminacao(int E, double tabela[2][E], double vetorY[E]) {
    double soma_y = 0.0, soma_y_ajustado = 0.0;
    double sqr = 0.0, sqt = 0.0;
    int i;

    for (i = 0; i < E; i++) {
        soma_y += tabela[1][i];
        soma_y_ajustado += vetorY[i];
    }

    double media_y = soma_y / E;
    for (i = 0; i < E; i++) {
        sqr += pow(tabela[1][i] - vetorY[i], 2);
        sqt += pow(tabela[1][i] - media_y, 2);
    }

    double coef_determinacao = 1 - (sqr / sqt);

    return coef_determinacao;
}

void AjustePolinomio(int E, int grau, double tabela[2][E], double vetorA[grau + 1], double vetorY[E], double *coef_determinacao) {
    int n = grau + 1;
    double A[n][n];
    double b[n];

    // Monta a matriz A e o vetor b para o sistema linear
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double soma = 0.0;
            for (int k = 0; k < E; k++) {
                soma += pow(tabela[0][k], i + j);
            }
            A[i][j] = soma;
        }

        double soma = 0.0;
        for (int k = 0; k < E; k++) {
            soma += tabela[1][k] * pow(tabela[0][k], i);
        }
        b[i] = soma;
    }

    double L[n][n];
    double U[n][n];
    decomposicaoLU(n, A, L, U);

    double y[n];
    substituicaoProgressiva(n, L, b, y);

    substituicaoRegressiva(n, U, y, vetorA);

    for (int i = 0; i < E; i++) {
        vetorY[i] = 0.0;
        for (int j = 0; j < n; j++) {
            vetorY[i] += vetorA[j] * pow(tabela[0][i], j);
        }
    }

    *coef_determinacao = CoefDeterminacao(E, tabela, vetorY);
}

int main() {
    int E = 5;  // <-- Declarar numero de pontos na tabela AQUI
    int grau = 2;  // <-- Grau do polinômio desejado

    double tabela[2][5] = {{0, 1, 2, 4, 5},
                           {4, 1, -1, 1, 2}};
    double vetorA[grau + 1];     // Coeficientes do polinômio ajustado
    double vetorY[E];            // Valores Y ajustados
    double coef_determinacao;    // Coeficiente de determinação

    AjustePolinomio(E, grau, tabela, vetorA, vetorY, &coef_determinacao);

    // Imprime os coeficientes do polinômio ajustado
    printf("Coeficientes do polinomio ajustado:\n");
    for (int i = 0; i <= grau; i++) {
        printf("a%d = %.3f\n", i, vetorA[i]);
    }

    // Imprime os valores Y ajustados
    printf("\nValores Y ajustados:\n");
    for (int i = 0; i < E; i++) {
        printf("Y ajustado[%d] = %.3f\n", i, vetorY[i]);
    }

    // Imprime o coeficiente de determinação
    printf("\nCoeficiente de determinacao: %.3f\n", coef_determinacao);

    return 0;
}

