#include <stdlib.h>
typedef struct reg *no;
struct reg {
           int info;
           struct reg *prox;
};
//----------------------------------------------------   
// Cria uma lista vazia
//----------------------------------------------------
void cria_lista (no *lista) {
  *lista = NULL;
} 
//----------------------------------------------------
// Inclui um elemento no inicio da lista
//----------------------------------------------------
void inclui_inicio (no *lista, int info){
  no p = (no) malloc(sizeof(struct reg));
  p->info=info;
  p->prox=*lista;
  *lista=p;
}
//----------------------------------------------------
// Mostra os elementos da lista
//----------------------------------------------------
void mostra_lista (no lista) {
  no p = lista;
  printf ("\nElementos da lista: ");
  while (p) {
    printf ("%d ",p->info);
    p = p->prox;
  }
}
//----------------------------------------------------
// Conta o numero de elementos da lista
//----------------------------------------------------
int conta_nos (no lista){
  no p = lista;
  int cont = 0;
  while (p){
    cont++;
    p = p->prox;
  }
  return cont;
}
//----------------------------------------------------
// Inclui um elemento no final da lista
//----------------------------------------------------
void inclui_final (no *lista, int info){
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  p->prox = NULL;
  if (*lista == NULL)
    *lista = p;
  else {
    no q = *lista;
    while (q->prox)
      q = q->prox;
    q->prox = p;
  }
}
//----------------------------------------------------
// Remove elemento do início da lista
//----------------------------------------------------
int remove_inicio (no *lista) {
  // lista vazia
  if (!*lista)
    return 0;
  // lista com pelo menos um elemento
  no p = *lista;
  *lista = (*lista)->prox;
  free(p);
  return 1;
}
//----------------------------------------------------
// Remove elemento do final da lista
//----------------------------------------------------
int remove_final (no *lista) {
  // lista vazia
  if (!*lista) // if (*lista == NULL)
    return 0;
  // lista com apenas um elemento
  if (!(*lista)->prox) {   // if ((*lista)->prox == NULL)
    free (*lista);
    *lista = NULL;                                                                                                                                                                 
    return 1;
  }
  // lista com pelo menos dois elementos
  no p = *lista, q;
  while (p->prox) {  // while (p-prox != NULL)
    q = p;        
    p = p->prox;
  }  
  free (p);
  q->prox = NULL;
  return 1;
}
//----------------------------------------------------
// Verifica se um determinado elemento pertence a lista
//----------------------------------------------------
int busca_lista (no lista, int info) {
  no p = lista;
  while (p) {
    if (p->info == info)
      return 1;
    p = p->prox;
  }    
  return 0;
}
//----------------------------------------------------
// Programa Principal
//----------------------------------------------------
int main () {
  int info;
  no lista;    
  char resp;
  cria_lista (&lista);   // lista = NULL;
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_final (&lista,info);
    mostra_lista (lista);
    printf ("\nQuantidade de elementos na lista: %d",conta_nos(lista));
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
  //--------------------------------------------------------------------------
  printf ("\n\n-----\nRemocao do ultimo elemento da lista realizada!\n");
  if (remove_final (&lista))
    printf ("Elemento do final da lista removido.");
  mostra_lista (lista);
  printf ("\nQuantidade de elementos na lista: %d",conta_nos(lista));
  //--------------------------------------------------------------------------
  printf ("\n\n-----\nBusca de um elemento na lista");
  printf ("\nDigite um numero inteiro: ");
  scanf ("%d",&info);
  if (busca_lista (lista,info)) 
    printf ("\n--> %d pertence a lista",info);
  else
    printf ("\n--> %d nao pertence a lista",info);
  //--------------------------------------------------------------------------  
}        
