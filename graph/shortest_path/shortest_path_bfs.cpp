#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> graph[N];
bool visited[N];
int level[N];
int parrent[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parrent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : graph[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parrent[v] = u;
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << "distance : " << level[d] << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << "parrent of " << i << " : " << parrent[i] << endl;
    }
    
    //parrent printing order --->>> O(n)
    vector<int> path;
    int current = d;
    while(current != -1)
    {
        path.push_back(current);
        current = parrent[current];
    }

    reverse(path.begin(), path.end());
    for(int val : path)
    {
        cout << val << " ";
    }
    return 0;
}