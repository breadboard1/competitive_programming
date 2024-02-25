#include <bits/stdc++.h>
using namespace std;

const int N = 1e+5;
vector <int> graph[N]; //arrays of vector

// void printVector(vector <int> mylist)
// {
//     for(int val : mylist)
//     {
//         cout << val << " ";
//     }
//     cout << endl;
// }

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
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    {
        // sort(graph[i].begin(), graph[i].end());  //sorting
        for(int val : graph[i])
        {
            cout << val << " ";
        }
        cout << endl;
        // printVector(graph[i]);
    }
    return 0;
}