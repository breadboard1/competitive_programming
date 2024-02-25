#include <bits/stdc++.h>
using namespace std;

const int N = 8;
bool visited[N][N];
int level[N][N];
typedef pair<int, int> pii;
vector <pii> directions = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
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

            if(isValid(ni, nj) && !visited[ni][nj])
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }

}

void zeroSetter()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            visited[i][j] = false;
            level[i][j] = 0;
        }
    }
}

int main() 
{
    int n; 
    int si, sj, di, dj;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        
        si = x[0] - 'a';
        sj = x[1] - '1';

        di = y[0] - 'a';
        dj = y[1] - '1';

        bfs(si, sj);
        cout << level[di][dj] << endl;
        zeroSetter();
    }
    return 0;
}