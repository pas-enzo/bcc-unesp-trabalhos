#include <stdio.h>

int main(){

    int N[10], i;
    int antec, aux, X;

    scanf("%d", &N[0]);

    printf("N[0] = %d\n", N[0]);
    
    antec=N[0];

    for(i=1;i<10;i++){
		
		N[i]=2*antec;
		
		X=N[i];
        
        printf("N[%d] = %d\n", i, X);
        
        aux=N[i];
        
        antec=aux;

    }



    return 0;
}
