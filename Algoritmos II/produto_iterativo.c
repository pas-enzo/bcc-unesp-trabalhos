#include <stdio.h>

int produto (int a, int b){

    int repeticao = a;
    int times = 0;

    while (repeticao) {

        times += b;

        repeticao--;

    }

    return times;

}

int main() {

    int a, b;

    printf("De o valor de a e b: ");
    scanf("%d %d", &a, &b);

    printf("%d x %d = %d", a, b, produto(a,b));

    return 0;

}