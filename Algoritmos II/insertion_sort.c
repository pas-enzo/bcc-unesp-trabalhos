#include <stdio.h>
#define MAX 1000

void insert_sort(int v[], int n) {

    /*chave necessaria para terminar a insercao 
    de cada elemento dentro do while, 
    j contador auxiliar*/
    int i, j, chave; 

    for (i=1;i<n;i++) {
        
        chave = v[i]; //chave para comparacao
        j = i-1; //j volta ate tiver valor 0, ou seja, compara elementos ate o inicio do vetor

        while (j>=0 && v[j]>chave) { //volta ate o primeiro elemento do vetor se o elemento v[j] for menor que a chave, caso contrario insert no elemento

            v[j+1] = v[j];
            j--;

        }

        v[j+1] = chave;

    }

}

int main () {

    int v[MAX], n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);


    printf("\nInsira os elementos do vetor: \n");
    for (i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }

    insert_sort(v, n);

    printf("\n\nVetor ordenado por Insert sort: \n");
    for (i=0;i<n;i++) {
        printf("%d ", v[i]);
    }

    return 0;

}