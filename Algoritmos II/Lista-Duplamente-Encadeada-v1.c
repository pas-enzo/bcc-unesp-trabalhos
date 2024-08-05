// Operacoes em uma Lista Linear Duplamente Encadeada
#include <stdlib.h>
#include <stdio.h>

typedef struct reg *no;
struct reg {
    int info;
    no ant, prox;  //struct reg *ant, *prox;
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
// Inclui um elemento no inicio da lista linear duplamente encadeada
//------------------------------------------------------------------------------
void inclui_inicio_LLDE (no *lista, int info) {
  no p = (no) malloc(sizeof(struct reg ));
  p->ant = NULL;  
  p->info = info;
  p->prox = *lista;
  if (*lista) 
    (*lista)->ant = p;
  *lista = p;
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
     inclui_inicio_LLDE (&lista,info);
     mostra_LLDE (lista);             
     printf ("\nContinua (S/N)? \n");   
     do {
        resp = toupper(getch());
     } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_LLDE (lista);
  mostra_LLDE_contrario (lista);
  return 0;
}   
