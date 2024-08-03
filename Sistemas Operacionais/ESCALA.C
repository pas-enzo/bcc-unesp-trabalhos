#include <system.h>
#include <stdio.h>

PTR_DESC dmain, desc, dX, dY;                               /* descritores de contexto */

/* função escalador */
void far escalador() {
    p_est->p_origem = desc;
    p_est->p_destino = dX;
    p_est->num_vetor = 8;

    while(1) {
        iotransfer();                                       /* transfere contexto */
        disable();
        if (p_est->p_destino == dX)
            p_est->p_destino = dY;                          /* alterna entre corotinas */
        else
            p_est->p_destino = dX;
        enable();
    }
}
/* função corotina X */
void far CorotinaX() {
    while(1) {
        printf("corotinaX ");
    }
}
/* função corotina Y */
void far CorotinaY() {
    while(1) {
        printf("corotinaY ");
    }
}
/* função principal */
main() {
    dX = cria_desc();                                       /* cria descritor para corotina X */
    dY = cria_desc();                                       /* cria descritor para corotina Y */
    desc = cria_desc();                                     /* cria descritor para escalador */
    dmain = cria_desc();                                    /* cria descritor para main */
    newprocess(CorotinaX, dX);                              /* cria processo para corotina X */
    newprocess(CorotinaY, dY);                              /* cria processo para corotina Y */
    newprocess(escalador, desc);                            /* cria processo para escalador */
    transfer(dmain, desc);                                  /* transfere controle para o escalador */
}
