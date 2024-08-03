#include <system.h>
#include <stdio.h>
#include <conio.h>

/* estrutura para regiao critica */
typedef struct registros {
    unsigned bx1, es1;
} regis;

/* aponta para a regiao critica */
typedef union k {
    regis x;
    char far *y;
} APONTA_REG_CRIT;

APONTA_REG_CRIT a;
/* estrutura do descritor de processos */
typedef struct descritor_processos {
    char nome[35];
    enum { ativo, terminado } estado;
    PTR_DESC contexto;
    struct descritor_processos *prox_desc;
} DESCRITOR_PROC;

typedef DESCRITOR_PROC *PTR_DESC_PROC;

PTR_DESC_PROC prim;                                         /* primeiro processo dos prontos */
PTR_DESC desc;                                              /* indicador do descritor */
/* insere um novo processo na fila */
void far insereFila(PTR_DESC_PROC novo) {
    PTR_DESC_PROC prox, ant;
    prox = prim;
    ant = prim;
    if (prox == NULL) {
        prim = novo;
        prim->prox_desc = novo;
    } else {
        prox = prox->prox_desc;
        while (prox != prim) {
            ant = prox;
            prox = prox->prox_desc;
        }
        novo->prox_desc = prim;                             /* insere no final da fila */
        ant->prox_desc = novo;
    }
}

/* cria um novo processo */
void far criaProcesso(char nome_processo[35], void far (*final_processo)()) {
    PTR_DESC_PROC auxiliar;
    auxiliar = (DESCRITOR_PROC *)malloc(sizeof(DESCRITOR_PROC)); /* inicia campos do descritor */
    strcpy(auxiliar->nome, nome_processo);                       /* copia o nome */
    auxiliar->estado = ativo;                                    /* muda o estado para ativo */
    auxiliar->contexto = cria_desc();                            /* inicia o descritor de contexto */
    newprocess(final_processo, auxiliar->contexto);
    insereFila(auxiliar);                                        /* coloca no final da fila de processos */
}

/* procura o próximo processo ativo */
PTR_DESC_PROC far procuraProxAtivo() {
    PTR_DESC_PROC aux;
    if (prim == NULL) return NULL;                          /* retorna nulo */
    aux = prim->prox_desc;                                  /* percorre a lista dos descritores ativos */
    while (aux != prim && aux->estado != ativo)
        aux = aux->prox_desc;
    if (aux == prim) {
        if (aux->estado == ativo) return aux;
        else return NULL;                                   /* se nao achou retorna nulo */
    }
    return aux;
}

/* volta para o DOS */
void far voltaDOS() {
    disable();
    setvect(8, p_est->int_anterior);                        /* restaura a interrupcao original */
    enable();
    printf("\t\nFIM");  
    getch();
    exit(0);
}

/* escalador de processos */
void far escalador() {
    p_est->p_origem = desc;
    p_est->p_destino = prim->contexto;
    p_est->num_vetor = 8;                                   /* ponteiro ja na regiao critica do DOS */
    _AH = 0x34;                                             /* procedimento padrao de registradores */
    _AL = 0X00;
    geninterrupt(0x21);
    a.x.bx1 = _BX;
    a.x.es1 = _ES;
    while (1) {
        iotransfer();
        disable();
        if (!*a.y) {
            
            if ((prim = procuraProxAtivo()) == NULL)       /* se nao esta na regiao critica troca o processo */
                voltaDOS();
            p_est->p_destino = prim->contexto;
        }
        enable();
    }
}

/* dispara o sistema */
void far startSistema() {
    PTR_DESC daux;
    daux = cria_desc();
    desc = cria_desc();
    newprocess(escalador, desc);
    transfer(daux, desc);
}

/* termina o processo atual */
void far terminaProcesso() {
    disable();                                              /* desabilita interrupcoes */
    prim->estado = terminado;                               /* marca o processo como terminado */
    enable();                                               /* habilita interrupcoes */
    while (1);                                              /* loop eterno */
}

/* representacao de um processo X */
void far processoX() {
    int i = 0;
    while (i < 10000) {
        printf("x");
        i++;
    }
    terminaProcesso();
}

/* representacao de um processo Y */
void far processoY() {
    int i = 0;
    while (i < 10000) {
        printf("y");
        i++;
    }
    terminaProcesso();
}

/* funcao principal */
void main() {
    prim = NULL;
    criaProcesso("Processo X", processoX);                  /* cria processo X */
    criaProcesso("Processo Y", processoY);                  /* cria processo Y */
    startSistema();                                         /* dispara o sistema */
}

