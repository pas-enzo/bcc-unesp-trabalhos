#include <bits/stdc++.h>

using namespace std;

int main ()
{
	char *fila[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	int entrada;
	long long int cont, soma, saida;
	
	cin >> entrada;
	
	for (soma=0,cont=1;entrada>soma;cont<<=1)
	{
		for (saida=0;saida<5 && entrada>soma;saida++,soma+=cont);	
	}	
	
	cout << fila[saida-1] << endl;
	
	return 0;
}