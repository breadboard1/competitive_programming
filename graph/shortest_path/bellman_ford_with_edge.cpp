#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e5 + 10;
vector <pair<pii, int>> edges;
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

    // O(n*m) complexity --> dense hole O(n^3)
    // sparse --> O(n^2)
    
    for(int i = 1; i < n; i++)  // n-1 times
    {
        for(auto edge : edges)   // edge times
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;

            if(dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    //negative cycle detection
    // for(auto edge : edges)
    // {
    //     int u = edge.first.first;
    //     int v = edge.first.second;
    //     int w = edge.second;
    //     if(dist[u] != INF && dist[v] > dist[u] + w)
    //     {
    //         // dist[v] = dist[u] + w;
    //         flag = true;
    //     }
    // }
    // if(flag) cout << "YES, negative cycle detected!" << endl;
    // else cout << "NO" << endl;
}

int main() 
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }
    
    bellmanFord(1);

    for(int i = 1; i <= n; i++)
    {
        cout << "dist " << i << " : " << dist[i] << endl;
    }
    return 0;
}