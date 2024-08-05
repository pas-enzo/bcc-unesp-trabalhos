#include <stdio.h>

int exponen (int n, int x){

    if (x==1)
        return n;

    else
        return n * exponen(n,x-1);

}


int main() {

    int n, x;
    int repro;

    while (scanf("%d", &repro) != 0) {
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("\nDigite o valor do expoente (inteiro): ");
    scanf("%d", &x);

    printf("\n\n%d^(%d) = %d", n, x, exponen(n,x));

    printf("")

    }

    return 0;
}