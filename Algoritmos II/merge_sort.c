#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void merge(int arr[], int l, int m, int r){   

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }


}

void mergeSort(int arr[], int l, int r){

    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }

}

void getVetor(int v[], int size){
    
    int i;

	printf("\nInsert array: \n");
	
    for(i=0;i<size;i++){
        scanf("%d", &v[i]);
    }

}

void printaVetor(int v[], int size){

    int i;

    printf("\nO vetor digitado foi: \n");

    for(i=0;i<size;i++){
        printf("%d ", v[i]);

        if(i==size-1)
            printf("\n");
    }

}

void printaSorted(int v[], int size){

    int i;

    printf("\n\nO vetor ordenado por merge: \n");

    for(i=0;i<size;i++){
        printf("%d ", v[i]);

        if(i==size-1)
            printf("\n");
    }

}

int main(){

    int vetor[MAX], size;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    getVetor(vetor, size);

    printaVetor(vetor, size);

    mergeSort(vetor, 0, size-1);

    printaSorted(vetor, size);

    return 0;

}