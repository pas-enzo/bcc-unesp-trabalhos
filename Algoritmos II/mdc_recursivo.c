#include <stdio.h>

int mdc (int x, int y) {

    if (y<=x && x%y==0)
        return y;

    if (x<y)
        return mdc(y,x);

    else 
        return mdc(y,x % y);

}

int main() {

    int m, n;

    scanf("%d %d", &m, &n);

    printf("\n\nO MDC entre %d e %d sera: %d", m, n, mdc(m,n));

    return 0;

}