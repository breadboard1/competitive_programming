#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1e5 + 5;
ll memory[N];

ll fibo(ll n)
{
    if(n == 0 || n == 1)
        return 1;
    if(memory[n] != -1) return memory[n];
    return memory[n] = fibo(n - 1) + fibo(n - 2);
}

int main() 
{
    ll n;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        memory[i] = -1;
    }
    cout << fibo(n);
    return 0;
}