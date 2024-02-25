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

ll ok(ll n, ll x, ll a[])
{
    //base
    if(n == 0) 
    {
        if(x == 0) return 1;
        else return 0;
    }
    ll op1 = ok(n-1, x + a[n-1], a);
    ll op2 = ok(n-1, x - a[n-1], a);
    return op1 || op2;
}

void solve()
{
    ll n, x; cin >> n >> x;
    ll a[n];
    For(i, n) cin >> a[i];
    if(ok(n, x, a)) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t = 1;
    // cin >> t;
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