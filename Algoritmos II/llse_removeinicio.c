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

int remove_inicio (no *lista) 
{
    if (*lista == NULL)
    {
        printf("\nLista vazia!");
        return 0;
    }

        else
        {
            no p = *lista;

            *lista = (*lista)->prox;
            free(p);
            return 1;
        }
}

int main ()
{
    int info;
    no *lista;
    char resp1, resp2, resp3;

    cria_lista(&lista);

    /*parte de inserir ordenado*/
    do
    {
        printf("\nDigite o elemento a ser inserido na lista: ");
        scanf("%d", &info);

        insere_ordenado(&lista, info);
        mostra_lista(lista);

        do
        {
            resp1 = toupper(getchar());
        } while (resp1 != 'N' && resp1 != 'S');
        
    } while (resp1 != 'N');

    /*parte da remocao no inicio*/
        do
        {
            mostra_lista(lista);
            printf("\nRemover primeiro elemento? (S/N)\n");
            
            do
            {
                resp2 = toupper(getchar());
            } while (resp2 != 'N' && resp2 != 'S');

            if (resp2 != 'N') 
			{
				remove_inicio(&lista);
				mostra_lista(lista);
			}

                else continue;
            
                printf("\nContinua? S/N");

                do
                {
                resp3 = toupper(getchar());
                } while (resp3 != 'N' && resp3 != 'S');
            
        } while (resp3 != 'N');
        
    return 0;
}