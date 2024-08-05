#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

struct reg 
{
	int info;
	struct reg *prox;	
};

no *lista;

void cria_LCSE (no *lista)
{
	*lista = NULL;
}

void insere_inicio_LCSE (no *lista, int info)
{
	no p = (no)malloc(sizeof(struct reg));
	p->info = info;
	
	if (!*lista)
	{
		p->prox = p;
		*lista = p;
	}
	
	else
	{
		no q = *lista;
		
		while (q->prox != *lista) 
		{
			q = q->prox;
		}
		
		q->prox = p;
		p->prox = *lista;
		*lista = p;
	}
}

void mostra_LCSE (no lista)
{
	no p = lista;
	
	printf("\nElementos da lista: ");
	
	do
	{
		printf("%d ", p->info);
		p = p->prox;
	} while (p != lista);
}

int remove_instancias_LCSE (no *lista, int elem)
{	
	if (*lista == NULL) return 0;
	
	if (elem == (*lista)->info)
	{
		no q = *lista;
		
		if(*lista = (*lista)->prox) *lista = NULL;
		
		else
		{
			no q = *lista;
			while (q->prox != *lista) q = q->prox;
			q->prox = (*lista)->prox;
			*lista = (*lista)->prox;	
		}
		
		free(q);
		return 1;
	}
	
	no q = *lista, r;
	
	do
	{	
		no q = *lista, r;
		
		do
		{
			r = q;
			q = q->prox;
		} while (q->info != elem && q->prox != *lista);
		r->prox = q->prox;
		free(q);		
	} while (q->prox != *lista);
	
	return 1;
}

int main () 
{
	int info, elem;
	no lista;
	char resp;
	
	cria_LCSE(&lista);
	//inclui
	do 
	{
		printf("\nDigite um numero a ser inserido na lista: ");
		scanf("%d", &info);
		
		insere_inicio_LCSE (&lista,info);
		mostra_LCSE(lista);
		
		printf("\nContinua? (S/N)");
		
		do
		{
			resp = toupper(getch());
		} while (resp != 'N' && resp != 'S');
	} while (resp != 'N');
	
	//remove
	
	do
	{
		printf("\nDigite o elemento cujas instancias serao removidas: ");
		scanf("%d", &elem);
		
		remove_instancias_LCSE(&lista,elem);
		mostra_LCSE(lista);
		
		printf("\nContinua? (S/N)");
		
		do
		{
			resp = toupper(getch());
		} while (resp != 'N' && resp != 'S');
	} while (resp != 'N');
		
}