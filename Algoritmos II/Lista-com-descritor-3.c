#include <stdlib.h>

typedef struct reg *no;
struct reg {
           int info;
           struct reg *prox;
};

typedef struct {
 no prim, ult;
 int qte;
 } Descritor;
 
//----------------------------------------------------   
// Cria uma lista simplesmente encadeada com descritor- LSECD
//----------------------------------------------------
void cria_LSECD (Descritor *lista) {
  (*lista).prim = (*lista).ult = NULL;
  (*lista).qte = 0;
} 
//----------------------------------------------------
// Mostra os elementos da lista com descritor
//----------------------------------------------------
void mostra_LSECD (Descritor lista) {
  if (lista.qte == 0) {
    printf ("\nLista vazia");
    return;
  }
  no p = lista.prim;
  printf ("\nElementos da lista: ");
  do {
    printf ("%d ",p->info);
    p = p->prox;
  } while (p != NULL);
  printf ("\nTotal de elementos: %d\n",lista.qte);
}
//----------------------------------------------------
// Inclui um elemento na lista ordenada com descritor
//----------------------------------------------------
void insere_ordenada_LSECD (Descritor *lista, int info) {
  no p = (no)malloc(sizeof(struct reg));
  p->info = info;
  if ((*lista).qte == 0 || (*lista).prim->info>info) {
    p->prox = (*lista).prim;
    (*lista).prim = p;
    if ((*lista).qte == 0)
     (*lista).ult = p;
  }
  else {
    no q = (*lista).prim, r;
    do {
      r = q;
      q = q->prox;
    } while (q != NULL && q->info < info); 
    p->prox = q; 
    r->prox = p;      
    if (q == NULL)
      (*lista).ult = p;
  } 
  (*lista).qte++;
}
//----------------------------------------------------
// Programa Principal
//----------------------------------------------------
int main () {
  int info;
  Descritor lista;    
  char resp;
  cria_LSECD (&lista);
  // Insere elementos na lista
  printf ("I N S E R C A O\n");
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    insere_ordenada_LSECD (&lista,info);
    mostra_LSECD (lista);
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
}        
