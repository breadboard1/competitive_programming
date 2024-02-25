#include <bits/stdc++.h>
using namespace std;

int parent[1001];
int parentLevel[1001];

void dsu_set(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
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
        if(parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if(parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;

        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
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