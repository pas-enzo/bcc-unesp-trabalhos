#include <stdlib.h>
#include <stdio.h>
//---------------------------------------------------------
// Declaração de uma lista simplesmente encadeada
//---------------------------------------------------------
typedef struct reg *no;
struct reg {
  int info;
  struct reg *prox;
};
//---------------------------------------------------------
// Cria uma lista vazia
//---------------------------------------------------------
void cria_lista (no *lista) {
  *lista = NULL;
}
//---------------------------------------------------------
// Inclui um elemento no início da lista
//---------------------------------------------------------
void inclui_inicio (no *lista, int info){
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  p->prox = *lista;
  *lista = p;
}	
//---------------------------------------------------------
// Mostra os elementos da lista
//---------------------------------------------------------
void mostra_lista (no lista) {
  no p = lista;
  printf ("\nElementos da lista: ");
  while (p) {   // while (p != NULL)
    printf ("%d ",p->info);
    p = p->prox;
  }
}
//---------------------------------------------------------
// Conta o numero de elementos da lista
//---------------------------------------------------------
int conta_nos (no lista){
  no p = lista;
  int n = 0;
  while (p != NULL){   // while (p)
    n++;
    p = p->prox;
  }
  return n;
}
//---------------------------------------------------------
int main () {
  int info;
  char resp;
  no lista;
  cria_lista (&lista);   // lista = NULL;
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    inclui_inicio (&lista,info);
    mostra_lista (lista);
    printf ("\nContinua (S/N)?");
    do {
      resp = toupper(getchar());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
  mostra_lista (lista);
  printf ("\nQte de elementos da lista: %d",conta_nos(lista));
}
