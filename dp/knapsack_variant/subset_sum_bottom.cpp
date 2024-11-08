#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s;
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = true;
    for(int i = 0; i < n; i++)
    {
        for(int j  = 0; j < n; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            if(a[i - 1] <= j)
            {
                bool opt1 = dp[i - 1][j - a[i-1]];
                bool opt2 = dp[i - 1][j];
                return dp[i][j] = opt1 || opt2;
            }
            else return dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][s];
    return 0;
}