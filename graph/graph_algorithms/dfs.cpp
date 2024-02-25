#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector <int> graph[N];
bool visited[N];

void dfs(int u)
{
    // 1 : action just after entering node u
    visited[u] = true;
    cout << "visiting node " << u << endl;
    for(int v : graph[u])
    {
        // 2 : action before entering a new neighbor
        if(visited[v]) continue;
        dfs(v);
        // 3 : action after exiting a neighbor
    }
    // 4 : action before exiting node u
}

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

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
    cout << "visiting array\n";
    // visiting array
    for(int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " status " << visited[i] << endl;
    }
    return 0;
}