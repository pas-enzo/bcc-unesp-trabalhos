#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
#define MOD 1000000007

int dp[MAX], n;

int dice (int num)
{
    if (dp[num] != 0) 
	{
		return dp[num];
	}
    
    for (int i=1; i<=6; i++)
    {
        if (num - i >= 0)
        {
            dp[num] += dice(num - i);
            dp[num] %= MOD;
        }
    }
    
    return dp[num];
}

int main ()
{
    cin >> n;
    
    memset(dp, 0, sizeof(dp));
    
    dp[0] = 1;

    cout << dice(n) << endl;

    return 0;

}