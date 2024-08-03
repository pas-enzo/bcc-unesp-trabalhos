#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float double
#define pb push_back
#define ff first
#define ss second
#define rep(i,n) for(int i=0;i<n;i++)
 
int n, m;
vector<pair<int, int>> v[100001];
int vis[100001];
int d[100001];
 
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
    
    int t = 1;

    while(t--) {

        cin >> n >> m;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        rep(i, m){
            int x, y, z;cin>>x>>y>>z;
            v[x].pb({y, z});
        }

        q.push({0, 1});

        rep(i, 100001)d[i]=1000000000LL * m + 1LL;
        rep(i, 100001)vis[i]=0;
        d[1]=0;

        while(!q.empty()) {

            auto a=q.top();
            q.pop();
            int c=a.ss, dis=a.ff;
            if(vis[c]) continue;
            
            vis[c]=1;
            
            for(auto i: v[c]){
                if(d[c]+i.ss<d[i.ff]){
                    d[i.ff]=d[c]+i.ss;
                    q.push({d[i.ff], i.ff});
                }
            }
        }
        
        rep(i, n)cout<<d[i+1]<<" ";
    }
    return 0;
}
