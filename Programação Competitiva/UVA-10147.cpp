#include <bits/stdc++.h>

using namespace std;

int P[755], R[755];

struct dados {
    int x, y, v;
};

dados D[755*755];

bool compara (dados a, dados b);

void init (int n);

int findp (int x);

int uniao (int x, int y);

int main() {

    int t, n, m, x[755], y[755];
    int i, j, a, b;

    scanf("%d", &t);

    while (t--) 
    {
        scanf("%d", &n);

        for(i=1; i<=n; i++)
            scanf("%d %d", &x[i], &y[i]);

        init(n);

        scanf("%d", &m);

        int cont = 0;

        while (m--) 
        {
            scanf("%d %d", &a, &b);
            cont += uniao(a, b);
        }

        if (cont == n-1) 
        {
            puts("No new highways need");
        } 
        
        else 
        {
            m = 0;
            for (i=1; i<=n; i++) 
            {
                for (j=i+1; j<=n; j++) 
                {
                    D[m].x = i, D[m].y = j;
                    D[m].v = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
                    m++;
                }
            }
            
            sort(D, D+m, compara);

            for (i=0; i<m; i++) 
            {
                if (uniao(D[i].x, D[i].y)) 
                {
                    printf("%d %d\n", D[i].x, D[i].y);
                }
            }
        }
        
        if (t)
            puts("");
    }

    return 0;
}

bool compara (dados a, dados b) {
    return a.v < b.v;
}

void init (int n) {
    static int i;
    for(int i = 0; i <= n; i++)
        P[i] = i, R[i] = 1;
}

int findp (int x) {
    return x == P[x] ? x : P[x]=findp(P[x]);
}

int uniao (int x, int y) {
    x = findp(x), y = findp(y);
    if(x != y) {
        if(R[x] > R[y])
            R[x] += R[y], P[y] = x;
        else
            R[y] += R[x], P[x] = y;
        return 1;
    }
    return 0;
}
