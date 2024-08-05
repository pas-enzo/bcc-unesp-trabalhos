#include <stdio.h>
#include <string.h>
#define MAX 1001

int main(){

	int x;
	unsigned i;
	unsigned n;
	char comandos[1001];
	
	while (scanf("%u", &n), n)
	{

		scanf("%s", comandos);

		x = 1;
		for (i = 0; i < n; ++i)
			if (comandos[i] == 'D')
			{

				++x;
				if (x > 4)
					x = 1;

			}
			else
			{
				--x;
				if (x == 0)
					x = 4;

			}

		if(x==1)printf("N\n");
		if(x==2)printf("L\n");
		if(x==3)printf("S\n");
		if(x==4)printf("O\n");

	}

}