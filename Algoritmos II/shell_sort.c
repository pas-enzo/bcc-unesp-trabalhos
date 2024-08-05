#include <stdio.h>
#define MAX 1000

void shell_sort (int v[], int n) {

    int i, j, gap, temp; 

    for (gap = n/2; gap>0; gap/=2) {
        for (i=gap;i<n;i++) {

            temp = v[i];

            for (j=i;j>=gap && v[j-gap] > temp;j-=gap)
                v[j] = v[j-gap];

            v[j] = temp;

        }
    }

    return 0;

}

int main() {

    int v[MAX], n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);


    printf("\nInsira os elementos do vetor: \n");
    for (i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }

    shell_sort(v, n);

    printf("\n\nVetor ordenado por Bubble sort: \n");
    for (i=0;i<n;i++) {
        printf("%d ", v[i]);
    }

    return 0;

}