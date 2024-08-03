#include <bits/stdc++.h>
#include <array>
#include <cmath>
#define ll long long int

using namespace std;

array<size_t, 21> cb;

ll dp[10001][21];

ll busca (size_t num, size_t pos = 0) 
{
    if (num == 0)
    {
        return 1;
    }

    if (pos == 21)
    {
        return 0;
    }

    if (dp[num][pos] != -1)
    {
        return dp[num][pos];
    }

    ll temp = busca(num, pos+1);

    if (cb[pos] <= num)
    {
        temp += busca(num-cb[pos], pos);
    }

    dp[num][pos] = temp;
    return temp;
}

int main () 
{
    for (size_t i = 0; i < cb.size(); ++i)
    {
        cb[i] = pow(cb.size()-i, 3);
    }
		
	for (auto &i:dp)
		for (auto &j:i)
			j = -1;
		
	size_t n;

	while (cin >> n)
		cout << busca(n) << endl;
		
	return 0;
}
