#include <bits/stdc++.h>
using namespace std;

int modular_exponentiation(int base, int power, int p)
{
    int result = 1;
    while(power)
    {
        if(power & 1) 
        {
            result = (result * base) % p;
            power--;
        }
        else 
        {
            power = power / 2;
            base = (base * base) % p;
        }
    }
    return result;
}

int main() 
{
    int base, power, prime;
    cin >> base >> power >> prime;
    cout << modular_exponentiation(base, power, prime);
    return 0;
}