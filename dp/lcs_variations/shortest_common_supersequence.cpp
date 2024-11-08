#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i - 1] == b[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; 
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int ci = n;
    int cj = m;
    string ans;
    while(ci != 0 && cj != 0)
    {
        if(a[ci - 1] == b[cj - 1])
        {
            ans += a[ci - 1];
            ci--;
            cj--;
        }
        else if(dp[ci - 1][cj] > dp[ci][cj - 1])
        {
            ans += a[ci - 1];
            ci--;
        }
        else 
        {
            ans += b[cj - 1];
            cj--;
        }
    }
    while(ci != 0)
    {
        ans += a[ci - 1];
        ci--;
    }
    while(cj != 0)
    {
        ans += b[cj - 1];
        cj--;
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}