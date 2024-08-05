#include <stdio.h> 
#include <stdlib.h>

typedef struct reg *no;

struct reg
{
    int info;
    struct reg *prox;
};

no *lista;

void cria_lista (no *lista) 
{
    *lista = NULL;
}

void inclui_inicio (no *lista, int info) 
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;
    p->prox = *lista;
    *lista = p;
}


void mostra_lista (no lista) 
{
    no p = lista;
    printf("\nElementos da lista: ");
    while (p) 
    {
        printf("%d ", p->info);
        p = p->prox;
    }
}

int main () 
{
    int info;
    no lista;
    char resp;

    cria_lista(&lista);

    do
    {
        printf("\nDigite o numero a ser inserido no inicio da lista: ");
        scanf("%d", &info);
        inclui_inicio(&lista,info);
        mostra_lista(lista);

        printf("\nGostaria de adicionar um novo numero? (S/N)");
        
        do
        {
          resp = toupper(getchar()); 
        } while (resp != 'N' && resp != 'S');
        
    } while (resp == 'S');

    return 0;
}