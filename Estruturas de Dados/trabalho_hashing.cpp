#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101
#define MAX_COLLISIONS 20
#define MAX_KEY_LENGTH 15

struct Element {
    char key[MAX_KEY_LENGTH + 1];
    int empty;
    struct Element* next;
};

int Hash(const char* key);
void addEnderecamentoAberto(struct Element table[], const char* key);
void addEncadeamento(struct Element* table[], const char* key);
void rem(struct Element table[], const char* key);
int find(const struct Element table[], const char* key, int* index);
void relatorio(const struct Element table[], struct Element* chainingTable[]);

int main() {
    struct Element openAddressingTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        openAddressingTable[i].empty = 1;
        openAddressingTable[i].next = NULL;
    }

    struct Element* chainingTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        chainingTable[i] = NULL;
    }

    // Conjunto de teste 1
    addEnderecamentoAberto(openAddressingTable, "key1");
    addEnderecamentoAberto(openAddressingTable, "key2");
    addEnderecamentoAberto(openAddressingTable, "key3");
    addEnderecamentoAberto(openAddressingTable, "key4");
    addEnderecamentoAberto(openAddressingTable, "key5");
    addEncadeamento(chainingTable, "key1");
    addEncadeamento(chainingTable, "key2");
    addEncadeamento(chainingTable, "key3");
    addEncadeamento(chainingTable, "key4");
    addEncadeamento(chainingTable, "key5");

    // Conjunto de teste 2
    addEnderecamentoAberto(openAddressingTable, "abc");
    addEnderecamentoAberto(openAddressingTable, "def");
    addEnderecamentoAberto(openAddressingTable, "ghi");
    addEncadeamento(chainingTable, "abc");
    addEncadeamento(chainingTable, "def");
    addEncadeamento(chainingTable, "ghi");

    int index;
    int found = find(openAddressingTable, "key3", &index);
    if (found) {
        printf("Elemento encontrado no endereço %d\n", index);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    rem(openAddressingTable, "key4");

    relatorio(openAddressingTable, chainingTable);

    return 0;
}

int Hash(const char* key) {
    int sum = 0;
    int length = strlen(key);
    for (int i = 0; i < length; ++i) {
        sum += (i + 1) * (int)(key[i]);
    }
    return sum % TABLE_SIZE;
}

void addEnderecamentoAberto(struct Element table[], const char* key) {
    int index = Hash(key);
    int j = 1;
    int attempts = 0;
    while (attempts < MAX_COLLISIONS) {
        int newIndex = (index + j * j + 23 * j) % TABLE_SIZE;
        if (table[newIndex].empty) {
            strcpy(table[newIndex].key, key);
            table[newIndex].empty = 0;
            return;
        }
        ++j;
        ++attempts;
    }
    printf("Nao foi possível inserir a chave %s apos %d tentativas.\n", key, MAX_COLLISIONS);
}

void addEncadeamento(struct Element* table[], const char* key) {
    int index = Hash(key);
    struct Element* newElement = (struct Element*)malloc(sizeof(struct Element));
    strcpy(newElement->key, key);
    newElement->empty = 0;
    newElement->next = NULL;

    if (table[index] == NULL) {
        table[index] = newElement;
    } else {
        struct Element* currentNode = table[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newElement;
    }
}

void rem(struct Element table[], const char* key) {
    int index;
    int found = find(table, key, &index);
    if (found) {
        table[index].empty = 1;
    }
}

int find(const struct Element table[], const char* key, int* index) {
    *index = Hash(key);

    // Verificar na tabela de dispersão
    if (!table[*index].empty && strcmp(table[*index].key, key) == 0) {
        return 1;
    }

    // Verificar na lista encadeada, se existir
    struct Element* currentNode = table[*index].next;
    while (currentNode != NULL) {
        if (strcmp(currentNode->key, key) == 0) {
            return 1;
        }
        currentNode = currentNode->next;
    }

    return 0;
}

void relatorio(const struct Element table[], struct Element* chainingTable[]) {
    FILE* file = fopen("relatorio.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de relatorio.\n");
        return;
    }

    fprintf(file, "Conjunto de Entrada:\n");
    fprintf(file, "ADD: chave\n");
    fprintf(file, "REM: chave\n");
    fprintf(file, "FIND: chave\n");

    int totalCollisions = 0;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (!table[i].empty) {
            fprintf(file, "Endereco %d: %s\n", i, table[i].key);
        }
    }

    fprintf(file, "Total de colisoes no metodo de enderecamento aberto: %d\n", totalCollisions);

    int totalKeys = 0;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        struct Element* currentNode = chainingTable[i];
        while (currentNode != NULL) {
            ++totalKeys;
            currentNode = currentNode->next;
        }
    }

    fprintf(file, "Total de chaves armazenadas na tabela de encadeamento externo: %d\n", totalKeys);

    fprintf(file, "Enderecos e chaves das posicoes nao vazias da tabela de encadeamento externo:\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        struct Element* currentNode = chainingTable[i];
        if (currentNode != NULL) {
            fprintf(file, "Endereco %d: ", i);
            while (currentNode != NULL) {
                fprintf(file, "%s ", currentNode->key);
                currentNode = currentNode->next;
            }
            fprintf(file, "\n");
        }
    }

    fclose(file);
}