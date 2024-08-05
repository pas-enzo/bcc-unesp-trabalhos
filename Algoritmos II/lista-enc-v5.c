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
// Inclui um elemento no início da lista
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
  p->info=info;
  p->prox=NULL;
  if (*lista==NULL)
    *lista = p;
  else {
    no q = *lista;
    while (q->prox)
      q = q->prox;
    q->prox = p;
  }
}
//------------------------------------------------------
// Remove um elemento de uma lista simplesmente encadeada
//------------------------------------------------------
int remove_elem (no *lista, int elem) {
  if (!*lista) // if (*lista == NULL)
    return 0;
  if (elem == (*lista)->info) {
    no q = *lista;
    *lista = (*lista)->prox;
    free (q);
    return 1;
  }
  no q = *lista, r;
  do {
    r = q;        
    q = q->prox;
  } while (q!= NULL && q->info != elem);
  if (q == NULL || q->info != elem)
    return 0;
  r->prox = q->prox;
  free (q);
  return 1;
}
//------------------------------------------------------
// Remove todas as ocorrências um elemento de uma lista simplesmente encadeada
//------------------------------------------------------
int remove_todos_elem (no *lista, int elem) {
  int achou = 0;  
  if (!*lista)
    return 0;
  // Se elemento estiver no início da lista
  while ((*lista) != NULL && elem == (*lista)->info) {
    no q = *lista;
    *lista = (*lista)->prox;
    free (q);
    achou = 1;
  }
  no q = *lista, r;
  // Se elemento estiver no meio da lista
  while (q != NULL) {
    r = q;        
    q = q->prox;
    if (q!= NULL && q->info == elem){
      r->prox = q->prox;
      free (q);
      q = r;          
      achou = 1;
    }
  };
  return achou;
}
//----------------------------------------------------
// Programa Principal
//----------------------------------------------------
int main () {
  int info;
  no lista;    
  char resp;
  cria_lista (&lista);
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
  // Remove elementos na lista
  printf ("\n\nR E M O C A O");
  do {
    printf ("\n\nDigite o elemento que deseja remover: ");
    scanf ("%d",&info);
    if (remove_todos_elem (&lista,info))
      printf ("-> %d removido.",info);
    else  
      printf ("-> elemento %d nao pertence a lista.",info);    mostra_lista (lista);
    printf ("\nQuantidade de elementos na lista: %d",conta_nos(lista));
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
}        
