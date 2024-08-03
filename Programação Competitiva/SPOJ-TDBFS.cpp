/*
For a given list of adjacent vertices of a graph and a chosen vertex v 
write down in the Depth First Search (DFS) or Breadth First Search (BFS) 
order all the vertices from the connected component of the graph containing v. 
Assume that the number of vertices of the graph is at most 1000.
*/

/*--Bibliotecas e definições--*/
#include <bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<queue>
#define usi unsigned

using namespace std;

/*--Bibliotecas--*/
usi int testes, vertices, vert, vizinhos, viz, tipo;
bool visitou[1024];
vector<unsigned int> grafo [1024];

/*--Bibliotecas--*/
void BFS(int v); // Breadth-First Search
void DFS(int v); // Depth-First Search

int main(void) 
{
    scanf("%u", &testes);
    for(usi int t=0; t<testes; ++t)
    {
        scanf("%u", &vertices);
        for(usi int v=1; v<=vertices; ++v)
            grafo[v].clear();

        for(usi int w=0; w<vertices; ++w)
        {
           scanf("%u%u", &vert, &vizinhos);
			for(unsigned int n = 0; n < vizinhos; ++ n)
			{
				scanf("%u", &viz);
				grafo[vert].push_back(viz);
			} 
        }

        printf("graph %u\n", t + 1);
		while(scanf("%u%u", &vert, &tipo) != -1 && vert != 0)
		{
			for(unsigned int v = 1; v <= vertices; ++ v)
				visitou[v] = false;

			if(tipo)
				BFS(vert);

			else
				DFS(vert);

			puts("");
		}
    }

    return 0;

}

void BFS(int v)
{
	queue<unsigned int> que;
	que.push(v);
	visitou[v] = true;
	while(!que.empty())
	{
		v = que.front();
		printf("%u ", v);
		que.pop();
		for(unsigned int n = 0; n < grafo[v].size(); ++ n)
			if(!visitou[grafo[v][n]])
			{
				visitou[grafo[v][n]] = true;
				que.push(grafo[v][n]);
			}
	}

	return;
}

void DFS(int v)
{
	printf("%d ", v);
	visitou[v] = true;
	for(unsigned int n = 0; n < grafo[v].size(); ++ n)
		if(!visitou[grafo[v][n]])
			DFS(grafo[v][n]);

	return;
}

