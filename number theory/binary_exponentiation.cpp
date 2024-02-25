#include <bits/stdc++.h>
using namespace std;

int binary_exponentiation(int base, int power)
{
    int result = 1;
    while(power)
    {
        if(power & 1) 
        {
            result = result * base;
            power--;
        }
        else 
        {
            power = power / 2;
            base = base * base;
        }
    }
    return result;
}

int main() 
{
    int base, power;
    cin >> base >> power;
    cout << binary_exponentiation(base, power);
    return 0;
}