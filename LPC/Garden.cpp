#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int main () 
{
	int  n, k, vet[MAX];
	int i, j;
	int menor, cont = 0;
	
	cin >> n >> k;
	menor = k;
	
	for (i=0;i<n;i++) 
	{
		cin >> vet[i];
	}
	
	for (i=0;i<n;i++)
	{	
		cont = 0;
		j = 0;
		
		do
		{
			j += vet[i];
			cont++;
		} while (j < k);
		
		if (j==k && cont < menor) menor = cont;
		
	}
	
	cout << menor << endl;
	
	return 0;
}