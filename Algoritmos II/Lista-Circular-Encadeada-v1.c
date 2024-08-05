#include <stdlib.h>

typedef struct reg *no;
struct reg {
  int info;
  struct reg *prox;
};
//----------------------------------------------------   
// Cria uma lista vazia
//----------------------------------------------------
void cria_LCSE (no *lista) {
     *lista = NULL;
} 
//----------------------------------------------------
// Mostra os elementos da lista circular
//----------------------------------------------------
void mostra_LCSE (no lista) {
  if (lista == NULL) {
    printf ("\nLista vazia");
    return;
  }
  no p = lista;
  printf ("\nElementos da lista: ");
  do {
    printf ("%d ",p->info);
    p = p->prox;
  } while (p != lista);
}
//----------------------------------------------------
// Inclui um elemento no inicio da lista circular
//----------------------------------------------------
void inclui_inicio_LCSE (no *lista, int info) {
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  if (!*lista) {  // if (*lista == NULL)
    p->prox = p;
    *lista = p;
  }
  else {
    no q = *lista;
    while (q->prox != *lista)
      q = q->prox;
    q->prox = p;
    p->prox = *lista;
    *lista = p;
  }
}
//----------------------------------------------------
// Programa Principal
//----------------------------------------------------
int main () {
  int info;
  no lista;    
  char resp;
  cria_LCSE (&lista);  // lista = NULL;
  // Insere elementos na lista
  printf ("I N S E R C A O\n");
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_inicio_LCSE (&lista,info);
    mostra_LCSE (lista);
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
}        
