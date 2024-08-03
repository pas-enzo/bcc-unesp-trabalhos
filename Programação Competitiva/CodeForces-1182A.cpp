#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main ()
{   
    ll n;

    cin >> n;

    if (n%2 != 0) cout << 0 << endl;

    else 
    {
        ll saida = pow(2, n/2);
        cout << saida << endl;
    }

    return 0;
}
