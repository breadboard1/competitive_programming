#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> pqii;
int parent[1001];
int parentLevel[1001];

bool cmp(pqii a, pqii b)
{
    return a.second < b.second;
}

void dsu_set(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}

int dsu_find(int node)
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if(leaderA != leaderB) 
    {
        if(parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if(parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;

        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    dsu_set(n);
    vector<pair<pii, int>> vec;
    vector<pair<pii, int>> ans;

    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back({{u, v}, w});
    }
    
    sort(vec.begin(), vec.end(), cmp);
    for(auto val : vec)
    {
        int a = val.first.first;
        int b = val.first.second;
        int w = val.second;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if(leaderA == leaderB) continue;
        ans.push_back({{a, b}, w});
        dsu_union(a, b);
    }
    for(auto val : ans)
    {
        cout << val.first.first << " " << val.first.second << " " << val.second << endl; 
    }
    return 0;
}