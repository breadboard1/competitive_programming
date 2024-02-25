#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector <int> graph[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{
    // 1 : action just after entering node u
    visited[u] = true;
    //cout << "visiting node " << u << endl;
    for(int v : graph[u])
    {
        // 2 : action before entering a new neighbor
        if(visited[v]) continue;
        depth[v] = depth[u] + 1;  //depth calculation
        dfs(v);
        // 3 : action after exiting a neighbor
        height[u] = max(height[u], height[v] + 1);
    }
    // 4 : action before exiting node u
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
    dfs(1);
    for(int i = 1; i <= n; i++)
    {
        cout << "depth of " << i << " " << depth[i] << endl;
    }
    cout << "**************" << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << "height of " << i << " " << height[i] << endl;
    }
    return 0;
}