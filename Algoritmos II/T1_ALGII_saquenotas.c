#include <stdio.h>

int main(){
	
	float quant=0, moedas=0; //quantidade sacada
	int cent=0, fift=0, twen=0; //contadores 
	int ten=0, five=0, two=0, one=0, sobra=0; //contadores
	int cfif=0, ctwf=0, cten=0, cfiv=0, ccen=0; //contadores
	
	/*verificacao da quantidade*/
	do{
		printf("\nDigite a quantidade a ser sacada: \n");
		scanf("%f", &quant);
		
		if(quant<=0 || quant>999999999)
			printf("\nQuantidade invalida.\n");
		
	}while(quant<=0 || quant>999999999);

	
	/*quantidade em moedas*/
	moedas=(int)((quant-(int)quant)*100);

	/*operacao do calculo de notas e moedas de 1*/
	
		/*parte inteira*/
		cent=(int)quant/100;
		sobra=(int)quant%100;
	
		fift=sobra/50;
		sobra=sobra%50;
		
		twen=sobra/20;
		sobra=sobra%20;
	
		ten=sobra/10;
		sobra=sobra%10;
	
		five=sobra/5;
		sobra=sobra%5;
		
		two=sobra/2;
		sobra=sobra%2;
		
		one=sobra;
		
		sobra=0;
		
		/*parte decimal*/
		cfif=(int)moedas/50;
		sobra=(int)moedas%50;
		
		ctwf=sobra/25;
		sobra=sobra%25;
		
		cten=sobra/10;
		sobra=sobra%10;
		
		cfiv=sobra/5;
		sobra=sobra%5;
		
		ccen=sobra;
		
		
	/*print dos resultados*/
	
	printf("\nVoce sacara: \n");
	
	if(cent!=0)
		printf("%d nota(s) de B$100.00.\n", cent);
		
	if(fift!=0)
		printf("%d nota(s) de B$50.00.\n", fift);
		
	if(twen!=0)
		printf("%d nota(s) de B$20.00.\n", twen);
		
	if(ten!=0)
		printf("%d nota(s) de B$10.00.\n", ten);
		
	if(five!=0)
		printf("%d nota(s) de B$5.00.\n", five);
		
	if(two!=0)
		printf("%d nota(s) de B$2.00.\n", two);
		
	if(one!=0)
		printf("%d moeda(s) de B$1.00.\n", one);
		
	if(cfif!=0)
		printf("%d moeda(s) de B$0.50.\n", cfif);
		
	if(ctwf!=0)
		printf("%d moeda(s) de B$0.25.\n", ctwf);
		
	if(cten!=0)
		printf("%d moeda(s) de B$0.10.\n", cten);
		
	if(cfiv!=0)
		printf("%d moeda(s) de B$0.05.\n", cfiv);
		
	if(ccen!=0)
		printf("%d moeda(s) de B$0.01.\n", ccen);
	
	
	return 0;
}