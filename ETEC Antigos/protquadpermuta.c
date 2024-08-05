#include <stdio.h>
#include <math.h>
#define size 15
#define TRUE 1
#define FALSE 0

int main(){
	
	int n, i, j, soma_inicial, soma1, soma2, igual = TRUE;
    int a[size][size];
    
    scanf("%d", &n);
	
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

    return 0;
}
