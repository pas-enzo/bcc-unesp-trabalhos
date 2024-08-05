#include <stdio.h>
#include <stdbool.h>

bool verificaOrd(short vet[], short cmp[], unsigned short tam);

int main ()
{

	unsigned short numero, i;
	unsigned short qtsOrd;
	bool resultado;

	while (true)
	{	
		scanf("%hu", &numero);

		if (numero == 0)
			break;

		short caixa[numero];
		short cmp[numero];

		
		for (i = 0; i < numero; i++)
			cmp[i] = i+1;

		
		qtsOrd = 1;
		do
		{
			
			for (i = 0; i < numero; i++)
				scanf("%hu", &caixa[i]);

			
			resultado = verificaOrd(caixa, cmp, numero);

			
			if (!resultado)
				qtsOrd++;

		} while (!resultado);
		
		printf("%hu\n", qtsOrd);			

	}


}

bool verificaOrd(short vet[], short cmp[], unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		if (vet[i] != cmp[i])
			return false;

	return true;

}