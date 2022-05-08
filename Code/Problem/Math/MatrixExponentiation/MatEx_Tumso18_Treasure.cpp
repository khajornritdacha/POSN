#include <bits/stdc++.h>
#define FOR(i) for(int (i) = 0; i < 3; i++)
using namespace std;

using ll = long long;
ll mod = 98765431;

struct Matrix{
    ll a[3][3] = {};
    Matrix operator*(const Matrix &other){
        Matrix res;
        FOR(i){
            FOR(j){
                FOR(k){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                    if(res.a[i][j] >= mod*mod)
                        res.a[i][j] -= mod*mod;
                }
                res.a[i][j] %= mod;
            }
        }
        return res;
    }
};

Matrix expo(Matrix base, ll pw){
    Matrix res;
    FOR(i) res.a[i][i] = 1;
    while(pw){
        if(pw&1){
            res = res*base;
        }
        base = base*base;
        pw /= 2;
    }
    return res;
}

void test_case(){
    ll n;
    cin >> n;
    /*vector<ll> dp(3);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        vector<ll> ndp(3);
        ndp[0] = dp[0]+dp[1]+dp[2];
        ndp[1] = dp[0]+dp[2];
        ndp[2] = dp[0]+dp[1];
        dp = ndp;
    }
    cout << dp[0] << " " << dp[1] << " " << dp[2] << "\n";
    cout << dp[0]+dp[1]+dp[2] << "\n";*/

    Matrix base;
    base.a[0][0] = base.a[1][0] = base.a[2][0] = 1;
    base.a[0][1] = base.a[2][1] = 1;
    base.a[0][2] = base.a[1][2] = 1;
    Matrix tot = expo(base, n);
    cout << (tot.a[0][0]+tot.a[0][1]+tot.a[0][2])%mod << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
