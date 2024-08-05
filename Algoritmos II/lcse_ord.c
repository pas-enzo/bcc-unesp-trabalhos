#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct reg *no;

struct reg {
	int info;
	struct reg *prox;
};

no lista;

//o unico null da lista circular será no início (declaração) da lista
void cria_lista (no *lista) {
		
		*lista = NULL;
}

void inclui_ord_lcse (no *lista, int info) {
	
	//inclui no inicio da lista circular simplesmente encadeada (LCSE)
	no p = (no) malloc(sizeof(struct reg));
	p->info = info;
	
	if (!*lista) {
	
		p->prox = p;
		*lista = p;
		
	}
	
	else {
		
		if (info <= (*lista)->info) { //começo
			
			no q = *lista;
					
			while (q->prox != *lista) q = q->prox;
			
			q->prox = p;
			p->prox = *lista;
			*lista = p;
			
		}
		
		else {
			
			no q = *lista, r;
			
				do {
					
					r = q;
					q = q->prox;
					
				} while (q != *lista && q->info < info);
				
			p->prox = q;
			r->prox = p;
			
		}
		
	}
	
	
}

void mostra_lcse (no lista) {
	
	if (lista == NULL) {
		
		printf("Lista vazia.\n");
		return;
		
	}
	
	no p = lista;
	printf("\nElementos da lista: ");
	do {
		
		printf(" %d", p->info);
		p = p->prox;
		
	} while (p!= lista);
	
}

int main () {
	
	int info, i=0;
	char resp;
	
	no lista;	
	
	cria_lista(&lista);
	
	do {
		
		printf("Digite o numero inteiro a ser adicionado:\n");
		scanf("%d", &info);
		inclui_ord_lcse(&lista, info);
		mostra_lcse(lista);
		
		printf("\n\nContinuar? S/N\n");
		do {
			
      		resp = toupper(getchar());
      		
    	} while (resp!='N' && resp!='S');
    	
    	i++;
		
	} while (resp!='N');
	
	printf("\n\n%d numeros adicionados.\n", i);
	
	return 0;
}
