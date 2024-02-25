#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 1; i <= n; i++)
typedef long long ll;
const int MOD = 1e9 + 7;
ll mat[1005][1005];
ll I[1005][1005];

void mul(ll A[][1005], ll B[][1005], int dim)
{
    ll tmp[dim+1][dim+1];
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
    //updating I
    REP(i, dim) REP(j, dim) I[i][j] = tmp[i][j];
}

void pow(int dim, int power)
{
    //setting identity matrix
    REP(i, dim) REP(j, dim)
    {
        if(i == j) I[i][j] = 1;
        else I[i][j] = 0;
    }

    while(power)
    {
        if(power & 1)
        {
            mul(I, mat, dim);
            power--;
        }
        else
        {
            mul(mat, mat, dim);
            power = power / 2;
        }
    }
    REP(i, dim) REP(j, dim) mat[i][j] = I[i][j];
}

void printMat(int dim)
{
    REP(i, dim)
    {
        REP(j, dim) cout << mat[i][j] << " ";
        cout << '\n';
    }
}

int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int dim, power;
        cin >> dim >> power;
        REP(i, dim) REP(j, dim) cin >> mat[i][j];

        pow(dim, power);
        printMat(dim);
    }
    return 0;
}