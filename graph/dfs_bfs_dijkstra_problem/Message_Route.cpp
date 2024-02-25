#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector <int> graph[N];
int level[N];
int parrent[N];

void bfs(int s)
{
    queue <int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 1;
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

    if(graph[1].empty())
    { 
        cout << "IMPOSSIBLE";
        return 0;
    }

    bfs(1);

    if(!visited[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> myList;
    int current = n;
    while(current != -1)
    {
        myList.push_back(current);
        current = parrent[current];
    }
    reverse(myList.begin(), myList.end());
    cout << level[n] << endl;
    for(int val : myList)
    {
        cout << val << " ";
    }
    return 0;
}