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
}