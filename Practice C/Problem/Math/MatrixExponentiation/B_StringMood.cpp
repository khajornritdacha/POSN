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
    ll K;
    cin >> K;
    Matrix base;
    base.a[0][0] = 19;
    base.a[1][0] = 6;
    base.a[0][1] = 7;
    base.a[1][1] = 20;
    base = expo(base, K);
    cout << base.a[0][0] << "\n";

    /*vector<ll> dp(2);
    dp[0] = 1;
    for(int i=1; i<=K; i++){
        vector<ll> ndp(2);
        ndp[0] = 19*dp[0] + 6*dp[1];
        ndp[1] = 7*dp[0] + 20*dp[1];
        dp = ndp;
    }
    cout << dp[0];*/
    return 0;
}
