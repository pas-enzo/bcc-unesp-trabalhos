#include <bits/stdc++.h>

using namespace std;

int main ()
{
	long long int n, i, temp, k;
	char c1, c2;
	string str = {"v<^>"};
	
	cin >> c1 >> c2;
	cin >> n;
	
	//se o numero for par, nao sera possivel determinar a rotacao do brinquedo
	//se for impar, verificar se sera horario ou anti-horario
	
	if (n%2==0) cout << "undefined" << endl;
	
	else
	{
		char cw, ccw;
		
		n = n%4;
		
		for (i=0;i<4;i++)
		{
			if (str[i] == c1)
			{
				temp = i;
				break;	
			}	
		}	
		
		i = temp;
		k = n;
		while (k--)
		{
			i++;
			i = i%4;
		}
		
	    cw = str[i];
		
		i = temp;
		k = n;
		while (k--)
		{
			i--;
			
			if (i<0) i = 3;
		}
		
		ccw = str[i];
    	
		if (cw == c2) cout << "cw";
    
		else if(ccw == c2) cout << "ccw";
    
		else cout<<"undefined";
	}
	
	return 0;	
}