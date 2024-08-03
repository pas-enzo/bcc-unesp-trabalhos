#include <bits/stdc++.h>
#define si(n) scanf("%d",&n)

using namespace std;

set<int> g[105];
int nc=0,vs[105],cnt=0;

void dfs(int u){
	vs[u]=1;

	cnt++;

	for(auto i=g[u].begin(); i!=g[u].end(); i++)
    {
		int w = *i;
		
        if(!vs[w]){
			g[w].erase(u);
			dfs(w);
		}
		else{
			nc++;
		}
	}
    
}

int main(){
	int n, m, a, b;

	si(n);
    si(m);

	for(int i=0;i<m;i++){
		si(a);si(b);
		g[a].insert(b);
		g[b].insert(a);
	}

	dfs(1);

	if(nc==2 && cnt==n)
		cout << "FHTAGN!" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
