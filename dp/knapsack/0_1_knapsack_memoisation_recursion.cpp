#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];  //O(n*s)

int knapsack(int v[], int w[], int n, int s)
{
    if(n == 0 || s == 0) return 0;

    if(dp[n][s] != -1) return dp[n][s];
    if(s >= w[n - 1])
    {
        int choice1 = knapsack(v, w, n - 1, s - w[n - 1]) + v[n - 1];
        int choice2 = knapsack(v, w, n - 1, s);
        return dp[n][s] = max(choice1, choice2);
    }
    else return dp[n][s] = knapsack(v, w, n - 1, s);
}

int main() 
{
    int n;
    cin >> n;
    int v[n], w[n];
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(v, w, n, s);
    return 0;
}