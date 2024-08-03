//B - Panoramix´s Prediction - recursividade
#include <bits/stdc++.h>
#define FALSE 0
#define TRUE 1

using namespace std;

int coe_primo (int var, int low)
{

    if (var % low == 0 && (low != var && low != 1))
    {
        return 0;
    }

        else if (var % low == 0 && low == 1)
        {
           return 1; 
        }

            else
            {
                return coe_primo(var, low - 1);
            }
}

int passa (int a, int b)
{	
	int next = a;
	int verif = 0;
	
    while (next <=b && !verif)
    {	
		next++;
    
    	if (next != b && coe_primo(next,next))
    	{
    		break;
		}
		
		else if (next == b && coe_primo(next,next))
		{
			verif = 1;
		}
			
	}
	
	if(verif) return 1;
	
	else return 0;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, test = 0; 

    cin >> x >> y;

    test = passa(x,y);

    if (test) cout << "YES" << endl;

    else cout << "NO" << endl;

    return 0;
}
