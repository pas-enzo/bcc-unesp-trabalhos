#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long int n;
	int i, maior, cont;
	string dna;
	char ante;
	
	cin >> dna;
	
	for (i=0 ; dna[i] != '\0' ; i++) //se for a primeira repeticao, ante recebe o caractere
	{
		if (i == 0)
		{
			ante = dna[i]; 
			cont++;
			maior = cont;
		} 
		
		else
		{
			if (dna[i] == ante) 
			{
				cont++;
				if (cont > maior) maior = cont;
			}
			
			else
			{
				cont = 0;
				ante = dna[i];
				cont++;
				
			}
		}
		
	}
	
	cout << maior << endl;
}
