#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    a =b;
    b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        maxHeapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    int i;

    //monta o heapmax
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    //tira 1 da contagem de numeros na array e troca o maior indice pelo menor e chama a heap max novamente
    for (i = n - 1; i >= 0; i--) {
        trocar(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void imprimirArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 5, 7, 15, 3, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, n);

    heapSort(arr, n);

    printf("Array ordenado: ");
    imprimirArray(arr, n);

    return 0;
}