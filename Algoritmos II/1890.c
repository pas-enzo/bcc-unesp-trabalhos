#include <stdio.h>

int main(){

    int t, c, d, i;
    int j, k, total=1;

    scanf("%d", &t);

    for(i=0;i<t;i++){

        scanf("%d %d", &c, &d);

        for(j=0;j<c;j++){
            total*=26;
        }

        for(k=0;k<d;k++){
            total*=10;
        }

		if(c==0 && d==0)printf("0\n");
		
		else printf("%d\n", total);
        
        total=1;

    }

}