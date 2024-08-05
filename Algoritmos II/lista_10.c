#include <stdio.h>
#include <stdlib.h>
//apesar de possuir descritor, a lista continua sendo simplelmente encadeada
//ou seja, nao ha necessidade de se preocupar com o ultimo no ligando com o primeiro, pois este nao sera circular

typedef struct reg *no;

struct reg 
{
    int info;
    struct reg *prox;
};

typedef struct 
{
    no prim, ult;
    int qte;
} Descritor;

void cria_listacomdescritor (Descritor *lista) 
{
    (*lista).prim = (*lista).ult = NULL;
    (*lista).qte = 0;
}

void insere_inicio_LSECD (Descritor *lista, int info)
{
    no p;
    p = (no)malloc(sizeof(struct reg));
    p->info = info;
    
    p->prox = (*lista).prim; // proixmo do p recebe o que veio antes dele, mesmo se for nulo
    (*lista).prim = p;//depois, troca-se o primeiro antigo pelo novo, que no caso sera o p

    if ((*lista).qte == 0) (*lista).ult = p;//o ult e definido na primeira instancia, e depois nao se altera

    (*lista).qte++;
}

void insere_final_LSECD (Descritor *lista, int info)
{
    no p;
    p = (no)malloc(sizeof(struct reg));
    p->info = info;
    p->prox = NULL;

    if (*lista.qte == 0) (*lista).prim = p; //no caso em que nao haja outros elementos, p recebe prim de primeiro elem

    else (*lista).ult->prox = p;//se houver, o campo prox do ultimo elemento apontara para o p

    (*lista).ult = p;// ultimo elemento recebe p
    (*lista).qte++;// 1 unidade sera acrescida no final
}

void insere_ordenado_LSECD (Descritor *lista, int info)
{
    no p;
    p = (no)malloc(sizeof(struct reg));
    p->info = info;

    if ((*lista).qte == 0 || (*lista).prim->info > info)//insere inicio
    {
        p->prox = (*lista).prim;
        (*lista).prim = p;

        if ((*lista).qte == 0) (*lista).ult = p;
    }

    else
    {
        no q = (*lista).prim, r;

        do
        {
            r = q;
            q = q->prox;
        } while (q != NULL && q->info < info); //caminha ate o final da lista

        r->prox = p;
        p->prox = q;

        if (q == NULL) (*lista).ult = p;//se o q for nulo, p eh o ultimo elemento da lista
    }
    (*lista).qte++;
}
 
void mostra_LSECD (Descritor lista)
{
    if (lista.qte == 0)
    {
        printf("\nLista vazia");
        return;
    }

    no p = lista.prim;

    printf("\nElementos da lista: ");
    do
    {   
        printf("%d ", p->info);
        p = p->prox;
    } while (p != NULL);

    printf("\nTotal de elementos da lista: %d\n", lista.qte);
}

//exercicio 1
int menor_muda (Descritor *lista)
{
    if ((*lista).qte == 0)
    {
        printf("\nLista vazia.");
        return;
    }

    no p = (*lista).prim;

    do
    {
        if (p = (*lista).prim || p->info < menor) menor = p->info;

        p = p->prox;

    } while (q != NULL);
    

}