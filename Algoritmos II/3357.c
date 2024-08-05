#include <stdio.h>
#define MAX 10

int main () {

    int pessoas, i, j;
    float termica, cuia;
    float rep, sobrado;
    char nomes[MAX][27];

    scanf("%d %f %f", &pessoas, &termica, &cuia);
    
    for(i = 0; i<pessoas ; i++) {
    	
		scanf("%s", &nomes[i]);
		
	}

    rep = termica / cuia;
    sobrado = termica / cuia;

    for (i=0 ; i<=(int)rep ; i++){

        j++;
        if (j > pessoas) j=0;

    }

    printf("%s %.1f\n", nomes[j], sobrado);

    return 0;
}