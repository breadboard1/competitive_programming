#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define nl "\n"
const int N = 2e5 + 23;
ll inf = 1e18 + 23;
const int mod = 1e9 + 7;
//clockwise  U  R  D  L
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a){
        cin >> i;
    }
    vector<int> lis, len;
    for(int i = 0; i < n; i++){
        if(lis.empty() || lis.back() < a[i]){
            lis.push_back(a[i]);
            len.push_back(lis.size());
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
            len.push_back(it-lis.begin()+1);
        }
    }
    cout << lis.size() << nl;
    int curlen = lis.size();
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        if(curlen == len[i]){
            ans.push_back(a[i]);
            curlen--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x: ans){
        cout << x << " ";
    }
    return 0;
}
