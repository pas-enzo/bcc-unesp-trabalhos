#include<stdio.h>
#include<string.h>
#define TAM 100000


static int pai[TAM];
static int rank[TAM];
static int elem[TAM];

int max;

void Cria_Novo (int n)
{
    for(int i = 0; i < n; ++i){
        pai[i]  = i;
        rank[i] = 0;
        elem[i] = 1;
    }
}

int Procura (int x)
{
    if(x != pai[x])
        pai[x] = Procura(pai[x]);
    return pai[x];
}

bool Mesmo_Set(int x, int y){
    return Procura(x) == Procura(y);
}

void Link (int x, int y)
{

    if(!Mesmo_Set(x, y))
    {

        if(rank[x] > rank[y])
        {
            pai[y] = x;
            elem[x] += elem[y];
            max = ( max < elem[x] ) ? elem[x] : max;
        }
        
        else
        {
            pai[x] = y;
            elem[y] += elem[x];
            max = (max < elem[y]) ? elem[y] : max;

            if(rank[x] == rank[y])
                rank[y] = rank[y] + 1;
        }

    }
}

void Uniao (int x, int y) 
{
    Link (Procura(x), Procura(y) );
}



int main()
{

    int n, m, i, j;


    int t;
    scanf("%d", &t);


    while(t--)
    {

        scanf("%d%d", &n, &m);

            Cria_Novo(n);

            max = 1;

            while (m--)
            {
                scanf("%d%d", &i, &j);
                --i, --j;
                Uniao(i, j);
            }

            printf("%d\n", max);

        }


    return 0;
}