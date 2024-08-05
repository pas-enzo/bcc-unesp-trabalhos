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

void insere_inicio (no *lista, int info)
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

int conta_instancias (no lista, int elem)
{
    no r = lista; //ponteiro auxiliar
    int i=0; //contador de instancias

    while (r)
    {
        if (r->info == elem) i++;
        r = r->prox;
    }

    return i;
}

int main ()
{
    int info, elem;
    no *lista;
    char resp1, resp2;

    cria_lista(&lista);

    do
    {
        printf("\nDigite o numero a ser inserido na lista: ");
        scanf("%d", &info);

        insere_inicio(&lista,info);
        mostra_lista(lista);
        
        printf("\nContinua? (S/N)");

        do
        {
            resp1 = toupper(getchar());
        } while (resp1 != 'N' && resp1 != 'S');
        
    } while (resp1 != 'N');

    do
    {
        printf("\nDigite o numero a ser conferido: ");
        scanf("%d", &elem);

        printf("A quantidade de vezes que o numero %d aparece na lista e: %d", elem, conta_instancias(lista,elem));

        printf("Continua? (S/N)");

        do
        {
            resp2 = toupper(getchar());
        } while (resp2 != 'N' && resp2 != 'S');
        
    } while (resp2 != 'N');

    return 0;
}