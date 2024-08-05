#include <stdio.h>

void hanoi (int d, char ori, char dest, char aux) {

    if (d==1) 
        printf("\nMover disco %d de %c para %c", d, ori, dest);

    else {

        hanoi(d-1, ori, aux, dest);
        printf("\nMover disco %d de %c para %c", d, ori, dest);
        hanoi(d-1, aux, dest, ori);

    }


}

int main() {
    
    int discos;

    printf("Digite o numero de discos: ");
    scanf("%d", &discos);

    hanoi(discos, 'A', 'C', 'B');

    return 0;

}