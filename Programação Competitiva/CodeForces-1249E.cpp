#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 200005;
const int INF = 1<<30;

int a[MAX], b[MAX];

int main() 
{
    int n, c;
    cin >> n >> c;

    for (int i=0; i<n-1; i++) cin >> a[i];
    for (int i=0; i<n-1; i++) cin >> b[i];

    vector<vector<int>>  dp(n, vector<int>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = c;

    for (int i=0; i<n-1; i++)
    {
        dp[i+1][0] = min(dp[i+1][0], dp[i][1]+a[i]);
        dp[i+1][0] = min(dp[i+1][0], dp[i][0]+a[i]);
        dp[i+1][1] = min(dp[i+1][1], dp[i][1]+b[i]);
        dp[i+1][1] = min(dp[i+1][1], dp[i][0]+b[i]+c);
    }

    for (int i=0; i<n; i++) cout << min(dp[i][0], dp[i][1]) << (i==n-1 ? '\n' : ' ');

    return 0;
}
