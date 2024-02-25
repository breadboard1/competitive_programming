#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 90000007;
const int MOD = 1e9 + 7;

bool isPrime[90000007];
vector <int> ans;

void sieve()
{
    for(int i = 2; i < MAX; i++)
        isPrime[i] = true;
    
    for(int i = 2; i * i <= MAX; i++)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i <= MAX; i++)
    {
        if(isPrime[i]) ans.push_back(i);
    }
}

void solve()
{
    ll n;
    cin >> n;
    cout << ans[n-1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    sieve();
    while(t--)
    {
        solve();
    }
}