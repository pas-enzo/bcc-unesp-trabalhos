//recursividade 
#include <stdio.h>

int fatorial (int n){

    if(n<=1)return 1;

    return n*fatorial(n-1);
}

int main(){

    int n;

    printf("Digite o valor que gostaria de calcular o fatorial: \n");
    scanf("%d", &n);

    printf("%d! = %d\n", n, fatorial(n));

    return 0;
}