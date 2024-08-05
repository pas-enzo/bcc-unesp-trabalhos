// Operacoes em uma Lista Linear Duplamente Encadeada

#include <stdlib.h>
#include <stdio.h>

typedef struct reg *no;
struct reg {
    int info;
    no ant, prox;
};

//------------------------------------------------------------------------------
// Cria uma LLDE vazia
//------------------------------------------------------------------------------
void cria_LLDE (no *lista) {
  *lista = NULL;
} 
//------------------------------------------------------------------------------
// Mostra os elementos da LLDE
//------------------------------------------------------------------------------
void mostra_LLDE (no lista){
  if (lista == NULL) {
    printf ("\n\nLista vazia");
    return;
  }
  no p = lista;
  printf ("\n\nElementos da lista: ");
  do {
    printf ("%d ",p->info);
    p = p->prox;
  } while (p != NULL);
}
//------------------------------------------------------------------------------
// Mostra os elementos da LLDE ao contrario
//------------------------------------------------------------------------------
void mostra_LLDE_contrario (no lista){
  if (lista == NULL) {
    printf ("\n\nLista vazia");
    return;
  }
  // posicionar p no último no da lista
  no p = lista;
  while (p->prox != NULL)
    p = p->prox;
  printf ("\n\nElementos da lista ao contrario: ");
  do {
    printf ("%d ",p->info);
    p = p->ant;
  } while (p != NULL);
}
//------------------------------------------------------------------------------
// Conta o numero de elementos de uma lista duplamente encadeada
//------------------------------------------------------------------------------
int conta_nos_LLDE (no lista) {
  if (lista == NULL)
    return 0;
  no p = lista;
  int n=0;
  do {
    n++;
    p = p->prox;
  } while (p != NULL);
  return n;
}
//------------------------------------------------------------------------------
// Inclui um elemento no final da lista linear duplamente encadeada
//------------------------------------------------------------------------------
void inclui_final_LLDE (no *lista, int info) {
  no p = (no) malloc(sizeof(struct reg ));
  p->info = info;
  p->prox = NULL;
  // se lista vazia
  if (!*lista) {
    p->ant = NULL;
    *lista = p;
  }
  else {
    // posicionar q no último no da lista
    no q = *lista;
    while (q->prox != NULL)
      q = q->prox;
    // inclusao de p no final da lista
    q->prox = p;
    p->ant  = q;
  }
}
//------------------------------------------------------------------------------
// Programa Principal
//------------------------------------------------------------------------------
int main () {
  no lista;    
  int info;
  char resp;
  cria_LLDE (&lista);
  do {
     printf ("\nDigite um numero inteiro: ");
     scanf ("%d",&info);
     inclui_final_LLDE (&lista,info);
     mostra_LLDE (lista);             
     printf ("\nContinua (S/N)? \n");   
     do {
        resp = toupper(getch());
     } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_LLDE (lista);
  mostra_LLDE_contrario (lista);
  printf ("\n\nQuantidade de elementos na lista: %d",conta_nos_LLDE(lista));
  return 0;
}   
