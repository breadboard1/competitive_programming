#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 23;
vector<bool> is_prime(N, true);

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i <= N; i++) 
    {
        if(is_prime[i]) 
        {
            for(ll j = i * i; j <= N; j += i) is_prime[j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve();
    return 0;
}


