#include <bits/stdc++.h>

using namespace std;

int main ()
{
	long long int n;
	int i, atu;
	//int vetor [TAM];
	
	cin >> n;
	
	if (n == 2 || n == 3) cout << "NO SOLUTION" << endl;
	
	else
	{
		atu = 2;
		
		for (i=0; i<n/2 ; i++)
		{
			cout << atu << " ";
			atu += 2;
		}
		
		atu = 0;
		
		if (n%2 != 0) 
		{
			atu = 1;
			
			for (i=0 ; i<n/2+1 ; i++)
			{
				cout << atu << " ";
				atu += 2;
			}
		}
		
		else 
		{
			atu = 1;
			
			for (i=0 ; i<n/2 ; i++)
			{
				cout << atu << " ";
				atu +=2;
			}
		}		
	}
}