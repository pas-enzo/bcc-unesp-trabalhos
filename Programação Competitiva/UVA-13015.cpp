#include <bits/stdc++.h>

using namespace std;

const int MAX = 5005;
int A, B, E, P;
vector<int> G[MAX], invG[MAX];
int usou[MAX] = {};
int  casos = 0;

int dfs (int u, vector<int> g[]);

int main () 
{
    int x, y;

    while (scanf("%d %d %d %d", &A, &B, &E, &P) == 4)
    {
        for (int i = 0; i < E; i++)
        {
			G[i].clear();
            invG[i].clear();
        }

		for (int i = 0; i < P; i++) 
        {
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
            invG[y].push_back(x);
		}
		
		int retA = 0, retB = 0, retN = 0;

		for (int i = 0; i < E; i++) 
        {
			int pior, melhor;
			casos++;
			pior = E - dfs(i, G) + 1;
			casos++;
			melhor = dfs(i, invG);
			if (pior <= A)	retA++;
			if (pior <= B)	retB++;
			if (melhor > B)	retN++;
		}

		printf("%d\n%d\n%d\n", retA, retB, retN);
    }

    return 0;

}

int dfs(int u, vector<int> g[]) {
	
    if (usou[u] == casos)	
        return 0;

	usou[u] = casos;

	int ret = 1;

	for (auto v : g[u])
		ret += dfs(v, g);
        
	return ret;
}
