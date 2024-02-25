#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef pair<ll, ll> pii;
const int MAX = 2e9 + 23;
const int N = 1e5 + 23;
ll inf = 1e18 + 23;
const int mod = 1e9 + 7;
#define rep(i, n) for(int i = 1; i <= n; i++)
#define For(i, n) for(int i = 0; i < n; i++)
//ll b_pow(ll b, ll p);

void solve()
{
    string s;
    cin >> s;
    int first = 0;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] != '0') 
        {
            first = i;
            break;
        }
    }
    if(first == 0)
    {
      cout << -1 << '\n';
      return;
    }
    int n = s.size();
    string s1 = s.substr(0, first);
    string s2 = s.substr(first, n);
    bool pos = 1;
    int f = stoi(s1);
    int sec = stoi(s2);
    if(f == 0 || sec == 0) pos = 0;
    if((sec <= f) || !pos) cout << -1 << '\n';
    else cout << f << " "  << sec << "\n";
    // cout << s1 << " " << s2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll t = 1;
    cin >> t;
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