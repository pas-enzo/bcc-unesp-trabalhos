// Operacoes em uma Lista Linear Duplamente Encadeada

#include <stdlib.h>

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
// Inclui elemento em uma LLDE ordenada
//------------------------------------------------------------------------------
void inclui_LLDE_ordenada (no *lista, int info){
     no p = (no) malloc(sizeof(struct reg));
     p->info = info;
     // se lista for vazia ou elemento menor que o primeiro elemento da lista
     if (*lista == NULL || info <= (*lista)->info){
          p->ant = NULL;
          p->prox = *lista;
          if (*lista != NULL)
            (*lista)->ant = p;
          *lista = p;
     }     
     else {
          no q = *lista;
          while (q->prox != NULL && q->info <= info)
                q = q->prox;
          if (q->info > info){
            p->prox = q; 
            p->ant = q->ant;
            q->ant->prox = p;
            q->ant = p;
          }  
          else {
            q->prox = p;
            p->ant = q;
            p->prox = NULL;
          }
     } 
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
// Remove elemento do inicio da LLDE
//------------------------------------------------------------------------------
int remove_inicio_LLDE (no *lista) {
  // Lista vazia
  if (!*lista)
     return 0;
  // Lista com apenas um elemento
  if ((*lista)->prox == NULL) {
    free (*lista);
    *lista = NULL;
  }
  // lista com mais de um elemento
  else {
    no p = *lista;
    *lista = p->prox;
    (*lista)->ant = NULL;
    free (p);
  }
  return 1;
} 
//------------------------------------------------------------------------------
// Remove elemento do final da LLDE
//------------------------------------------------------------------------------
int remove_final_LLDE (no *lista) {
  // Lista vazia
  if (!*lista)
    return 0;
  // Lista com apenas um elemento
  if ((*lista)->prox == NULL) {
    free (*lista);
    *lista = NULL;
  }
  // Lista com mais de um elemento
  else {
    no p = *lista;
    while (p->prox != NULL)
      p = p->prox;
    p->ant->prox = NULL;  
    free (p);
  }
  return 1;
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
     inclui_LLDE_ordenada (&lista,info);
     mostra_LLDE (lista);             
     printf ("\nContinua (S/N)? \n");   
     do {
        resp = toupper(getch());
     } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_LLDE (lista);
  mostra_LLDE_contrario (lista);
  printf ("\n\nQuantidade de elementos na lista: %d",conta_nos_LLDE(lista));
  do {
     if (remove_final_LLDE (&lista))
       printf ("\n--->Elemento final removido.\n");
     else
       printf ("\n--->Lista vazia!\n");
     mostra_LLDE (lista);
     mostra_LLDE_contrario (lista);
     printf ("\n\nRemove outro elemento do final da lista (S/N)? ");   
     do {
        resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');    
  return 0;
}   
