#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9 + 5;
int adjMat[N][N];
int n, m;

void initMat()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j) adjMat[i][j] = INF;
        }
    }
}

void printMat()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(adjMat[i][j] == INF) cout << "X ";
            else cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    cin >> n >> m;
    initMat();
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjMat[u][v] = w;
        // adjMat[v][u] = w;
    }

    cout << "Before Floyd Warshall :\n";
    printMat();
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            }
        }
    }

    cout << "After Floyd Warshall:\n";
    printMat();

    return 0;
}