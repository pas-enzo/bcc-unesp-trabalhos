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

void insere_ordenado (no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;

    if (*lista == NULL || info <= (*lista)->info)
    {
        p->prox = *lista;
        *lista = p;
    }

        else
        {
            no q = *lista, r;

            while (q != NULL && q->info < info)
            {
                r = q;
                q = q->prox;
            }

            r->prox = p;
            p->prox = q;
        }
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
    no *lista;
    char resp;

    cria_lista(&lista);

    do
    {
        printf("\nDigite o elemento a ser inserido em ordem crescente: ");
        scanf("%d", &info);

        insere_ordenado(&lista,info);
        mostra_lista(lista);

        printf("\nContinua? (S/N)");

        do
        {
            resp = toupper(getchar());
        } while (resp != 'N' && resp != 'S');
        
    } while (resp != 'N');
    
    return 0;
}