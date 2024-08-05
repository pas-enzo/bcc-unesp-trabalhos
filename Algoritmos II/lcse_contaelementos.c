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
	
	if (!*lista)//se nao houver nenhum elemento na lista
	{
		p->prox = p;
		*lista = p;
	}
	
	else//se houver algum elemento na lista 
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
	
	if (lista == NULL) printf("\nLista vazia!");

	else
	{
		do	
		{
			printf("%d ", p->info);
			p = p->prox;
		} while (p != lista);
	}
}

int conta_instancias_LCSE (no lista, int elem)
{
	no p = lista;
	int i = 0;
	
	if (lista == NULL)
	{
		return 0;
	} 
	
	else 
	{
		do
		{
			if (p->info == elem) i++;
			p = p->prox;
		} while (p != lista);
		
		if (i == 0) return 0;
			
		else return i;
	}
}

int main () 
{
	int info, elem;
	no lista;
	char resp1, resp2;
	
	cria_LCSE(&lista);
	
	do
	{
		printf("\nDigite o elemento a ser adicionado: ");
		scanf("%d", &info);
		
		insere_inicio_LCSE(&lista,info);
		mostra_LCSE(lista);
		
		printf("\nContinua? (S/N)\n");
		
		do
		{
			resp1 = toupper(getchar());
		} while (resp1 != 'N' && resp1 !='S');
	} while (resp1 != 'N');
	
	
	do
	{
		printf("\nDigite o elemento que gostaria de conferir: ");
		scanf("%d", &elem);
		
		mostra_LCSE(lista);
		printf("\nO elemento %d se repete %d vez(es) na lista.", elem, conta_instancias_LCSE(lista, elem));
		
		printf("\nContinua? (S/N)\n");
		
		do
		{
			resp2 = toupper(getchar());
		} while (resp2 != 'N' && resp2 != 'S');
		
	} while (resp2 != 'N');
	
	return 0;
}


















