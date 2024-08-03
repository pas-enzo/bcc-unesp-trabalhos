/*
Nome: Enzo Campanholo Paschoalini
RA: 221026215

Executado em: Windows 10 (x64) no compilador mingw32-gcc-g++ versão 6.3.0-1 executado em VSCode
IMPORTANTE: o arquivo "Exemplo1_Trab2_Compiladores.txt" se encontra dentro da pasta "output" devido à compilação em VSCode
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Identificadores para a análise sintática
#define PROGRAM 1
#define LABEL 2
#define VAR 3
#define PROCEDURE 4
#define FUNCTION 5
#define BEGIN 6
#define END 7
#define IF 8
#define THEN 9
#define ELSE 10
#define WHILE 11
#define DO 12
#define OR 13
#define AND 14
#define DIV 15
#define NOT 16
#define PONTO_FINAL 17
#define PONTO_VIRGULA 18
#define VIRGULA 19
#define ABRE_PARENTESIS 20
#define FECHA_PARENTESIS 21
#define ABRE_COLCHETES 22
#define FECHA_COLCHETES 23
#define DOIS_PONTOS 24
#define IGUAL 25
#define DIFERENTE 26
#define MAIOR_QUE 27
#define MENOR_QUE 28
#define MAIOR_IGUAL_QUE 29
#define MENOR_IGUAL_QUE 30
#define SOMA 31                 // Símbolo: +
#define SUBTRAI 32              // Símbolo: -
#define MULTIPLICA 33           // Símbolo: *
#define DOISPONTOS_IGUAL 34     // Símbolo: :=
#define PONTO_PONTO 35          // Símbolo: ..
#define ABRE_COMENTARIO 36      // Símbolo: (*
#define FECHA_COMENTARIO 37     // Símbolo: *)
#define READ 38                 // Símbolo: read(var)
#define WRITE 39                // Símbolo: write(var)
#define INTEIRO 40              // Palavra: integer
#define BOOLEANO 41             // Palavra: boolean
#define TOKEN 42                // Todo token que não é palavra/simbolo reservado
#define NUMERO 43               // Todo número associado no código-fonte (valores)

#define MAX_LETTERS 1000        // Máximo de Caracteres para um Token
#define MAX_KEYWORD 10          // Máximo de Caracteres por Token/Símbolo Reservado
#define MAX_SYMBOL 15           // Máximo de Caracteres para um Símbolo

typedef long long int lld;

//-------------------------------------------------------------------------------
/* Estruturas de dados e variáveis globais */
//-------------------------------------------------------------------------------

//Marca o código de identificação do último átomo analisado pela Análise Léxica
int codigoID;

// Fila dinâmica - estrutura para token
struct struct_tuple_token
{
    int identifier;             //Identificador: valor inteiro do token na tabela de símbolos da análise léxica
    char token[MAX_LETTERS];    //Token: cadeia de caracteres
    lld line;                   //Linha do Token: linha em que o token está
};
typedef struct struct_tuple_token tuple_token;

//Variável tupla para obter o elemento atual para Análise Sintática
tuple_token tokenSyntactical;

//Estrutura da Fila
typedef struct struct_queue *queue;
struct struct_queue
{
    tuple_token element;
    queue next;
};

//Fila contendo cada token, sua linha respectiva e seu identificador
queue token;

//Par contendo o identificador e token associado
typedef struct struct_pair_symbol pairSymbol;
struct struct_pair_symbol
{
    int identifier;          //Salva o identificador (número) do átomo associado
    char token[MAX_LETTERS]; //Salva o átomo associado
};

//Tabela de Símbolos PRÉ-DEFINIDOS por LISTA ENCADEADA
typedef struct struct_symbol_table *table;
struct struct_symbol_table
{
    pairSymbol pair;
    struct symbol *prox;
};
table symbolTable;

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/* Declaração de funcções para cada regra da gramática simplificada do Pascal */
//-------------------------------------------------------------------------------

void PROGRAMA();

void BLOCO();

void PARTE_DECLARACAO_VARIAVEL();

void DECLARACAO_VARIAVEL();

void LISTA_IDENTIFICADOR();

void TIPO_VARIAVEL();

void AUXILIAR_DECLARACAO_VARIAVEL();

void PARTE_DECLARACAO_SUBTORINA();

void DECLARACAO_PROCEDIMENTO();

void DECLARACAO_FUNCAO();

void PARAMETROS_FORMAIS();

void SECAO_PARAMETROS_FORMAIS();

void PARTE_SECAO_PARAMETROS_FORMAIS();

void LISTA_IDENTIFICADOR_PARAMETROS_FORMAIS();

void FIM_SECAO_PARAMETROS_FORMAIS();

void COMANDO_COMPOSTO();

void COMANDO();

void FIM_COMANDO();

void COMANDO_SEM_ROTULO();

void ATRIBUICAO_OU_PROCEDIMENTO();

void ATRIBUICAO();

void CHAMADA_PROCEDIMENTO();

void COMANDO_CONDICIONAL();

void FIM_COMANDO_CONDICIONAL();

void COMANDO_REPETITIVO();

void COMANDO_LEITURA_DADOS();

void FIM_COMANDO_LEITURA_DADOS();

void EXPRESSAO();

void EXPRESSAO_SIMPLES();

void EXPRESSAO_SIMPLES_OPCIONAL();

void EXPRESSAO_COM_RELACAO();

void LISTA_DE_EXPRESSAO();

void TERMO();

void FATOR();

void FATOR_COM_OPERACAO();

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/* Declaração de Funções */
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/* Operações de fila */
//-------------------------------------------------------------------------------

//Alocação de Elemento
queue allocFila(int *identifier, char *token_word, lld *line);

//Verifica se Fila está vazia
int verFilaVazia(queue q);

//Inserção na Fila
void pushFila(int *identifier, char *token_word, lld *line);

//Remover da Fila
void popFila();

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
/* Análise Léxica */
//-------------------------------------------------------------------------------

//Inserir ao fim da Tabela de Símbolos
void insereFinal(pairSymbol pair);

//Verificador de SÍMBOLOS ESPECIAIS
int verificaEspecial(char character);

//Verificador de LETRAS
int verificaLetra(char character);

//Verificador de NÚMEROS
int verificaNumero(char character);

//Verificador de LETRAS e DÍGITOS
int verificaLetraOuNumero(char character);

//Verificador de NÚMEROS (0 até 9)
int verificaSomenteNumero(char *word);

//Inserir os Símbolos Especiais, Símbolos Especiais Compostos e Palavras-Chave na Tabela de Símbolos
void insereEspecialTabela(int *countTableSymbol);

//Função PROXIMO: responsável por ler o arquivo que contenha o código-fonte
char *PROXIMO_LEXICO(FILE *file);

//Função CÓDIGO: responsável por retornar o par(id, token) caso contido na Tabela de Símbolos
int CODIGO_LEXICO(char *token, int *countTableSymbol);

//Função ERRO: retorna um erro ao usuário e a linha em que foi encontrado o erro
void ERRO_LEXICO(lld line);

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
/* Análise Sintática */
//-------------------------------------------------------------------------------

//Utilizada para mostrar o respectivo erro da Análise Sintática
char *convertIDtoToken();

void syntacticError();

void parser(int identifier);

//Início da Análise Sintática pela análise do PROGRAM
void startSyntacticAnalyzer();

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
/* Funções para cada regra da gramática simplificada do Pascal */
//-------------------------------------------------------------------------------

void PROGRAMA()
{
    switch (tokenSyntactical.identifier)
    {
    case PROGRAM:
        parser(PROGRAM);
        parser(TOKEN);
        parser(PONTO_VIRGULA);
        BLOCO();
        parser(PONTO_FINAL);
        break;
    default:
        syntacticError();
    }
}

void BLOCO()
{
    switch (tokenSyntactical.identifier)
    {
    case VAR:
        PARTE_DECLARACAO_VARIAVEL();
        break;
    case PROCEDURE:
        PARTE_DECLARACAO_SUBTORINA();
        break;
    case FUNCTION:
        PARTE_DECLARACAO_SUBTORINA();
        break;
    case BEGIN:
        COMANDO_COMPOSTO();
        break;
    default:
        syntacticError();
    }
}

void PARTE_DECLARACAO_VARIAVEL()
{
    switch (tokenSyntactical.identifier)
    {
    case VAR:
        parser(VAR);
        DECLARACAO_VARIAVEL();
        break;
    default:
        syntacticError();
    }
}

void DECLARACAO_VARIAVEL()
{
    switch (tokenSyntactical.identifier)
    {
    case TOKEN:
        parser(TOKEN);         
        LISTA_IDENTIFICADOR();
        break;
    default:
        syntacticError();
    }
}

void LISTA_IDENTIFICADOR()
{
    switch (tokenSyntactical.identifier)
    {
    case VIRGULA:
        parser(VIRGULA);
        DECLARACAO_VARIAVEL(); 
        break;
    case DOIS_PONTOS:
        parser(DOIS_PONTOS);
        TIPO_VARIAVEL();
        parser(PONTO_VIRGULA); 

        AUXILIAR_DECLARACAO_VARIAVEL();
        break;
    default:
        syntacticError();
    }
}

void TIPO_VARIAVEL()
{
    switch (tokenSyntactical.identifier)
    {
    case INTEIRO:
        parser(INTEIRO);
        break;
    case BOOLEANO:
        parser(BOOLEANO);
        break;
    default:
        syntacticError();
    }
}

void AUXILIAR_DECLARACAO_VARIAVEL()
{
    switch (tokenSyntactical.identifier)
    {
    case TOKEN:
        DECLARACAO_VARIAVEL();
        break;
    case PROCEDURE:
        BLOCO();
        break;
    case FUNCTION:
        BLOCO();
        break;
    case BEGIN:
        BLOCO();
        break;
    default:
        syntacticError();
    }
}

void PARTE_DECLARACAO_SUBTORINA()
{
    switch (tokenSyntactical.identifier)
    {
    case PROCEDURE:
        parser(PROCEDURE);
        DECLARACAO_PROCEDIMENTO();
        break;
    case FUNCTION:
        parser(FUNCTION);
        DECLARACAO_FUNCAO();
        break;
    default:
        syntacticError();
    }
}

void DECLARACAO_PROCEDIMENTO()
{
    switch (tokenSyntactical.identifier)
    {
    case TOKEN:
        parser(TOKEN);
        PARAMETROS_FORMAIS();
        parser(PONTO_VIRGULA);
        BLOCO();
        break;
    default:
        syntacticError();
    }
}

void DECLARACAO_FUNCAO()
{
    switch (tokenSyntactical.identifier)
    {
    case TOKEN:
        parser(TOKEN);
        PARAMETROS_FORMAIS();
        parser(DOIS_PONTOS);
        parser(TOKEN);
        parser(PONTO_VIRGULA);
        BLOCO();
        break;
    default:
        syntacticError();
    }
}

void PARAMETROS_FORMAIS()
{
    switch (tokenSyntactical.identifier)
    {
    case ABRE_PARENTESIS:
        parser(ABRE_PARENTESIS);
        SECAO_PARAMETROS_FORMAIS();
        parser(FECHA_PARENTESIS);
        break;
    case DOIS_PONTOS:
        break;
    case PONTO_VIRGULA:
        break;
    default:
        syntacticError();
    }
}

void SECAO_PARAMETROS_FORMAIS()
{
    switch (tokenSyntactical.identifier)
    {
    case VAR:
        parser(VAR);
        PARTE_SECAO_PARAMETROS_FORMAIS();
        break;
    case TOKEN:
        PARTE_SECAO_PARAMETROS_FORMAIS();
        break;
    default:
        syntacticError();
    }
}

void PARTE_SECAO_PARAMETROS_FORMAIS()
{
    switch (tokenSyntactical.identifier)
    {
    case TOKEN:
        parser(TOKEN);
        LISTA_IDENTIFICADOR_PARAMETROS_FORMAIS();
        break;
    default:
        syntacticError();
    }
}

void LISTA_IDENTIFICADOR_PARAMETROS_FORMAIS()
{
    switch (tokenSyntactical.identifier)
    {
    case VIRGULA:
        parser(VIRGULA);
        PARTE_SECAO_PARAMETROS_FORMAIS(); 
        break;
    case DOIS_PONTOS:
        parser(DOIS_PONTOS);
        parser(TOKEN);
        FIM_SECAO_PARAMETROS_FORMAIS(); 
        break;
    default:
        syntacticError();
    }
}

void FIM_SECAO_PARAMETROS_FORMAIS()
{
    switch (tokenSyntactical.identifier)
    {
    case PONTO_VIRGULA:
        parser(PONTO_VIRGULA);
        SECAO_PARAMETROS_FORMAIS();
        break;
    }
}

void COMANDO_COMPOSTO()
{
    switch (tokenSyntactical.identifier)
    {
    case BEGIN:
        parser(BEGIN);
        COMANDO();
        break;
    default:
        syntacticError();
    }
}

void COMANDO()
{
    switch (tokenSyntactical.identifier)
    {
    case NUMERO:
        parser(NUMERO);
        parser(DOIS_PONTOS);
        COMANDO_SEM_ROTULO();
        FIM_COMANDO();
        break;
    default:
        COMANDO_SEM_ROTULO();
        FIM_COMANDO();
        break;
    }
}

void FIM_COMANDO()
{
    switch (tokenSyntactical.identifier)
    {
    case PONTO_VIRGULA:
        parser(PONTO_VIRGULA);
        COMANDO();
        break;
    case END:
        parser(END);
        break;
    }
}

void COMANDO_SEM_ROTULO()
{
    switch (tokenSyntactical.identifier)
    {
    case TOKEN:
        parser(TOKEN);
        ATRIBUICAO_OU_PROCEDIMENTO();
        FIM_COMANDO();
        break;
    case BEGIN:
        COMANDO_COMPOSTO();
        FIM_COMANDO();
        break;
    case END:
        break;
    case IF:
        COMANDO_CONDICIONAL();
        FIM_COMANDO();
        break;
    case WHILE:
        COMANDO_REPETITIVO();
        FIM_COMANDO();
        break;
    case READ:
        parser(READ);
        parser(ABRE_PARENTESIS);
        COMANDO_LEITURA_DADOS();  
        parser(FECHA_PARENTESIS);
        FIM_COMANDO();
        break;
    case WRITE:
        parser(WRITE);
        parser(ABRE_PARENTESIS);
        EXPRESSAO();            
        parser(FECHA_PARENTESIS);
        FIM_COMANDO();
        break;   
    default:
        syntacticError();
    }
}

void ATRIBUICAO_OU_PROCEDIMENTO()
{
    switch (tokenSyntactical.identifier)
    {
    case DOISPONTOS_IGUAL:
        ATRIBUICAO();
        break;
    default:
        CHAMADA_PROCEDIMENTO();
        break;
    }
}

void ATRIBUICAO()
{
    switch (tokenSyntactical.identifier)
    {
    case DOISPONTOS_IGUAL:
        parser(DOISPONTOS_IGUAL);
        EXPRESSAO();
        break;
    default:
        syntacticError();
    }
}

void CHAMADA_PROCEDIMENTO()
{
    switch (tokenSyntactical.identifier)
    {
    case ABRE_PARENTESIS:
        parser(ABRE_PARENTESIS);
        EXPRESSAO();
        parser(FECHA_PARENTESIS);
        break;
    }
}

void COMANDO_CONDICIONAL()
{
    switch (tokenSyntactical.identifier)
    {
    case IF:
        parser(IF);
        EXPRESSAO();
        parser(THEN);
        COMANDO_SEM_ROTULO();
        FIM_COMANDO_CONDICIONAL();
        break;
    default:
        syntacticError();
    }
}

void FIM_COMANDO_CONDICIONAL()
{
    switch (tokenSyntactical.identifier)
    {
    case ELSE:
        parser(ELSE);
        COMANDO_SEM_ROTULO();
        break;
    }
}

void COMANDO_REPETITIVO()
{
    switch (tokenSyntactical.identifier)
    {
    case WHILE:
        parser(WHILE);
        EXPRESSAO();
        parser(DO);
        COMANDO_SEM_ROTULO();
        break;
    default:
        syntacticError();
    }
}

void COMANDO_LEITURA_DADOS()
{
    switch (tokenSyntactical.identifier)
    {
    case TOKEN:
        parser(TOKEN);
        FIM_COMANDO_LEITURA_DADOS();
        break;
    default:
        syntacticError();
    }
}

void FIM_COMANDO_LEITURA_DADOS()
{
    switch (tokenSyntactical.identifier)
    {
    case VIRGULA:
        parser(VIRGULA);
        COMANDO_LEITURA_DADOS();    
        break;
    }
}

void EXPRESSAO()
{
    EXPRESSAO_SIMPLES();
    EXPRESSAO_COM_RELACAO(); 
    LISTA_DE_EXPRESSAO();    
}

void EXPRESSAO_SIMPLES()
{
    switch (tokenSyntactical.identifier)
    {
    case SOMA:
        parser(SOMA);
        TERMO();
        EXPRESSAO_SIMPLES_OPCIONAL();
        break;
    case SUBTRAI:
        parser(SUBTRAI);
        TERMO();
        EXPRESSAO_SIMPLES_OPCIONAL();
        break;
    default:
        TERMO();
        EXPRESSAO_SIMPLES_OPCIONAL();
        break;
    }
}

void EXPRESSAO_SIMPLES_OPCIONAL()
{
    switch (tokenSyntactical.identifier)
    {
    case SOMA:
        parser(SOMA);
        TERMO();
        break;
    case SUBTRAI:
        parser(SUBTRAI);
        TERMO();
        break;
    case OR:
        parser(OR);
        TERMO();
        break;
    }
}

void EXPRESSAO_COM_RELACAO()
{
    switch (tokenSyntactical.identifier)
    {
    case IGUAL:
        parser(IGUAL);
        EXPRESSAO_SIMPLES();
        break;
    case DIFERENTE:
        parser(DIFERENTE);
        EXPRESSAO_SIMPLES();
        break;
    case MENOR_QUE:
        parser(MENOR_QUE);
        EXPRESSAO_SIMPLES();
        break;
    case MENOR_IGUAL_QUE:
        parser(MENOR_IGUAL_QUE);
        EXPRESSAO_SIMPLES();
        break;
    case MAIOR_QUE:
        parser(MAIOR_QUE);
        EXPRESSAO_SIMPLES();
        break;
    case MAIOR_IGUAL_QUE:
        parser(MAIOR_IGUAL_QUE);
        EXPRESSAO_SIMPLES();
        break;
    }
}

void LISTA_DE_EXPRESSAO()
{
    switch (tokenSyntactical.identifier)
    {
    case VIRGULA:
        parser(VIRGULA);
        EXPRESSAO();
        break;
    }
}

void TERMO()
{
    FATOR();
    FATOR_COM_OPERACAO();
}

void FATOR()
{
    switch (tokenSyntactical.identifier)
    {
    case TOKEN:
        parser(TOKEN);
        CHAMADA_PROCEDIMENTO(); 
        break;
    case NUMERO:
        parser(NUMERO);
        break;
    case ABRE_PARENTESIS:
        parser(ABRE_PARENTESIS);
        EXPRESSAO();
        parser(FECHA_PARENTESIS);
        break;
    case NOT:
        parser(NOT);
        FATOR();
        break;
    default:
        syntacticError();
    }
}

void FATOR_COM_OPERACAO()
{
    switch (tokenSyntactical.identifier)
    {
    case MULTIPLICA:
        parser(MULTIPLICA);
        FATOR();
        break;
    case DIV:
        parser(DIV);
        FATOR();
        break;
    case AND:
        parser(AND);
        FATOR();
        break;
    }
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
/* Funções de arquivo */
//-------------------------------------------------------------------------------

//Abrir arquivo TEXTO
int abrirArquivo(FILE *(*file), char *filename, char *mode);

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/* Função Main */
//-------------------------------------------------------------------------------

int main()
{

    token = NULL;

    FILE *file;
    char *filename = "Exemplo1_Trab2_Compiladores.txt"; 
    char *mode = "rt";                                  

    if (abrirArquivo(&file, filename, mode))
    {

        //-------------------------------------------------------------------------------
        /* Análise Léxica*/
        //-------------------------------------------------------------------------------

        //Estruturas do Analisador Léxico
        char lex_token[MAX_LETTERS] = "\0"; 
        codigoID = -1;                     
        int countTableSymbol;              

        //Caractere do Código (variável "proximo") e a do anterior ("s")
        char caracter = '\0', prevCar;

        //Auxiliares para os simbolos especiais compostos
        char specialSymbol[5] = "\0"; 

        //Linha em análise do código
        lld line = 1;

        //Inicializando a Tabela de Símbolos
        symbolTable = NULL;
        insereEspecialTabela(&countTableSymbol);

        //Início de verificação do Analisador Léxico
        caracter = PROXIMO_LEXICO(file); //Realiza a leitura do primeiro caractere
        while (!feof(file))
        {
            //Reseta a string que contém os tokens para próximo token
            strcpy(lex_token, "\0");

            //Reseta a string associada ao símbolo especial composto
            strcpy(specialSymbol, "\0");

            //SPACE na Tabela ASCII = 32
            if (caracter > 32)
            {
                //Análise de Símbolos Especiais e Símbolos Especiais Compostos
                if (verificaEspecial(caracter))
                {
                    //String associada ao símbolo especial composto
                    strncat(specialSymbol, &caracter, 1);

                    //Recuperando o próximo caractere
                    prevCar = caracter;
                    caracter = PROXIMO_LEXICO(file);
                    
                    
                    if (prevCar == '>')
                    {
                        if (caracter == '=')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    else if (prevCar == '<')
                    {
                        if (caracter == '=')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    else if (prevCar == ':')
                    {
                        if (caracter == '=')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    else if (prevCar == '.')
                    {
                        if (caracter == '.')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    else if (prevCar == '(')
                    {
                        if (caracter == '*')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }
                    
                    else if (prevCar == '*')
                    {
                        if (caracter == ')')
                        {
                            strncat(specialSymbol, &caracter, 1);
                        }
                    }

                    //Retorna o valor do Símbolo Especial associado
                    codigoID = CODIGO_LEXICO(specialSymbol, &countTableSymbol);

                    //Salvando os tokens na fila para a análise sintática
                    pushFila(&codigoID, specialSymbol, &line);
                }

                //Análise de Letras e Palavras-Chave
                else if (verificaLetra(caracter))
                {
                    do
                    {
                        strncat(lex_token, &caracter, 1);
                        caracter = PROXIMO_LEXICO(file);
                    } while (verificaLetraOuNumero(caracter));

                    //Retornando o código identificador de uma PALAVRA-CHAVE ou de um novo Átomo
                    codigoID = CODIGO_LEXICO(lex_token, &countTableSymbol);

                    //Salvando os tokens na fila para a análise sintática
                    pushFila(&codigoID, lex_token, &line);
                }

                //Análise de Números
                else if (verificaNumero(caracter))
                {
                    do
                    {
                        strncat(lex_token, &caracter, 1);
                        caracter = PROXIMO_LEXICO(file);
                    } while (verificaNumero(caracter));

                    //Caso haja letras após uma sequencia de números...
                    if (verificaLetra(caracter))
                    {
                        ERRO_LEXICO(line);
                    }

                    //Retornando o código identificador de um NÚMERO
                    codigoID = CODIGO_LEXICO(lex_token, &countTableSymbol);

                    //Salvando os tokens na fila para a análise sintática
                    pushFila(&codigoID, lex_token, &line);
                }

                //Retorna erro em não ocorrência aos casos anteriores
                else
                {
                    ERRO_LEXICO(line);
                }

                //Realizando manipulações no ponteiro de arquivo após espaços vazios
                if (caracter >= 32)
                {
                    fseek(file, -1, SEEK_CUR);
                }

                //Caso tenha tido um símbolo especial, avança o último caractere
                if (strlen(specialSymbol) > 1)
                {
                    caracter = PROXIMO_LEXICO(file);
                }
            }

            //Pulando as quebras de linha e armazenando na variável
            if (caracter == '\n')
            {
                line++;
            }

            //Realiza a leitura eliminando os espaços
            caracter = PROXIMO_LEXICO(file);
        }

        //Fechar arquivo após o uso
        fclose(file);
    }
    else
    {
        //Erro na abertura de arquivo
        printf("Erro na abertura de arquivo!\n\n");
        printf("Pressione ENTER para sair...");
        getchar();
        exit(0);
    }

    //-------------------------------------------------------------------------------
    /* Análise Sintática - realizada somente após a análise léxica */
    //-------------------------------------------------------------------------------
    
    //Início da Análise Sintática pela função startSyntacticAnalyzer
    startSyntacticAnalyzer();

    //Caso tenha analisado tudo, significa que não houve erros: sucesso na análise sintática
    printf("\nSUCESSO NA ANALISE SINTATICA DO CODIGO-FONTE!\n\n");

    printf("Pressione ENTER para sair...");
    getchar();

    return 0;
}

//-------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/* Seção de Funções */
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/* Operações de fila */
//-------------------------------------------------------------------------------

queue allocFila(int *identifier, char *token_word, lld *line)
{
    queue q = (queue)malloc(sizeof(struct struct_queue));
    tuple_token element;

    element.identifier = (*identifier);
    strcpy(element.token, token_word);
    element.line = (*line);

    q->element = element;
    q->next = NULL;

    return q;
}

int verFilaVazia(queue q)
{
    return (q == NULL);
}

void pushFila(int *identifier, char *token_word, lld *line)
{
    //Alocando elemento
    queue element = allocFila(identifier, token_word, line);

    //Se estiver vazia, aloca elemento único
    if (verFilaVazia(token))
    {
        token = element;
    }
    else
    {
        //Se não estiver vazia, aloca mais de um elemento
        element->next = token->next;
    }

    token->next = element;
    token = element;
}

void popFila()
{
    //Não remove se estiver vazia
    if (verFilaVazia(token))
    {
        return;
    }

    //Recuperando elemento da cabeça da lista
    tokenSyntactical.identifier = token->next->element.identifier;
    strcpy(tokenSyntactical.token, token->next->element.token);
    tokenSyntactical.line = token->next->element.line;

    //Recuperando elemento pra eliminar
    queue element = token->next;

    //Se tiver só um elemento
    if (element == token)
    {
        token = NULL;
    }
    //Se tiver mais de um elemento
    else
    {
        token->next = element->next;
    }

    //Eliminando elemento
    free(element);

    //return 1;
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
/* Análise Léxica */
//-------------------------------------------------------------------------------

void insereFinal(pairSymbol pair)
{
    //Alocando espaço para inserção
    table p = (table)malloc(sizeof(struct struct_symbol_table));
    //Recebendo a informação
    p->pair = pair;
    p->prox = NULL;

    //Caso a lista esteja nula
    if (symbolTable == NULL)
    {
        symbolTable = p;
    }
    else
    {
        table q = symbolTable;
        while (q->prox)
        {
            q = q->prox;
        }
        q->prox = p;
    }
}

int verificaEspecial(char character)
{
    //Símbolos Especiais do PASCAL
    char symbols[MAX_SYMBOL] = {".;,()[]:=><+-*"};

    int i;
    for (i = 0; i < MAX_SYMBOL; i++)
    {
        if (character == symbols[i])
        {
            //Caso o caractere seja um símbolo especial
            return 1;
        }
    }
    return 0;
}

int verificaLetra(char character)
{
    return ((character >= 'A') && (character <= 'Z'));
}

int verificaNumero(char character)
{
    return ((character >= '0') && (character <= '9'));
}

int verificaLetraOuNumero(char character)
{
    return (verificaLetra(character) || verificaNumero(character));
}

int verificaSomenteNumero(char *word)
{
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        if (verificaNumero(word[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

void insereEspecialTabela(int *countTableSymbol)
{
    (*countTableSymbol) = 1; //Inicia os identificadores em 1
    int i = 0, size;
    pairSymbol pair;

    // Palavras e Símbolos Reservados do PASCAL
    char keywords[][MAX_KEYWORD] = {"PROGRAM", "LABEL", "VAR", "PROCEDURE",
                                    "FUNCTION", "BEGIN", "END", "IF", "THEN",
                                    "ELSE", "WHILE", "DO", "OR", "AND", "DIV",
                                    "NOT", ".", ";", ",", "(", ")", "[", "]",
                                    ":", "=", "<>", ">", "<", ">=", "<=", "+",
                                    "-", "*", ":=", "..", "(*", "*)",
                                    "READ", "WRITE", "INTEGER", "BOOLEAN"};

    size = *(&keywords + 1) - keywords; //Tamanho da tabela de palavras-chave
    for (i = 0; i < size; i++)
    {
        pair.identifier = (*countTableSymbol)++;
        strcpy(pair.token, keywords[i]);

        //Inserção na Tabela de Símbolos
        insereFinal(pair);
    }
}

char *PROXIMO_LEXICO(FILE *file)
{
    return toupper(fgetc(file));
}

int CODIGO_LEXICO(char *token, int *countTableSymbol)
{
    //Percorre a tabela de símbolos em busca do átomo associado
    table p = symbolTable;
    while (p)
    {
        if (strcmp(p->pair.token, token) == 0)
        {
            return p->pair.identifier;
        }
        p = p->prox;
    }

    //Caso não tenha encontrado nada, verifica se é número ou palavra
    if (verificaSomenteNumero(token))
    {
        //Se for número
        (*countTableSymbol) = NUMERO;
    }
    else
    {
        //Se for palavra
        (*countTableSymbol) = TOKEN;
    }

    return (*countTableSymbol); //Retorna o identificador do elemento atual
}

void ERRO_LEXICO(lld line)
{
    printf("\nERRO DE COMPILACAO!\n\n");
    printf("ERRO LEXICO!\n");
    printf("Ocorreu um erro lexico na linha %lld do codigo-fonte!", line);
    printf("\n\n");
    printf("Pressione ENTER para sair...");
    getchar();
    exit(0);
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
/* Análise Sintática */
//-------------------------------------------------------------------------------

char *convertIDtoToken()
{
    switch (tokenSyntactical.identifier)
    {
    case PROGRAM:
        return "PROGRAM";
    case LABEL:
        return "LABEL";
    case VAR:
        return "VAR";
    case PROCEDURE:
        return "PROCEDURE";
    case FUNCTION:
        return "FUNCTION";
    case BEGIN:
        return "BEGIN";
    case END:
        return "END";
    case IF:
        return "IF";
    case THEN:
        return "THEN";
    case ELSE:
        return "ELSE";
    case WHILE:
        return "WHILE";
    case DO:
        return "DO";
    case OR:
        return "OR";
    case AND:
        return "AND";
    case DIV:
        return "DIV";
    case NOT:
        return "NOT";
    case PONTO_FINAL:
        return ".";
    case PONTO_VIRGULA:
        return ";";
    case VIRGULA:
        return ",";
    case ABRE_PARENTESIS:
        return "(";
    case FECHA_PARENTESIS:
        return ")";
    case ABRE_COLCHETES:
        return "[";
    case FECHA_COLCHETES:
        return "]";
    case DOIS_PONTOS:
        return ":";
    case IGUAL:
        return "=";
    case DIFERENTE:
        return "<>";
    case MAIOR_QUE:
        return ">";
    case MENOR_QUE:
        return "<";
    case MAIOR_IGUAL_QUE:
        return ">=";
    case MENOR_IGUAL_QUE:
        return "<=";
    case SOMA:
        return "+";
    case SUBTRAI:
        return "-";
    case MULTIPLICA:
        return "*";
    case DOISPONTOS_IGUAL:
        return ":=";
    case PONTO_PONTO:
        return "..";
    case ABRE_COMENTARIO:
        return "(*";
    case FECHA_COMENTARIO:
        return "*)";
    case READ:
        return "READ(variavel)";
    case WRITE:
        return "WRITE(variavel)";
    case INTEIRO:
        return "INTEGER";
    case BOOLEANO:
        return "BOOLEAN";
    default:
        return tokenSyntactical.token;
    }
}

void syntacticError()
{
    printf("\nERRO DE COMPILACAO!\n\n");
    printf("ERRO SINTATICO!\n\n");
    printf("Linha %lld\nErro: %s", tokenSyntactical.line, convertIDtoToken());
    printf("\n\n");
    printf("Pressione ENTER para sair...");
    getchar();
    exit(0);
}

void parser(int identifier)
{
    if (tokenSyntactical.identifier == identifier)
    {
        popFila();
    }
    else
    {
        syntacticError();
    }
}

void startSyntacticAnalyzer()
{
    popFila();

    switch (tokenSyntactical.identifier)
    {
    case PROGRAM:
        PROGRAMA();
        break;

    default:
        syntacticError();
    }
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
/* Funções de arquivo */
//-------------------------------------------------------------------------------

int abrirArquivo(FILE *(*file), char *filename, char *mode)
{
    return ((*file) = fopen(filename, mode));
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------