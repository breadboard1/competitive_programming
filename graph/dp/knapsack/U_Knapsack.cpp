#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef pair<ll, ll> pii;
const int MAX = 2e9 + 23;
ll inf = 1e18 + 23;
const int mod = 1e9 + 7;
#define rep(i, n) for(int i = 1; i <= n; i++)
#define For(i, n) for(int i = 0; i < n; i++)
//ll b_pow(ll b, ll p);

ll knapsack(ll n, ll w, ll wei[], ll v[])
{
    //base
    if(n == 0 || w == 0) return 0;
    else if(wei[n-1] <= w)
    {
        ll op1 = knapsack(n - 1, w - wei[n - 1], wei, v) + v[n - 1];
        ll op2 = knapsack(n - 1, w, wei, v);
        return max(op1, op2);
    }
    else 
    {
        return knapsack(n - 1, w, wei, v);
    }
}

void solve()
{
    ll n, w;
    cin >> n >> w;
    ll wei[n], v[n];
    for(int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        wei[i] = x;
        v[i] = y;
    }
    cout << knapsack(n, w, wei, v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}

//ll b_pow(ll b, ll p)
//{
//    ll r = 1;
//    while(p)
//    {
//        if(p & 1) 
//        {
//            r = r * b;
//            p--;
//        }
//        else 
//        {
//            p = p / 2;
//            b = b * b;
//        }
//    }
//    return r;
//}