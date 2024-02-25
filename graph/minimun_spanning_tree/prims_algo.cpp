#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pqii;
const int N = 1e3 + 5;
vector <pii> graph[N];
bool visited[N];
vector <pair<pii, int>> edgeList;

void prims(int s)
{
    priority_queue <pqii, vector<pqii>, greater<>> pq;
    pq.push({0, {s, s}});

    while(!pq.empty())
    {
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();

        if(visited[v]) continue;
        visited[v] = true;
        edgeList.push_back({{u, v}, w});

        for(pii vpair : graph[v])
        {
            int nd = vpair.first;
            int w = vpair.second;
            if(!visited[nd])
            {
                pq.push({w, {v, nd}});
            }
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    prims(1);
    edgeList.erase(edgeList.begin());
    for(auto upair : edgeList)
    {
        cout << upair.first.first << " " << upair.first.second << " " << upair.second << endl;
    }
    return 0;
}