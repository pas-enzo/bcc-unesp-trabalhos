// @ - Run a nested for loop to traverse the input array using two variables i and j, such that 0 ≤ i < n-1 and 0 ≤ j < n-i-1
// @ - If arr[j] is greater than arr[j+1] then swap these adjacent elements, else move on
// @ - Print the sorted array

#include <stdio.h>
#define MAX 1000

void bubble_sort (int v[], int n) {

    int i, j, aux;

    for (i=0;i<n-1;i++) {
        for (j=0;j<n-i-1;j++) {
            
            if (v[j] > v[j+1]) {

                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

            }

        }

    }

}

int main() {

    int v[MAX], n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);


    printf("\nInsira os elementos do vetor: \n");
    for (i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }

    bubble_sort(v, n);

    printf("\n\nVetor ordenado por Bubble sort: \n");
    for (i=0;i<n;i++) {
        printf("%d ", v[i]);
    }

    return 0;

}