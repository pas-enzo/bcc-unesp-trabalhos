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

//exercicio 7
int conta_elementos (no lista)
{
    no q = lista;
    int i = 0;

    if (!lista) return 0;

    else
    {
        while (q)
        {
            q = q->prox;
            i++;
        }
        return i;
    }
}

//exercicio 8
int retorna_primeiro (no lista)
{
    no q = lista;

    if (!lista) return 0;

    else
    {
        return q->info;
    }
}

//exercicio 9
int retorna_ultimo (no lista)
{
    no q = lista;

    if (!lista) return 0;

    else
    {
        while (q)
        {
            q = q->prox;
        }
        return q->info;
    }
}

//exercicio 10
int busca (no lista, int info)
{
    no q = lista;
    
    if (!lista) return 0;

    else
    {
        while (q != NULL && q->info != info)
        {
            q = q->prox;
        }

        if (q->prox = NULL && q->info != info)
        {
            return 0;
        }

        else
        {
            return 1;
        }
        
    }
}

//exercicio 11
int busca_instancias (no lista, int info)
{
    no q = lista;
    int i = 0;

    if (!lista) return 0;

    else
    {
        while (p != NULL)
        {
            p = p->prox;
            if (p->info == info) i++;
        }
        return i;
    }
}

//exercicio 12
void inserir_inicio (no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;

    if (*lista == NULL)
    {
        p->prox = NULL;
        *lista = p;
    }

    else
    {
        p->prox = *lista;
        *lista = p;
    }
}

//exercicio 13
void inserir_final (no *lista, int info)
{
    no p = (no)malloc(sizeof(strut reg));
    p->info = info;
    p->prox = NULL;
    
    if (*lista == NULL) *lista = p;

    else
    {
        no q = *lista;

        while (q)
        {
            q = q->prox;
        }

        q->prox = p;

    }
}

//exercicio 14
void inserir_nesimo (no *lista, int info, int n)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;

    if (*lista == NULL || n == 0)
    {
        p->prox = *lista;
        *lista = p;
    }
    else{
        no q = *lista, r;
        int count = 0;
        
        do
        {   
            r = q;
            q = q->prox;
            count++; 
        } while (q != NULL && count < n-1);

        if (q->prox == NULL)
        {
            p->prox = NULL;
            q->prox = p;
        }

        else
        {
            r->prox = p;
            p->prox = q;
        }
    }
}

//exercicio 15
void insere_antesenesimo (no *lista, int info, int n)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;

    if (*lista == NULL || n == 1)
    {
        p->prox = *lista;
        *lista = p;
    }

    else 
    {
        no q = *lista, r;
        int count = 0;

        do
        {
            r = q;
            q = q->prox;
        } while (q != NULL && count < n-2);

        r->prox = p;
        p->prox = q;
    }
}

//exercicio 16
int remover_inicio (no *lista)
{
    no p = *lista;

    if (!*lista) return 0;

    *lista = (*lista)->prox;
    free(p);
}

//exercicio 16
int remover_final (no *lista)
{
    if(!*lista) return 0;

    else
    {
        no q = *lista, r;

        while (q != NULL)
        {
            r = q;
            q = q->prox;
        } 

        r->prox = NULL;
        free(q);
    }
}

//exercicio 25
int concatenar_listas (no *lista1, no *lista2)
{
    

    if (!lista1 || !lista2) return 0;

    else
    {
        no p = *lista1, q = *lista2;

        while (p != NULL) p = p->prox;
        p->prox = q;
        free(*lista2);
        return 1;
    }
}