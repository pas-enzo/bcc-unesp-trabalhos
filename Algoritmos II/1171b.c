#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    int v[2001] = {0}, i, ent, quant;
    scanf("%d",&quant);

    for( ;quant>0;quant--){
        scanf("%d", &ent);
        v[ent]++;
        }
        
    for(i=0;i<2001;i++){
        if(v[i]>0){
            printf("%d aparece %d vez(es)\n", i, v[i]);
            }
        }

    return 0;
}