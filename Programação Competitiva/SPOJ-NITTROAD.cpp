
    #include<stdio.h>
    #include<bits/stdc++.h>

    using namespace std;

    typedef struct No
    {
    	int u;
    	int v;
    	int flag;
    }no;


    typedef struct No1
    {
    	int par;
    	int cont;
    	int alt;
    } no1;

    no1 dsu[20005];
    no E[20005];
    stack<pair<char, int> > qs;
    stack<long long> resp;
    long long curr;

    int find (int ver)
    {
    	if (dsu[ver].par == -1)
        {
    		return ver;
    	}
    	return find(dsu[ver].par);
    } 

    void uniao(int u, int v){
    	int ru, rv;
    	ru = find(u);
    	rv = find(v);
     
    	curr-=(dsu[ru].cont * dsu[rv].cont);
    	
        if (dsu[ru].alt > dsu[rv].alt) 
        {
    		dsu[rv].par = ru;
    		dsu[ru].cont += dsu[rv].cont;
    	}

    	else 
        
        if (dsu[rv].alt>dsu[ru].alt) 
        {
    		dsu[ru].par=rv;
    		dsu[rv].cont+=dsu[ru].cont;
    	}

    	else
        {
    		dsu[rv].par=ru;
    		dsu[ru].cont+=dsu[rv].cont;
    		dsu[ru].alt++;	
    	}
     
    }

    int main ()
    {
    	int T;
    	scanf("%d", &T);

    	while(T--){
     
    		for (int i=0; i<20005; i++)
            {
    			dsu[i].par=-1;
    			dsu[i].cont=1;
    			dsu[i].alt=0;
    		}
     
    		int n, q, r;
    		char ch;

    		scanf("%d", &n);

    		curr = (n*(n-1))/2;
     
    		for (int i=1; i<=n-1; i++)
            {
    			scanf("%d %d", &E[i].u, &E[i].v);
    			E[i].flag=1;
    		}
     
    		scanf("%d", &q);

    		while (q--) 
            {
    			scanf("\n%c", &ch);

    			if (ch=='Q')
                {
    				qs.push(make_pair('Q', -1));
    			}

    			else
                {
    				scanf("%d", &r);
    				E[r].flag = 0;
    				qs.push(make_pair('R', r));
    			}
    		}
     
    		for (int i=1; i<=n-1; i++)
            {
    			if (E[i].flag==1) 
                {
    				uniao(E[i].u, E[i].v);
    			}
    		}
     
    		while (!qs.empty())
            {
    			if (qs.top().first=='Q') 
                {
    				resp.push(curr);
    			}

    			else
                {
    				r=qs.top().second;
    				uniao(E[r].u, E[r].v);
    			}
    			qs.pop();
    		}
     
    		while (!resp.empty()) 
            {
    			printf("%lld\n", resp.top());
    			resp.pop();
    		}

    		printf("\n");
    	}
    	return 0;
    } 
