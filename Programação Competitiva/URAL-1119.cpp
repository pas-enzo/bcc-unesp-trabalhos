#include <bits/stdc++.h>
#define INF 1e9+7
#define xs sqrt(2.0)*100.0

using namespace std;

const int maxn = 1e3+7;
double dp[maxn][maxn];
bool vis[maxn][maxn];
int n, m, k;

int main() {

    while (~scanf("%d %d", &n, &m))
    {
        memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));

        for (int i=0; i<=n; i++)
            for (int j=0; j<=m; j++)
            dp[i][j] = INF;

        scanf("%d", &k);

        for (int i=0; i<k; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            vis[x][y] = true;
        }

        dp[0][0] = 0;

        for (int i=0; i<=n; i++)
            for (int j=0; j<=m; j++) {
                
                if (i==0 && j==0) continue;

                if (i==0) dp[i][j] = dp[i][j-1] + 100.0;

                if (j==0) dp[i][j] = dp[i-1][j] + 100.0;

                if (i==0 || j==0) continue;

                if (vis[i][j]) {
                    dp[i][j] = min(dp[i][j-1] + 100.0, min(dp[i-1][j] + 100.0, dp[i-1][j-1] + xs));
                }

                else dp[i][j] = min(dp[i][j-1] + 100.0, dp[i-1][j] + 100.0);
            }
        printf("%0.0lf\n", dp[n][m]);
    }
    return 0;
}
