#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 1e9+7;

struct Matrix{
    ll a[2][2] = {};
    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

Matrix expo(Matrix base, ll pw){
    Matrix res;
    for(int i=0; i<2; i++) res.a[i][i] = 1;
    while(pw){
        if(pw&1){
            res = res*base;
        }
        base = base*base;
        pw /= 2;
    }
    return res;
}

int main(void){
    ll K,f[2];
    f[0] = 55, f[1] = 89; ///F[0] = Fibonacci 10th, F[1] = Fibonacci 11th
    cin >> K; ///If K = 5 -> Have to print Fibonacci (10+5) = 15th
    Matrix base;
    base.a[0][0] = 0;
    base.a[1][0] = 1;
    base.a[0][1] = 1;
    base.a[1][1] = 1;
    base = expo(base, K);///CF stands for coefficient
    cout << base.a[0][0]*f[0]+base.a[1][0]*f[1] << "\n"; ///Fibonacci of (10+K)th = CF(0, 0)*F[10] + CF(1, 0)*F[11]

    vector<ll> dp(2);
    dp[0] = f[0], dp[1] = f[1];
    for(int i=1; i<=K; i++){
        vector<ll> ndp(2);
        ndp[0] = 0*dp[0] + 1*dp[1]; ///1, coefficient precede dp[1], actually is not 1, but it is the result of the matrix exponentiation index(1, 0)
        ndp[1] = 1*dp[0] + 1*dp[1];
        dp = ndp;
    }
    cout << dp[0];
    return 0;
}
