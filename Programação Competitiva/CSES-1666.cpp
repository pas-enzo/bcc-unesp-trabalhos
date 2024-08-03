#include <bits/stdc++.h>
using namespace std;
 
class Resolve 
{
    public:

    vector<int> visitou;

    string res (int n, vector<vector<int>> &adj) 
    {
        visitou = vector<int>(n+1);

        vector<int> nosQueSeraoConectados;

        dfs(1, adj);

        for (int i=2; i<=n; i++) 
        {
            if (!visitou[i]) 
            {
                nosQueSeraoConectados.push_back(i);
                dfs(i, adj);
            }
        }
        
        string resu = to_string(nosQueSeraoConectados.size()) + "\n";

        for (auto no: nosQueSeraoConectados)
            resu += ("1 " + to_string(no) + "\n");
        return resu;
    }

    void dfs (int no, vector<vector<int>> &adj) 
    {
        if (visitou[no]) return;
        
        visitou[no] = 1;
        
        for (auto child: adj[no])
            dfs(child, adj);
    }
};
 
int main() {
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1); // adjacency list
    
    for (int i=0; i<m; i++) 
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    
    Resolve resolvedor;
    cout << resolvedor.res(n, adj);
 
    return 0;
}
