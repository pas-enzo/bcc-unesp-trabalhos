#include <stdio.h>
#include <math.h>


int main () {

    int raio, helio;
    float litraobalao, quantidade;

    scanf("%d %d", &raio, &helio);

    litraobalao = (4 * (3.1415 * raio * raio * raio)) / 3;

    quantidade = (float)helio / litraobalao;

    printf("%d\n", (int)quantidade);

    return 0;

}