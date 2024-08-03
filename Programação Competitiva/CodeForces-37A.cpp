#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

int main () 
{
    int i;
    int n, bars[MAX];
    int alt = 1, cont = 1, h = 1;
	
	cin >> n;
	
	for (i=0; i<n; i++)
	{
		cin >> bars[i];
	}
	
	sort(bars, bars + n);
	
	for (i=1; i<n; i++)
	{
		if (bars[i] == bars[i-1])
		{	//se os valores forem iguais, incrementa h
			h++;
			
			if (h > alt)//se h for maior que altura, troca valor da altura para h
			{
				alt = h;
			}
		}
		
		else
		{	
			//se encontrar valor diferente, volta o h para 1
			h = 1;
			++cont;//cont quantidade de torres
		}
	}
	
	cout << alt << " " << cont << endl;
	
	return 0;
}
