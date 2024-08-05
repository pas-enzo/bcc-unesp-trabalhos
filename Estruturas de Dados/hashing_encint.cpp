#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Definição da estrutura para os nós da tabela hash
struct Node {
    char key[50];
    int value;
    struct Node* next;
};

// Função hash para calcular o índice
int hashFunction(char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return (sum*19) % TABLE_SIZE;
}

// Função para inserir um elemento na tabela hash
void insert(struct Node** table, char* key, int value) {
    int index = hashFunction(key);

    // Criação de um novo nó
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strncpy(newNode->key, key, 50);
    newNode->value = value;
    newNode->next = NULL;

    // Verifica se o índice da tabela está vazio
    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        // Caso contrário, insere o novo nó no início da lista encadeada
        newNode->next = table[index];
        table[index] = newNode;
    }
}

// Função para imprimir a tabela hash
void printHashTable(struct Node** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        struct Node* currentNode = table[i];
        while (currentNode != NULL) {
            printf("(%s, %d) ", currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int main() {
    // Criação da tabela hash
    struct Node* table[TABLE_SIZE];

    // Inicializa todos os elementos da tabela com NULL
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }

    // Exemplo de inserção de elementos na tabela hash
    insert(table, "apple", 10);
    insert(table, "banana", 5);
    insert(table, "orange", 8);
    insert(table, "grape", 15);
    insert(table, "melon", 12);

    // Imprime a tabela hash
    printHashTable(table);

    return 0;
}