#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg
{
    int info;
    struct reg *prox;
};

no *lista;

//exercicios treino - incluir no inicio
void inclui_inicio_lcse (no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;

    if (*lista == NULL)
    {
        p->prox = p;
        *lista = p;
    }

    else
    {
        no q = *lista;

        do
        {
            q = q->prox;
        } while (q != *lista);

        q->prox = p;
        p->prox = *lista;
        *lista = p;
    }
}

//exercicios treino - incluir no final;

void inclui_final (no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;


    if (*lista == NULL) //se a lista for nula, inclui no inicio
    {
        p->prox = p;
        *lista = p;
    }

    else
    {
        no q = *lista;

        do
        {
            q = q->prox;
        } while (q != *lista);

        q->prox = p;
        p->prox = *lista; //nao diz que *lista = p porque ai p seria o primeiro elemento de lista
        
    }
}

//exercicios treino - incluir ordenado
void inclui_ordenado (no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;

    if(*lista == NULL)//se a lista tiver vazia
    {
        p->prox = *lista;
        *lista = p;
    }

    else //senao, incluir no inicio ou no meio/final
    {
        if (info <= (*lista)->info)//incluir no inicio
        {
            no q = *lista;

            while (q != *lista)
            {
                q = q->prox;
            }

            q->prox = p;
            p->prox = *lista;
            *lista = p;
        }

        else
        {
            no q = *lista, r;

            do
            {
                r = q;
                q = q->prox;
            } while (q != *lista && q->info < info);

            r->prox = p;
            p->prox = q; 
        }
    }
}

//exercicios treino - remover inicio
int remove_inicio (no *lista)
{
    if (*lista == NULL) return 0;//se a lista for vazia retorna 0

    if ((*lista)->prox = *lista)//se a lista tiver apenas um elemento, free lista e anula
    {
        free(*lista);
        *lista = NULL;
    }

    else //se a lista tiver mais de um elemento, remover do inicio
    {
        no q = *lista;
        
        while (q != *lista)
        {
            q = q->prox;
        }

        no p = *lista;

        *lista = p->prox;
        q->prox = *lista;
        free(p);
    }
    return 1;
}

//exercicio 1
int conta_qnts (no *lista, int info)
{
    if (!*lista) return 0;

    else
    {
        no p = *lista;
        int i = 0;

        while (p != *lista)
        {
            if (p->info == info) i++;
            p = p->prox;
        }

        return i;
    }
}

//exercicio 3
int exclui_todos (no *lista)
{
    if (!*lista) return 0;

    else
    {
        do
        {
            if((*lista)->prox = *lista)
            {
                free(*lista);
                *lista = NULL;
            }

            else
            {
                no q = *lista;

                while (q != *lista) q = q->prox;

                no p = *lista;
                *lista = p->prox;
                q->prox = *lista;
                free(p);
            }
        } while (*lista != NULL);
        
        return 1;
    }
}

//exercicio 5
void insere_ordenado (no *lista, int info)
{
    no p = (no)malloc(sizeof(struct reg));
    p->info = info;

    if (*lista == NULL)//se a lista está vazia
    {
        p->prox = p;
        *lista = p;
    }

    else//se a lista nao esta vazia
    {
        if (info <= (*lista)->info)//se o elemento adicionado for menor ou igual ao primeiro elemento
        {
            no q = *lista;

            while (q != *lista) q = q->prox;//leva o ponteiro auxiliar para o final da lista

            q->prox = p;
            p->prox = *lista;
            *lista = p;
        }

        else//se o elemento adicionado vai ser adicionado no meio ou no final da lista
        {
            no q = *lista, r;

            do
            {
                r = q;
                q = q->prox;
            } while (q != *lista && q->info < info);
            
            r->prox = p;
            p->prox = q;
        }
    }
}

int remove_instancias_ord (no *lista, int elem)
{
    if (*lista = NULL) return 0;

    do
    {
        if (elem == (*lista)->info) 
        {//se o elemento é igual ao primeiro elemento da lista
            
            no q = *lista;
            
            if (*lista == (*lista)->prox)//se removeu todos os elementos
                *lista = NULL; //anula a lista

            else 
            {//se o elemento for o primeiro elemento
                no q = *lista;
                
                while (q->prox != *lista) q = q->prox;
                q->prox = (*lista)->prox;    
                *lista = (*lista)->prox;
            }  
            free (q);
            return 1;
        }

    no q = *lista, r;//se for remover do inicio ao final
  
    do 
    {
        r = q;        
        q = q->prox;
    } while (q->info != elem && q != *lista);

    if (q->info != elem) return 0;
    r->prox = q->prox;
    free (q);
    return 1;

    no s = *lista;
    int achou = 0;

    while (s != *lista && !achou)
    {
        s = s->prox;
        if (s->info == elem) achou = 1;

    } while (achou == 1);
}

//exercicio 7
int informa_identico (no lista1, no lista2) 
{
    no q = lista1, s = lista2;
    int achou = 0;

    do
    {
        if(q->info == s->info) achou = 0;

        else 
        {
            achou = 1;
            break;
        }

        q = q->prox;
        s = s->prox;

    } while (q != lista && s != lista);
}

//exercicio 9
void copia_sem_repeticoes 