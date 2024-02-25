#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
bool visited[N];
vector <int> graph[N];
int level[N];

void bfs(int s, int strength)
{
    queue<int>q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

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
            if(level[v] > strength) return;
        }
    }
}

void reset()
{
    for(int i = 0; i < N; i++)
    {
        level[i] = 0;
        graph[i].clear();
    }
}

int main() 
{
    int t; 
    cin >> t;
    while(t--)
    {
        int n, r, m;
        cin >> n >> r >> m;
        
        for(int i = 0; i < r; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 0; i < m; i++)
        {
            int k, strength;
            cin >> k >> strength;
            bfs(k, strength);
        }

        bool flag = true;
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j])
            {
                flag = false;
                break;
            }
        }

        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
        reset();
    }
    return 0;
}