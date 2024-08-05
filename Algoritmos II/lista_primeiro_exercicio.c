#include <stdio.h>
#include <stdlib.h>

typedef struct reg *no;

typedef struct reg {
	
	int info;
	struct reg *prox;
	
};

no lista;

void cria_lista (no *lista) {
	
	*lista = NULL;
	
}

void inclui_final (no *lista, int info) {
	
	no p = (no) malloc(sizeof(struct reg));
	p->info = info;
	p->prox = NULL;
	
	if(*lista==NULL)
		*lista = p;
		
		else {
			no q = *lista;
			
			while (q->prox)
				q = q->prox;
				
			q->prox = p;
		}
	
}


int main () {
	
	int continua, i=0;
	no lista;
	
	void cria_lista(lista)
	
	while (1) {
		
		if(i)
			printf("Gostaria de inserir outro elemento na lista?\n");
		
		scanf("%d", &continua);
		
		while (continua!=1 && continua!=0) {
			printf("Erro! 1 para continuar a insercao, 0 para parar de inserir.\n\n");
			scanf("%d", &continua);
		}
		
		
		
	}
	
}








