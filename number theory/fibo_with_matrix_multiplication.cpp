#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 1; i <= n; i++)
#define dim 2
const int MOD = 1e9 + 7;
typedef long long ll;

ll mat[3][3];
ll I[3][3];
ll fibo[3];

void mul(ll A[3][3], ll B[3][3])
{
    ll tmp[3][3];
    REP(i, dim)
    { 
        REP(j, dim)
        {
            tmp[i][j] = 0;
            REP(k, dim)
            {
                ll x = (A[i][k] * B[k][j]) % MOD;
                tmp[i][j] = (tmp[i][j] + x) % MOD;
            }
        }
    }

    //saving into A
    REP(i, dim)
    { 
        REP(j, dim)
        {
            A[i][j] = tmp[i][j];
        }
    } 
}

ll power(int pow)
{
    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;

    mat[1][1] = 0;
    mat[1][2] = mat[2][1] = mat[2][2] = 1;

    while(pow)
    {
        if(pow & 1)
        {
            mul(I, mat);
            pow--;
        }
        else
        {
            mul(mat, mat);
            pow = pow / 2;
        }
    }

    ll fn = (fibo[1] * I[1][1] + fibo[2] * I[2][1]) % MOD;
    return fn;
}

int main()
{
    int n;
    cin >> n;
    fibo[1] = fibo[2] = 1;
    cout << power(n - 1);
    return 0;
}