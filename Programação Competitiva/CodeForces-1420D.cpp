#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 998244353;
ll fact[300001];

ll fexp(ll a, ll b){
    ll ans = 1;
    for(int i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

ll nCr(int N, int K){
    return fact[N] * fexp(fact[K] * fact[N-K] % MOD, MOD-2) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K; cin >> N >> K;
    fact[0] = 1;
    for(int i = 1; i <= 300000; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    vector<pair<int, int>> ops;
    for(int i = 0; i < N; i++){
        int l, r; cin >> l >> r;
        ops.push_back(make_pair(l, 1));
        ops.push_back(make_pair(r+1, -1));
    }
    sort(ops.begin(), ops.end());
    ll active = 0;
    ll ans = 0;
    for(int i = 0; i < (int)ops.size(); i++){
        if(ops[i].second == 1 && active >= K-1){
            ans += nCr(active, K-1);
            ans %= MOD;
        }
        active += ops[i].second;
    }
    cout << ans << endl;
    return 0;
}
