#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

ll mod = 1e9+7;

struct Matrix{
    ll a[2][2] = {};
    Matrix operator * (const Matrix &other){
        Matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};


Matrix expo(Matrix base, int pw){
    Matrix res;
    res.a[0][0] = res.a[1][1] = 1;
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
    /*dp[1][0] = dp[1][1] = 1;
    vector<ll> dp(2, 1);
    for(int i = 2; i <= 1e6; i++){
        vector<ll> ndp(2);
        ndp[0] = (dp[0]*4 + dp[1])%mod;
        ndp[1] = (dp[0]   + dp[1]*2)%mod;
        dp = ndp;
    }*/

    Matrix base;
    base.a[0][0] = 4; base.a[1][0] = 1;
    base.a[0][1] = 1; base.a[1][1] = 2;

    int Q; cin >> Q;
    while(Q--){
        int n; cin >> n;
        Matrix res = expo(base, n-1);
        cout << (res.a[0][0] + res.a[0][1] + res.a[1][0] + res.a[1][1])%mod << "\n";
    }
    return 0;
}
