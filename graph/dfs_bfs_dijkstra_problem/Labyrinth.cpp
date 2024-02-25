#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int N = 1e3 + 5;
int n, m;
vector <string> g;
bool visited[N][N];
int level[N][N];
vector <pii> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
pii parrent[N][N];

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue <pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty())
    {
        pii upair = q.front();
        q.pop();

        int i = upair.first;
        int j = upair.second;

        for(auto d : directions)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if(isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parrent[ni][nj] = {i, j};
            }
        }

    }
}

int main() 
{
    cin >> n >> m;
    int si, sj;
    int di, dj;

    for(int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        g.push_back(x);

        for(int j = 0; j < m; j++)
        {
            if(x[j] == 'A')
                si = i, sj = j;
            if(x[j] == 'B')
                di = i, dj = j;
        }
    }

    //printing output
    bfs(si, sj);
    if(level[di][dj] != 0)
    {
        cout << "YES" << endl;
        cout << level[di][dj] << endl;
    }
    else
    {
        cout << "NO";
        return 0;
    }

    //path tracking
    vector <pii> path;
    pii curr = {di, dj};

    while(!(curr.first == si && curr.second == sj))
    {
        path.push_back(curr);
        curr = parrent[curr.first][curr.second];
    }

    path.push_back({si, sj});
    reverse(path.begin(), path.end());
    
    for(int i = 1; i < path.size(); i++)
    {
        //dane bame
        if(path[i - 1].first == path[i].first)
        {
            if(path[i - 1].second == path[i].second + 1)
            {
                cout << "L";
            }
            else cout << "R";
        }
        //upor niche
        else
        {
            if(path[i - 1].first == path[i].first + 1)
            {
                cout << "U";
            }
            else cout << "D";
        }
    }
    return 0;
}