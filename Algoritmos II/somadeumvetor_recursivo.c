#include <stdio.h>

int vetorsoma (int v[], int tam){

    if (tam==0)
        return 0;

    else
        return v[tam-1] + vetorsoma(v, tam-1);

}

int main () {

    int v[6] = {2, 5, 6, 1, 7, 3};
    
    printf("A soma do vetor v[6] = {2, 5, 6, 1, 7, 3} sera igual a: %d", vetorsoma(v, 6));
    return 0;

}