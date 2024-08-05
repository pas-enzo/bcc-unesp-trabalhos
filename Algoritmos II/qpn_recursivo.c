#include <stdio.h>

int soma_quadrados (int n) {

    if (n==1) 
        return 1;
    

    else
        return n * n + soma_quadrados(n-1);

}

int main() {

    int n;

    scanf("%d", &n);

    printf("\n\nSoma dos quadrados dos %d primeiros numeros: %d", n, soma_quadrados(n));

    return 0;

}