/*
Nome: Enzo Campanholo Paschoalini
RA: 221026215
Executado em: Windows 10 (x64) no compilador mingw32-gcc-g++ versão 6.3.0-1 executado em VSCode
IMPORTANTE: o arquivo "Trab1_Compiladores.txt" se encontra dentro da pasta "output" devido à compilação em VSCode
*/

//---------------------------------------------------------------------------------------------------------------------------
/* Bibliotecas, variáveis globais e estruturas */
//---------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 
#include <iostream>
#include <cctype>
#define MAX_SYMBOL 12 
#define MAX_KEYWORD 20  
#define MAX_ATOMO 300               
typedef long long int lld;              
int codigoID;   

typedef struct pares parSimbolo;

struct pares {
    int identificador;           
    char token[MAX_ATOMO];          
};

typedef struct simbolo *tabela;
struct simbolo {
    parSimbolo par;
    struct simbolo *prox;
};

tabela tabelaDeSimbolos;

using namespace std;



//---------------------------------------------------------------------------------------------------------------------------
/* Declaração de funções auxiliares (ver final do código-fonte) */
//---------------------------------------------------------------------------------------------------------------------------

void insereLista(parSimbolo par);

void insereSimboloEspecial(lld *contaSimbolos);

bool abrirArquivo (FILE *(*arq), char *nomeArquivo, char *modo);

int verificaEspecial (char caracter);

int verificaLetra(char caracter);

int verificaNumero(char caracter);

int verificaLetraOuNumero(char caracter);



//---------------------------------------------------------------------------------------------------------------------------
/* Funções obrigatórias: PROXIMO, CODIGO, ERRO */
//---------------------------------------------------------------------------------------------------------------------------

char PROXIMO (FILE *arquivo) {
    return toupper(fgetc(arquivo));
}

int CODIGO (char *atomo, lld *contaSimbolos) {
    tabela p = tabelaDeSimbolos;

    while (p) {
        if(strcmp(p->par.token, atomo) == 0) {
            return p->par.identificador;
        }
        p = p->prox;
    }

    parSimbolo par;
    par.identificador = (*contaSimbolos)++;
    strcpy(par.token, atomo);

    insereLista(par);

    return par.identificador;
}

void ERRO (int linha) {
    cout << endl << "ERRO DE COMPILACAO." << endl << endl;
    cout << "ERRO LEXICO ENCONTRADO NA " << linha << " DO CODIGO FONTE." << endl << endl;
    system("PAUSE");
    exit(0);
}



//---------------------------------------------------------------------------------------------------------------------------
/* Função main */
//---------------------------------------------------------------------------------------------------------------------------

int main () {

    FILE *arq;                                                

    if(abrirArquivo(&arq, "Trab1_Compiladores.txt", "rt")) {
        
        char atomo[MAX_ATOMO] = "\0";
        char caracter = '\0', carAnterior;
        char specialSymbol[5] = "\0";

        codigoID = -1;
        lld contaSimbolos;
        lld linhas = 1;

        tabelaDeSimbolos = NULL;

        insereSimboloEspecial(&contaSimbolos);

        cout << linhas << "\t";

        caracter = PROXIMO(arq);

        while (!feof(arq)) {
            
            strcpy(atomo, "\0");

            strcpy(specialSymbol, "\0");

            if (caracter > 32) {

                if (verificaEspecial(caracter)) {
                    strncat(specialSymbol, &caracter, 1);

                    carAnterior = caracter;
                    caracter = PROXIMO(arq);

                    // >=
                    if (carAnterior == '>')
                    {
                        if (caracter == '=')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    // <=
                    else if (carAnterior == '<')
                    {
                        if (caracter == '=')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    // :=
                    else if (carAnterior == ':')
                    {
                        if (caracter == '=')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    // ..
                    else if (carAnterior == '.')
                    {
                        if (caracter == '.')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    // (*
                    else if (carAnterior == '(')
                    {
                        if (caracter == '*')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    // *)
                    else if (carAnterior == '*')
                    {
                        if (caracter == ')')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }

                    codigoID = CODIGO(specialSymbol, &contaSimbolos);

                    cout << "[" << specialSymbol << ", " << codigoID << "] ";
                }

                else if (verificaLetra(caracter)) {
                    do {
                        strncat(atomo, &caracter, 1);
                        caracter = PROXIMO(arq);
                    } while (verificaLetraOuNumero(caracter));

                    codigoID = CODIGO(atomo, &contaSimbolos);

                    cout << "[" << atomo << ", " << codigoID << "] "; 

                } 

                else if (verificaNumero(caracter)) {

                    do {
                        strncat(atomo, &caracter, 1);
                        caracter = PROXIMO(arq);
                    } while (verificaNumero(caracter));

                    if (verificaLetra(caracter)) {
                        ERRO(linhas);
                    }

                    codigoID = CODIGO(atomo, &contaSimbolos);

                    strcpy(atomo, "NUMBER");
                    cout << "["<< atomo << ", " << codigoID << "] ";
                }

                else {
                    ERRO(linhas);
                }

                if (caracter >= 32) {
                     fseek(arq, -1, SEEK_CUR);
                }

                if (strlen(specialSymbol) > 1) {
                    caracter = PROXIMO(arq);
                }
            }

            if (caracter == '\n') {

                linhas++;

                cout << "\n" << linhas << "\t";
            }

            caracter = PROXIMO(arq);
        }

        cout << "\n\nANALISE LEXICA CONCLUIDA COM SUCESSO. TOTAL DE LINHAS ANALISADAS: " << linhas << endl << endl;

        fclose(arq);
    }

    else {
        cout << "ERRO NA ABERTURA DO ARQUIVO\n" << endl;
    }

    system("PAUSE");
    return 0;
}



//---------------------------------------------------------------------------------------------------------------------------
/* Funções auxiliares */
//---------------------------------------------------------------------------------------------------------------------------

// Funções de Inserção ---------------------------------------
void insereLista(parSimbolo par){
    //Alocando espaço para inserção
    tabela p = (tabela) malloc(sizeof(struct simbolo));
    //Recebendo a informação
    p->par = par;
    p->prox = NULL;
    
    //Caso a lista esteja nula
    if(tabelaDeSimbolos == NULL){
        tabelaDeSimbolos = p;
    }
    else{
        tabela q = tabelaDeSimbolos;
        while(q->prox){
            q = q->prox;
        }
        q->prox = p;
    }
}

void insereSimboloEspecial(lld *contaSimbolos){
    
    char palavrasChave[][MAX_KEYWORD] = {".", ";", ",", "(", ")", "[", "]",
                                         ":", "=", "<>", ">", "<", ">=", "<=", 
                                         "+", "-", "*", ":=", "..", "(*", "*)", 
                                         "PROGRAM", "LABEL", "VAR", "PROCEDURE",
                                         "FUNCTION", "BEGIN", "END", "IF", 
                                         "THEN", "ELSE", "WHILE", "DO", "OR", 
                                         "AND", "DIV", "NOT", "READ", "WRITE", 
                                         "INTEGER", "BOOLEAN"};
    
    (*contaSimbolos) = 1; 
    int i = 0, tam;
    parSimbolo par;

    //Tamanho da tabela de palavras-chave
    tam = *(&palavrasChave + 1) - palavrasChave; 
    for (i = 0; i < tam; i++)
    {
        par.identificador = (*contaSimbolos)++;
        strcpy(par.token, palavrasChave[i]);

        //Inserção na Tabela de Símbolos
        insereLista(par);
    }
}
//------------------------------------------------------------

// Funções de Arquivo ----------------------------------------
bool abrirArquivo (FILE *(*arq), char *nomeArquivo, char *modo) {
    // tenta abrir o arquivo referenciado
    return ((*arq) = fopen(nomeArquivo, modo));
}
//------------------------------------------------------------

// Funções de Verificação ------------------------------------
int verificaEspecial (char caracter)
{
    char symbols[MAX_SYMBOL] = {'.', ';', ',', '(', 
                                ')', ':', '=', '<', 
                                '>', '+', '-', '*'};

    for (int i=0; i<MAX_SYMBOL; i++) {
        if (caracter == symbols[i]) {
            return 1;
        }
    }
    return 0;
}

int verificaLetra(char caracter){
    return ((caracter >= 'A') && (caracter <= 'Z'));
}

int verificaNumero(char caracter){
    return ((caracter >= '0') && (caracter <= '9'));
}

int verificaLetraOuNumero(char caracter){
    return (verificaLetra(caracter) || verificaNumero(caracter));
}
//------------------------------------------------------------  