#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int unboundedKnapsack(int w[], int v[], int n, int s)
{
    if(n == 0 || s == 0) return 0;
    if(dp[n][s] != -1) return dp[n][s];

    if(w[n-1] <= s)
    {
        int op1 = unboundedKnapsack(w, v, n, s - w[n-1]) + v[n - 1];
        int op2 = unboundedKnapsack(w, v, n - 1, s);
        return dp[n][s] =  max(op1, op2);
    }
    else return dp[n][s] = unboundedKnapsack(w, v, n - 1, s);
}

int main() 
{
    int n;
    cin >> n;
    int v[n], w[n];

    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
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
    cout << unboundedKnapsack(w, v, n, s);

    return 0;
}