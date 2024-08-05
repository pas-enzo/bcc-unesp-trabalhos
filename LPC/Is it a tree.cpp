#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool dfs (int noAtual, int pai, vector<bool> &visitou, vector<vector<ll>> &lstad)
{
    if (visitou[noAtual] == true)
    {
        return false;
    }

    visitou[noAtual] = true;

    for(auto filho: lstad[noAtual])
    {
        if (filho != pai) 
        {
            bool resultado = dfs(filho, noAtual, visitou, lstad);
            if (resultado == false) 
            {
                return false;
            }
        }
    }

    return true;

}

bool vArvore (vector<vector<ll>> &lstad, ll n)
{
    vector<bool> visitou(n+1);
    if (dfs(1, -1, visitou, lstad) == false) 
    {
        return false;
    }

    for (int i=1; i<=n; i++)
    {
         if (visitou[i] == false) 
         {
            return false;
         }
    }
    return true;
}

int main() 
{
    ios_base::sync_with_stdio(false);

    ll n, m, u, v;

    cin >> n >> m;
    vector<vector<ll>> lstad(n+1); 

    for (int i=0; i<m; i++) 
    {
        cin >> u >> v;
        lstad[u].push_back(v);
        lstad[v].push_back(u);
    }

    if (vArvore(lstad, n)) 
    {
        cout << "YES" << endl;
    }

    else cout  << "NO" << endl;

    return 0;
}

