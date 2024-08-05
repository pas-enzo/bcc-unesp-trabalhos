#include <stdio.h>

int fatera(int n){

    int i=n;
    int fatorial;

    while (i>=1) {

        if (i==n) 
            fatorial = n;

        else
            fatorial *= n-i;

        i--;    

    }

    return fatorial;

}

int main(){

    int n;
    
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("\n\n%d! = %d", n, fatera(n));


    return 0;

}