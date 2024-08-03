#include <system.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

/* estrutura região crítica */
typedef struct registros {
    unsigned bx1, es1;
} regis;

/* aponta para a região crítica */
typedef union k {
    regis x;
    char far *y;
} APONTA_REG_CRIT;

APONTA_REG_CRIT a;

/* estrutura descritor */
typedef struct descritor_processos {
    char nome[35];
    enum { ativo, bloq_P, terminado } estado;
    PTR_DESC contexto;
    struct descritor_processos *fila_sem;                   /* processos bloqueados pelo semáforo */
    struct descritor_processos *prox_desc;
} DESCRITOR_PROC;

typedef DESCRITOR_PROC *PTR_DESC_PROC;

/* estrutura semáforo */
typedef struct {
    int s;
    PTR_DESC_PROC Q;
} semaforo;

/* instruções iniciais dos semáforo */
void far startSemaforo(semaforo *sem, int n) {
    sem->s = n;
    sem->Q = NULL;
}
PTR_DESC_PROC prim = NULL;                                  /* primeiro processo dos prontos */
PTR_DESC d_esc;                                             /* indicador do descritor */

/* remove processo do semáforo */
void far removeSemaforo(semaforo *sem) {
    PTR_DESC_PROC p_aux;
    p_aux = sem->Q;
    p_aux->estado = ativo;
    sem->Q = p_aux->fila_sem;                               /* remove da fila do semáforo */
}

/* insere processo no semáforo */
void far insereSemaforo(semaforo *sem) {
    PTR_DESC_PROC p_aux;
    p_aux = sem->Q;
    if (p_aux == NULL) {
        sem->Q = prim;
    } else {
        while (p_aux->fila_sem != NULL) {
            p_aux = p_aux->fila_sem;
        }
        p_aux->fila_sem = prim;                             /* insere no final da fila */
        prim->fila_sem = NULL;
    }
}
/* procura o próximo processo ativo */
PTR_DESC_PROC far procuraProxAtivo() {
    PTR_DESC_PROC aux;
    if (prim == NULL) return NULL;                          /* retorna nulo se não houver processos */
    aux = prim->prox_desc;                                  /* percorre a lista dos descritores ativos */
    while (aux != prim && aux->estado != ativo) {
        aux = aux->prox_desc;
    }
    if (aux == prim) {
        if (aux->estado == ativo) return aux;
        else return NULL;                                   /* se não achou retorna nulo */
    }
    return aux;
}

/* volta para o DOS */
void far voltaDOS() {
    disable();
    setvect(8, p_est->int_anterior);                        /* restaura a interrupção original */
    enable();
    printf("\t\nFIM");
    getch();
    exit(0);
}

/* P (wait) de espera do semáforo */
void far P(semaforo *sem) {
    PTR_DESC_PROC p_aux;
    disable();

    if (sem->s > 0) {
        sem->s--;
    } else {
        insereSemaforo(sem);                                /* bloqueia processo e insere na fila do semáforo */
        prim->estado = bloq_P;
        p_aux = prim;
        if ((prim = procuraProxAtivo()) == NULL) {
            voltaDOS();
        }
        transfer(p_aux->contexto, prim->contexto);          /* transfere o contexto */
    }
    enable();
}

/* V (signal) de largada do semáforo */
void far V(semaforo *sem) {
    disable();
    if (sem->Q == NULL) {
        sem->s++;
    } else {
        removeSemaforo(sem);                                /* remove processo da fila do semáforo */
    }
    enable();
}

/* inicializa a fila de prontos */
void far startProntos() {
    prim = NULL;
}

/* insere um novo processo na fila de prontos */
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
    PTR_DESC_PROC auxiliar;                                 /* inicia campos do descritor */
    auxiliar = (DESCRITOR_PROC *)malloc(sizeof(DESCRITOR_PROC)); 
    strcpy(auxiliar->nome, nome_processo);                  /* copia o nome do processo */
    auxiliar->estado = ativo;                               /* define o estado como ativo */
    auxiliar->contexto = cria_desc();                       /* inicia o descritor de contexto */
    newprocess(final_processo, auxiliar->contexto);         /* cria um novo processo */
    insereFila(auxiliar);                                   /* coloca no final da fila de processos */
}

/* escalador de processos */
void far escalador() {
    p_est->p_origem = d_esc;
    p_est->p_destino = prim->contexto;
    p_est->num_vetor = 8;                                   /* ponteiro já na região crítica do DOS */
    _AH = 0x34;                                             /* procedimento padrão de registradores */
    _AL = 0X00;
    geninterrupt(0x21);
    a.x.bx1 = _BX;
    a.x.es1 = _ES;
    while (1) {
        iotransfer();
        disable();
        if (!*a.y) {
            if ((prim = procuraProxAtivo()) == NULL) {      /* se não está na região crítica troca o processo */
                voltaDOS();
            }
            p_est->p_destino = prim->contexto;
        }
        enable();
    }
}

/* dispara o sistema */
void far startSistema() {
    PTR_DESC d_aux;
    d_aux = cria_desc();
    d_esc = cria_desc();
    newprocess(escalador, d_esc);                           /* cria o processo escalador */
    transfer(d_aux, d_esc);                                 /* transfere o contexto para o escalador */
}

/* termina o processo atual */
void far terminaProcesso() {
    disable();                                              /* desabilita interrupções */
    prim->estado = terminado;                               /* marca o processo como terminado */
    enable();                                               /* habilita interrupções */
    while (1);                                              /* loop eterno */
}

/* buffer circular */
#define N 10
int buffer[N];
int in = 0;
int out = 0;

/* semáforos */
semaforo mutex;
semaforo empty;
semaforo full;

/* funções produtor e consumidor */
int produto = 0;
void far produtor() {
    int item;
    while (1) {
        item = rand() % 100;                                /* produz um item */
        P(&empty);                                          /* decrementa empty */
        P(&mutex);                                          /* entra na seção crítica */
        buffer[in] = item;                                  /* coloca o item no buffer */
        in = (in + 1) % N;
        V(&mutex);                                          /* sai da seção crítica */
        V(&full);                                           /* incrementa full */
        printf("Produziu: %d\t qtd: %d \n", item, produto); /* imprime item produzido */
        produto++;
    }
}

int consumo = 0;
void far consumidor() {
    int item;
    while (1) {
        P(&full);                                           /* decrementa full */
        P(&mutex);                                          /* entra na seção crítica */
        item = buffer[out];                                 /* retira o item do buffer */
        out = (out + 1) % N;
        V(&mutex);                                          /* sai da seção crítica */
        V(&empty);                                          /* incrementa empty */
        printf("Consumiu: %d\t qtd: %d \n", item, consumo); /* imprime item consumido */
        consumo++;
    }
}

/* função principal */
void main() {
    startProntos();                                         /* inicializa a fila de prontos */
    startSemaforo(&mutex, 1);                               /* inicia semáforo mutex */
    startSemaforo(&empty, N);                               /* inicia semáforo empty */
    startSemaforo(&full, 0);                                /* inicia semáforo full */
    criaProcesso("Produtor", produtor);                     /* cria processo produtor */
    criaProcesso("Consumidor", consumidor);                 /* cria processo consumidor */
    startSistema();                                         /* dispara o sistema */
}
