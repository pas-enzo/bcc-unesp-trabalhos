// Copia uma Lista Linear Duplamente Encadeada

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
    printf ("\nLista vazia");
    return;
  }
  // posicionar p no último no da lista
  no p = lista;
  while (p->prox != NULL)
    p = p->prox;
  printf ("\nElementos da lista ao contrario: ");
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
          // inserir antes do no q
          if (q->info >= info){
            p->prox = q; 
            p->ant = q->ant;
            q->ant->prox = p;
            q->ant = p;
          }  
          // inserir no final da lista
          else {
            q->prox = p;
            p->ant = q;
            p->prox = NULL;
          }
     } 
}
//------------------------------------------------------------------------------
// Copia uma lista duplamente encadeada
//------------------------------------------------------------------------------
int copia_LLDE (no L1, no *L2) {
  no p, q, r;
  *L2 = NULL;
  p = L1;
  while (p != NULL){
  	q = (no) malloc (sizeof(struct reg));
  	q->info = p->info;
  	if(*L2 == NULL){
  		q->ant = q->prox = NULL;
  		*L2 = q;
 		}
		else{
			q->prox = NULL;
			q->ant = r;
			r->prox = q;			
		}
		r = q;
  	p = p->prox;  
	}
}
//------------------------------------------------------------------------------
// Programa Principal
//------------------------------------------------------------------------------
int main () {
  no lista, copia;    
  int info;
  char resp;
  cria_LLDE (&lista);
  do {
     printf ("\nDigite um numero inteiro: ");
     scanf ("%d",&info);
     inclui_LLDE_ordenada (&lista,info);
     printf ("\nContinua (S/N)? \n");   
     do {
        resp = toupper(getch());
     } while (resp!='N' && resp!='S');
  } while (resp!='N');
  printf ("\nLISTA ORIGINAL");
  mostra_LLDE (lista);
  mostra_LLDE_contrario (lista);
  copia_LLDE (lista,&copia);
	printf ("\n\nLISTA COPIA");
	mostra_LLDE (copia);
  mostra_LLDE_contrario (copia);
	return 0;
}   
