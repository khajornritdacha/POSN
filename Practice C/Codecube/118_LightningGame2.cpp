#include <bits/stdc++.h>
using namespace std;
const int N = 105;
using ll = long long;
ll K,mod=1e9+7;

struct Matrix{
    ll a[N][N] = {};
    Matrix operator *(const Matrix &other){
        Matrix res;
        for(int i=0; i<=2*K; i++){
            for(int j=0; j<=2*K; j++){
                for(int k=0; k<=2*K; k++){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                    if(res.a[i][j] >= 8ll*mod*mod){
                        res.a[i][j] -= 8ll*mod*mod; ///Lord Errichto's Trick
                    }
                }
                res.a[i][j] %= mod;
            }
        }
        return res;
    }
};

Matrix expo(Matrix base, ll n){
    Matrix res;
    for(int i=0; i<=2*K; i++) res.a[i][i] = 1;
    while(n){
        if(n&1){
            res = res*base;
        }
        base = base*base;
        n /= 2;
    }
    return res;
}

void test_case(){
    ll n;
    cin >> n >> K;
    Matrix tot;
    tot.a[K-1][2*K] = 1;
    for(int k=1; k<=K-1; k++)
        tot.a[k-1][k] = 1;
    for(int k=K+1; k<=2*K; k++)
        tot.a[k-1][k] = 1;
    for(int k=0; k<=K-1; k++)
        tot.a[k][0] = 1;
    for(int k=K; k<=2*K; k++)
        tot.a[k][K] = 1;
    Matrix ans = expo(tot, n);
    ll res = 0;
    for(int k=K; k<=2*K; k++)
        res = (res+ans.a[0][k])%mod;
    cout << res << "\n";
}
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        cout << "Case #" << tt << ": ";
        test_case();
    }
    return 0;
}
