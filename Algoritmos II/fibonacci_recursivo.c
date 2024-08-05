#include <stdio.h> 

int fibo (int n){

    if(n==0)
        return 0;

    else{

            if (n==1)
                return 1;

            else
                return fibo(n-1) + fibo(n-2);

    }

}

int main(){

    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("\n\nFibonacci de %d repeticoes(0-%d): %d", n, n-1, fibo(n));

    return 0;

}