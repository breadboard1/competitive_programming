#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

//first equal hole second tar minimum ta nibe.

class cmp 
{
    public:
        bool operator()(const pii& a, const pii& b) const 
        {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    priority_queue<pii, vector<pii>, cmp>pq;
    return 0;
}
