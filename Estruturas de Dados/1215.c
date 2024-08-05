#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct no
{
	char* substring;
	struct no *prox;
} No;

typedef struct fila
{
	no *inicio;
	no *fim;
}Fila;

void iniciaFila (Fila *f)
{
	f->inicio = NULL;
	f->fim = NULL;
}

int retornaVazio (Fila *f)
{
	return(f->inicio = NULL && f->fim == NULL);
}

void insereOrdemAlfabetica (Fila *f, char *substring)
{
	No* p = (No*)malloc(sizeof(No));
	p->substring = substring;
	p->prox = NULL;
}



//------------------------------------------------------------------------------------------------------------
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

void enqueue(Queue* q, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

char* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    } else if (q->front == q->rear) {
        char* data = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
        return data;
    } else {
        char* data = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        return data;
    }
}

int main() {
    char str[] = "exemplo de string para dividir";
    char* token = strtok(str, " ");

    Queue q;
    initQueue(&q);

    while (token != NULL) {
        char* substring = (char*)malloc(strlen(token) + 1);
        strcpy(substring, token);
        enqueue(&q, substring);
        token = strtok(NULL, " ");
    }

    while (!isEmpty(&q)) {
        printf("%s\n", dequeue(&q));
    }

    return 0;
}
*/

//-----------------------------------------------------------------------------------------------------