#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector <pair<int, int>> graph[N]; //arrays of vector

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
    for(int i = 1; i <= n; i++)
    {
        // sort(graph[i].begin(), graph[i].end());  //sorting
        for(pair<int,int> val : graph[i])
        {
            cout << "(" << val.first << ", "; 
            cout << val.second << ") ";
        }
        cout << endl;
    }
    return 0;
}