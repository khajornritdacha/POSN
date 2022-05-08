#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int S = 5;

ll mod = 1e9+7;

struct Matrix{
    ll a[5][5] = {};
    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i = 0; i < S; i++){
            for(int j = 0; j < S; j++){
                for(int k = 0; k < S; k++){
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
    for(int i = 0; i < S; i++) res.a[i][i] = 1;
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
    int n;
    cin >> n;
    /*dp[0][0] = dp[0][1] = dp[0][2] = 1;
    ll dp[300][3], mod = 1e9+7, qs[300][3];
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1]+qs[i-1][2];
        dp[i][1] = dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][2] = dp[i-1][1]+dp[i-1][2]+qs[i-1][0];
        qs[i][0] = qs[i-1][0]+dp[i-1][0];
        qs[i][2] = qs[i-1][2]+dp[i-1][2];
    }*/
/*
    vector<ll> dp(5); ///qs(0) = 3, qs(2) = 4
    dp[0] = dp[1] = dp[2] = 1;
    for(int i = 1; i <= n; i++){
        vector<ll> ndp(5);
        ndp[0] = dp[0]+dp[1]+dp[3];
        ndp[1] = dp[0]+dp[1]+dp[2];
        ndp[2] = dp[1]+dp[2]+dp[4];
        ndp[3] = dp[3]+dp[0];
        ndp[4] = dp[4]+dp[2];
        //ndp[5] = dp[0]+dp[1]+dp[2];
        dp = ndp;
    }
    cout << dp[0] << " " << dp[1] << " " << dp[2] << "\n";
    cout << dp[0]+dp[1]+dp[2] << "\n";
    //cout << dp[5] << "\n";*/

    Matrix base;
    base.a[0][0] = base.a[1][0] = base.a[3][0] = 1;
    base.a[0][1] = base.a[1][1] = base.a[2][1] = 1;
    base.a[1][2] = base.a[2][2] = base.a[4][2] = 1;
    base.a[3][3] = base.a[0][3] = 1;
    base.a[4][4] = base.a[2][4] = 1;

    Matrix tot = expo(base, n);


    vector<ll> dp(5), ans(5); ///qs(0) = 3, qs(2) = 4
    dp[0] = dp[1] = dp[2] = 1;
    for(int j = 0; j < S; j++){
        for(int k = 0; k < S; k++){
            ans[j] += dp[k]*tot.a[k][j];
            ans[j] %= mod;
        }
    }

    cout << (ans[0]+ans[1]+ans[2])%mod << "\n";
    return 0;
}
