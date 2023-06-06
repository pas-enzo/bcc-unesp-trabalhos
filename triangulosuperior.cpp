#include <stdio.h>
#define max 10

int somatoria (int j, int i , double M[][10], double X[]) {
	int cont = 0; 
	int aux = j-1;
	//linha de i fixada  pois j é i+1 na chamda da função
	
	for ( j=0; j<i; j++) {
		cont += M[aux][j] * X[j]; 
	}
	
	return cont;
}

void TriSuperior (int t, double M[][10], double X[], double B[]) {
	int i, j; 
	
	for(i=t-1 ; i>=0 ; i--) {
			if (i==t-1) X[i] = B[i] / M[i][i];
			
			else X[i]= (B[i] - somatoria(i+1, t, M, X)) / M[i][i];
	}
}

int main () {	
	double A[max][max], X[max], B[max];
	int i , n, j;
	
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

	for (i=0 ; i<n ; i++) {
		printf("\n");
			for(j=0 ; j<n ; j++)
				printf("%.4lf ", A[i][j]);
	}
	
	printf("\n\nO vetor B inserido foi: ");
	
	for(i=0 ; i<n ; i++)
		printf("%.4lf ", B[i]);
	
	TriSuperior(n, A, X, B);

	printf("\n\nO vetor X sera: ");
	
	for(i=0 ; i<n ; i++)
		printf("%.4lf ", X[i]);
}
