#include<stdio.h>

int main(){
 
 int dia,diaatual,mes,mesatual,ano,anoatual,totaldias,i;

printf("Digite o dia que você nasceu:\n");
scanf("%d",&dia);
printf("Digite o mes que você nasceu:\n");
scanf("%d",&mes);
printf("Digite o ano que você nasceu:\n");
scanf("%d",&ano);
printf("Digite o dia (data de hoje):\n");
scanf("%d",&diaatual);
printf("Digite o mês (data de hoje):\n");
scanf("%d",&mesatual);
printf("Digite o ano (data de hoje):\n");
scanf("%d",&anoatual);

    for(int i = ano; i < anoatual; i++){ 

        //para ver se o ano eh bissexto
        if(i % 4 == 0){
            totaldias += 366;
        } else {
            totaldias += 365;
        }
    }

    printf("Dias: %d",totaldias);

    return 0;
}
