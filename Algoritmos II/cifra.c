#include <stdio.h>
#include <conio.h>

void main(){

    FILE *arquivo;
    char linha[100];
    char *resu;
    int i=1;
    
    arquivo=fopen("ajudacrp.txt", "rt");
        

    while(!feof(arquivo)){

        resu = fgets(linha, 100, arquivo);

        if(resu)
            printf("%s", linha);

    }
    
    fclose(arquivo);

}
