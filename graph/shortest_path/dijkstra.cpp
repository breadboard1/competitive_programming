#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = INT_MAX;
vector <pii> graph[N];
vector <int> dist(N, INF);
vector <bool> visited(N);

void dijkstra(int s)
{
    priority_queue <pii, vector<pii>, greater<>> pq;
    dist[s] = 0; 
    pq.push({dist[s], s});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;
        for(pii vpair : graph[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if(visited[v]) continue;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}


int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(1);
    for(int i = 1; i <= n; i++)
    {
        cout << "distance of " << i << " : " << dist[i] << endl;
    }
    return 0;
}