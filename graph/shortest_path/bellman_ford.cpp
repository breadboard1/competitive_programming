#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e5 + 10;
vector <pii> graph[N];
int dist[N];
int n, m;

void bellmanFord(int s)
{
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    dist[s] = 0;

    for(int i = 1; i < n; i++)
    {
        for(int u = 1; u <= n; u++)
        {
            for(pii vpair : graph[u])
            {
                int v = vpair.first;
                int w = vpair.second;
                if(dist[u] != INF && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    bellmanFord(1);

    for(int i = 1; i <= n; i++)
    {
        cout << "dist " << i << " : " << dist[i] << endl;
    }
    return 0;
}