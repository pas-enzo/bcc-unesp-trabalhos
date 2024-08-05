#include <stdio.h>
#include <locale.h>
#define MAX 100

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo;
    char nome_arq[30], texto[50];
    int a[MAX][MAX];

    printf("De um nome ao arquivo: ");
    fflush(stdin);
    gets(nome_arq);

    if((arquivo=fopen(nome_arq, "wt"))==NULL){
        printf("Erro na abertura de arquivo.\n");
        exit(1);
    } 

    fflush(stdin);
    fputs(texto, nome_arq);
    fputc('\n');

    printf("De as dimensoes da matriz: ");


    return 0;

}