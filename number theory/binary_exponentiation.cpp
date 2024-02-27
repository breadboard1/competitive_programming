#include <bits/stdc++.h>
using namespace std;

ll bin_pow(ll base, ll power)
{
    ll result = 1;
    while(power)
    {
        if(power & 1) 
        {
            result = result * base;
            power--;
        }
        else 
        {
            power >>= 1;
            base = base * base;
        }
    }
    return result;
}

int main() 
{
    int base, power;
    cin >> base >> power;
    cout << bin_pow(base, power);
    return 0;
}
