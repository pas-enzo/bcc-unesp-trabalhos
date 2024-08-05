//feito por Lucca Comerao

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_tabela 101

struct dado {
    char chave[100];
    int flag;
    int tentativas;
};

int Hash(char* chave) {
    int soma = 0;
    int len = strlen(chave);
    for (int loop = 0; loop < len; loop++) {
        soma += (loop + 1) * ((int)chave[loop]);
    }
    soma += 19;

    return soma % tam_tabela;
}

int insereaberto(struct dado tabela[], char *chave) {
    int hash = Hash(chave);
    int tentativa = 1;
    int colisoes = 0;

    while (tentativa < 20) {
        int pos = (hash + tentativa * tentativa + 23 * tentativa) % tam_tabela;

        if (tabela[pos].flag && strcmp(tabela[pos].chave, chave) == 0)
            return -2;

        if (!tabela[pos].flag) {
            strcpy(tabela[pos].chave, chave);
            tabela[pos].flag = 1;
            tabela[pos].tentativas = tentativa;
            return colisoes;
        } else {
            colisoes++;
            tentativa++;
        }
    }

    return -1;
}

void insereencadeado(struct dado tabelaenc[], char *chave) {
    int hash = Hash(chave);
    int pos = hash;

    while (tabelaenc[pos].flag)
        pos = (pos + 1) % tam_tabela;

    strcpy(tabelaenc[pos].chave, chave);
    tabelaenc[pos].flag = 1;
    tabelaenc[pos].tentativas++;
}

int Find(struct dado tabela[], char *chave) {
    int hash = Hash(chave);
    int tentativa = 0;

    while (tentativa < tam_tabela) {
        int pos = (hash + tentativa * tentativa + 23 * tentativa) % tam_tabela;

        if (tabela[pos].flag && strcmp(tabela[pos].chave, chave) == 0)
            return pos;

        tentativa++;
    }

    return -1;
}

void Remove(struct dado tabela[], struct dado tabelaenc[], char *chave) {
    int pos = Find(tabela, chave);
    if (pos != -1) {
        tabela[pos].flag = 0;

        int hash = Hash(chave);
        int i = hash;

        while (tabelaenc[i].flag) {
            if (strcmp(tabelaenc[i].chave, chave) == 0) {
                tabelaenc[i].flag = 0;
                tabelaenc[i].tentativas = 0;
                break;
            }
            i = (i + 1) % tam_tabela;
        }
    }
}

void Relatorio(struct dado tabela[], struct dado tabelaenc[], char *inputFile) {
    FILE *relatorio = fopen("relatorio.txt", "w");
    if (!relatorio) {
        printf("Erro ao abrir o arquivo de relatorio.\n");
        return;
    }

    fprintf(relatorio, "-Entrada-\n");
    FILE *input = fopen(inputFile, "r");
    char operacao[10], chave[100];

    while (fscanf(input, "%s %s", operacao, chave) != EOF)
        fprintf(relatorio, " %s %s\n", operacao, chave);

    fclose(input);
    fprintf(relatorio, "\n\n");
    fprintf(relatorio, "*Total de colisoes:\n");

    int colisoesabertas = 0, colisoesenc = 0;

    for (int i = 0; i < tam_tabela; i++) {
        if (tabela[i].flag)
            colisoesabertas += tabela[i].tentativas - 1;
        if (tabelaenc[i].flag) {
            int colisoes = 0;
            int j = i;
            while (tabelaenc[j].flag) {
                colisoes++;
                j = (j + 1) % tam_tabela;
            }
            if (colisoes > 0)
                colisoesenc += colisoes - 1;
        }
    }

    fprintf(relatorio, "*Colisoes enderecamento aberto: %d\n", colisoesabertas);
    fprintf(relatorio, "* Colisoes com encadeamento: %d\n\n\n", colisoesenc);

    fprintf(relatorio, "Chaves e tentativas - enderecamento aberto:\n");
    int totalChaves = 0;
    for (int pos = 0; pos < tam_tabela; pos++) {
        if (tabela[pos].flag) {
            totalChaves++;
            fprintf(relatorio, " %s - %d tentativas\n", tabela[pos].chave, tabela[pos].tentativas);
        }
    }

    fprintf(relatorio, "\n\n");

    fprintf(relatorio, "*Chaves: %d\n\n", totalChaves);

    fprintf(relatorio, "Endereco e chave das posicoes nao vazias:\n\n");
    fprintf(relatorio, "*Enderecamento aberto:\n");

    for (int i = 0; i < tam_tabela; i++) {
        if (tabela[i].flag)
            fprintf(relatorio, "  endereco %d: %s\n", i, tabela[i].chave);
    }
    fprintf(relatorio, "\n*Encadeamento externo:\n");
    for (int i = 0; i < tam_tabela; i++) {
        if (tabelaenc[i].flag) {
            fprintf(relatorio, "  endereco %d: ", i);
            int j = i;
            while (tabelaenc[j].flag) {
                fprintf(relatorio, "%s", tabelaenc[j].chave);
                j = (j + 1) % tam_tabela;
                if (tabelaenc[j].flag)
                    fprintf(relatorio, " - ");
            }
            fprintf(relatorio, "\n");
        }
    }
    fclose(relatorio);
}

int main() {
    struct dado tabelaaberta[tam_tabela];
    struct dado tabelaenc[tam_tabela];

    for (int i = 0; i < tam_tabela; i++) {
        tabelaaberta[i].flag = 0;
        tabelaaberta[i].tentativas = 0;
        tabelaenc[i].flag = 0;
        tabelaenc[i].tentativas = 0;
    }

    char inputFile[] = "input.txt";

    FILE *input = fopen(inputFile, "r");
    char operacao[10], chave[100];

    while (fscanf(input, "%s %s", operacao, chave) != EOF) {
        if (strcmp(operacao, "find") == 0) {
            int pos = Find(tabelaaberta, chave);

            if (pos != -1)
                printf("Chave encontrada - %d\n", pos);
            else
                printf("Esta chave nao foi encontrada\n");
        } else if (strcmp(operacao, "add") == 0) {
            int colisoes = insereaberto(tabelaaberta, chave);
            if (colisoes != -1 && colisoes != -2)
                printf("Chave inserida com %d colisoes\n", colisoes);
            else if (colisoes == -2)
                printf("Chave existente\n");
            else
                printf("Nao foi possivel inserir a chave depois de muitas tentativas\n");

            insereencadeado(tabelaenc, chave);
        } else if (strcmp(operacao, "rem") == 0) {
            Remove(tabelaaberta, tabelaenc, chave);
            printf("Chave removida\n");
        }
    }
    fclose(input);

    Relatorio(tabelaaberta, tabelaenc, inputFile);

    return 0;
}