#include <bits/stdc++.h>

using namespace std;

int main ()
{
    string str1, str2, str3, comparador;

    cin >> str1 >> str2 >> str3;

    comparador = str1 + str2;

    sort (str3.begin(), str3.end());
    sort (comparador.begin(), comparador.end());

    if (str3 == comparador) cout << "YES" << endl;

    else cout << "NO" << endl;

    return 0;

}
