#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector <int> graph[N];
bool visited[N];
vector <int> myList;

void dfs(int u)
{
    visited[u] = true;
    
    for(int v : graph[u])
    {
        if(visited[v]) continue;
        dfs(v);
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
    int cc = 0;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        dfs(i);
        cc++;
        myList.push_back(i);
    }
    cout << cc - 1;
    cout << endl;
    for(int i = 0; i < myList.size() - 1; i++)
    {
        cout << myList[i] << " " << myList[i + 1] << endl;
    }
    return 0;
}