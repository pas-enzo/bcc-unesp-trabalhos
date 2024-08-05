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
// Inclui um elemento no final da lista com descritor
//----------------------------------------------------
void insere_final_LSECD (Descritor *lista, int info) {
  no p;
  p = (no)malloc(sizeof(struct reg));
  p->info = info;
  p->prox = NULL;
  if ((*lista).qte == 0)
    (*lista).prim = p;
  else
    (*lista).ult->prox = p;
  (*lista).ult = p;
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
    insere_final_LSECD (&lista,info);
    mostra_LSECD (lista);
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
}        
