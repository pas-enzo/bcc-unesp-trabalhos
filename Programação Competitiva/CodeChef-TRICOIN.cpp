#include <bits/stdc++.h>

using namespace std;

int retorna_altura (int n, int camada)
{
	n -= camada;
	
	camada++;
	
	if (n == 0) return 1;
	
	else if (n > 0 && n < camada) return 1;
	
	else return 1 + retorna_altura(n, camada);
}

int main () 
{
	int t, n, cont=0;
	
	cin >> t;
	
	while (cont<t)
	{
		cin >> n;
		
		cout << retorna_altura(n, 1) << endl;
		
		cont++;
	}
	
	return 0;
}
