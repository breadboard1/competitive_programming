#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adjMat[N][N];

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main() 
{
    init_code();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        // cin >> u >> v >> w;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; //for undirected graph
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}