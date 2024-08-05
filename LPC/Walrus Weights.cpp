#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main ()
{   

    vector<bool> ehPossivel;

    ehPossivel.resize(2200, false);
    ehPossivel[0] = true;

    int n;

    cin >> n;

    for (int i=0; i<n; i++)
    {
        int peso;
        cin >> peso;

        for (int j=ehPossivel.size()-peso-1; j>=0; j--)
        {
            if (ehPossivel[j])
            {
                ehPossivel[j+peso] = true;
            }
        }
    }

    int estaProximo = 0;

    for (int j=0; j<ehPossivel.size(); j++)
    {
        if (ehPossivel[j] && abs(1000-j) <= abs(1000-estaProximo)) estaProximo = j;
    }

    cout << estaProximo << endl;

    return 0;
}