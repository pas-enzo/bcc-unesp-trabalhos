#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout << '\n';
#define E cerr << '\n';
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rev(i, a, b) for (int i = a; i > b; --i)
#define IOS                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                      \
    cout.tie(0);
#define int long long
#define seea(a, x, y) for (int i = x; i < y; i++) { cin >> a[i]; }
#define seev(v, n) for (int i = 0; i < n; i++) { int x; cin >> x; v.push_back(x); }
#define sees(s, n) for (int i = 0; i < n; i++) { int x; cin >> x; s.insert(x); }
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int fac[2000001];
int inv[2000001];

int exp(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << (fac[a + b - 1] * inv[a - 1] % md * inv[b] % md) << " ";
}

signed main()
{
    //IOS;
//#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif
    int t = 1;
    fac[0] = 1, inv[0] = 1;
    rep(i, 1, 2000001)
    {
        fac[i] = fac[i - 1] * i % md;
        inv[i] = exp(fac[i], md - 2, md);
    }
    // cin>>t;
    while (t--)
    {
        solve();
        // cout<<'\n';
    }
#ifdef LOCAL
    clock_t tStart = clock();
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
