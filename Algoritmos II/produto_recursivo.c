#include <stdio.h>

int prod_recursivo (int a, int b) {

    if (b==1)
        return a;

    else
        return a + prod_recursivo(a,b-1);

}

int main() {

    int a, b;

    printf("De o valor de a e b: ");
    scanf("%d %d", &a, &b);

    printf("%d x %d = %d", a, b, prod_recursivo(a,b));

    return 0;

}