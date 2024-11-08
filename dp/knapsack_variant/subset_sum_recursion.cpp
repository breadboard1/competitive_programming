#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool subset(int arr[], int n, int s)
{
    if(n == 0)
    {
        if(s == 0) return true;
        else return false;
    }

    if(dp[n][s] != -1) return dp[n][s];

    if(arr[n - 1] <= s)
    {
        bool opt1 = subset(arr, n - 1, s - arr[n-1]);
        bool opt2 = subset(arr, n - 1, s);
        return dp[n][s] = opt1 || opt2;
    }
    else return dp[n][s] = subset(arr, n - 1, s);
}

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
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
    if(subset(arr, n, s)) cout << "yes";
    else cout << "no";
    return 0;
}