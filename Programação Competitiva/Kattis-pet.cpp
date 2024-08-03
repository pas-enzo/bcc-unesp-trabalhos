#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int k = 0;
	int vet_pontos[6];
	int pontos, temp_total = 0;
	int big_pos, big_pon;
	
   	while (k<5)
   	{
   		for (int i=0; i<4; i++)
		{
			cin >> pontos;
			temp_total += pontos;
		}	
		
		vet_pontos[k] = temp_total;
		temp_total = 0;
		k++;
	}
	
	for (int j=0; j<5; j++)
	{
		if (j == 0)
		{
			big_pos = j+1;
			big_pon = vet_pontos[j];
		}
		
		else if (vet_pontos[j] > big_pon)
		{
			big_pos = j+1;
			big_pon = vet_pontos[j];
		}
	}
	
	cout << big_pos << " " << big_pon << endl;

    return 0;
}
