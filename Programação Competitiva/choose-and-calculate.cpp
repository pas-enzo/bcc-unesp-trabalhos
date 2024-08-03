#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100005
#define MOD 1000000007

int N, K, arr[MAXN];
long long factorial[MAXN], inv_factorial[MAXN];

int modularPower(long long a, int b) {
    long long result = 1;
    
    while (b) {
        if (b & 1)
            result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return result;
}

long long combination(int n, int m) {
    return factorial[n] * inv_factorial[m] % MOD * inv_factorial[n - m] % MOD;
}

int main() {
    scanf("%d %d", &N, &K);
    
    if (K == 1) {
        printf("0\n");
        return 0;
    }
    
    for (int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);
    
    factorial[0] = inv_factorial[0] = 1;
    
    for (int i = 1; i <= N; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inv_factorial[i] = modularPower(factorial[i], MOD - 2);
    }
    
    int ans = 0;
    
    for (int i = 0; i < N;) {
        int end = i;
        
        while (end < N && arr[end] == arr[i])
            ++end;
        
        if (end >= K)
            ans = (ans + (combination(end, K) - combination(i, K)) * arr[i]) % MOD;
        
        i = end;
    }
    
    for (int i = N - 1; i >= 0;) {
        int end = i;
        
        while (end >= 0 && arr[end] == arr[i])
            --end;
        
        if (N - 1 - end >= K)
            ans = (ans - (combination(N - 1 - end, K) - combination(N - 1 - i, K)) * arr[i]) % MOD;
        
        i = end;
    }
    
    if (ans < 0)
        ans += MOD;
    printf("%d\n", ans);
    
    return 0;
}
