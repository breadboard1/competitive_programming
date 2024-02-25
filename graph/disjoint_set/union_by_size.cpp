#include <bits/stdc++.h>
using namespace std;

int parent[1001];
int parentSize[1001];

void dsu_set(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if(leaderA != leaderB) 
    {
        parent[leaderB] = leaderA;
        if(parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderA] = leaderB;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else 
        {
            parent[leaderB] = leaderA;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    dsu_set(n);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << parent[i] << endl;
    }
    return 0;
}