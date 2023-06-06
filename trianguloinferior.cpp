#include <stdio.h>
#define max 10

int somatoria (int j, int i , double M[][10], double X[]) {
	int cont = 0;
	
	for (j=0; j < i ; j++) {
		cont+=M[i][j] * X[j]; 
		//é i+1 para fixar a linha, pois na chamada de função é i-1
	}
	
	return cont;
}

void TriInferior (int t, double M[][10], double X[], double B[]) {
	int i, j;
	
	for (i=0; i<t; i++) {
			if(i==0) X[0]= B[0]/M [0][0];
			
			else X[i]= (B[i] - somatoria(0, i, M, X))/M[i][i];
	}
}

int main() {
	
	double A[max][max], X[max], B[max];
	int i, n, j;
	
	printf("Digite a ordem da matriz: ");
	scanf("%d", &n);
	
	printf("\nDigite a matriz %d x %d:\n", n, n);
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			scanf("%lf", &A[i][j]);	
	
	printf("Digite o vetor B\n");
	
	for(i=0 ; i<n ; i++)
		scanf("%lf", &B[i]);
	
	printf("\n\nA matriz inserida foi:");
	
	for(i=0 ; i<n ; i++){
		printf("\n");
			for(j=0 ; j<n ; j++)
				printf("%.4lf ", A[i][j]);
	}
	
	printf("\n\nO vetor B inserido foi: ");
	
	for(i=0 ; i<n ; i++)
		printf("%.4lf ", B[i]);
	
	TriInferior(n, A, X, B);

	printf("\n\nO vetor X sera: ");
	
	for(i=0 ; i<n ; i++)
		printf("%.4lf ", X[i]);
}
