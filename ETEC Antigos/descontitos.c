#include <stdio.h>

int main(){
	
	int modo;
	float preco;
	
	printf("Por obsequio defina seu modo de pagamento: \n");
	scanf("%d", &modo);
	
	printf("Insira o preco do produto escolhido: \n");
	scanf("%f", &preco);
	
	switch(modo){
		case 1:
			printf("Preco = R$ %.2f\n", preco*0.9);
			break;
			
		case 2:
			printf("Preco = R$ %.2f\n", preco*0.95);
			break;
			
		case 3:
			printf("Preco = R$ %.2f\n", preco);
			break;
			
		case 4:
			printf("Preco = R$ %.2f\n", preco*1.1);
			break;
			
		default: 
			printf("Escolha um modo de pagamento valido!!!!\n");
			

	}
	
	
	return 0;
}
