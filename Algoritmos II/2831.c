#include <stdio.h>
#define FALSE 0
#define TRUE 1

int main(){
	
	int caixas[10005];
	int quant_ca, i;
	int possivel = TRUE;
	
	scanf("%d", &quant_ca);

	for (i=1;i<=quant_ca;++i)
		scanf("%d", &caixas[i]);

	for (i=1;i<=quant_ca && possivel == TRUE;++i)
		if(caixas[i]-caixas[i-1]>8)
			possivel = FALSE;

	if (!possivel)
		printf("N\n");
	else
		printf("S\n");
	
	return 0;
}