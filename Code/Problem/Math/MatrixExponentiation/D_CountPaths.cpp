#include <bits/stdc++.h>
using namespace std;

const int N = 110;
using ll = long long;

ll mod = 1e9+7,sz;

struct Matrix{
    ll a[N][N] = {};
    Matrix operator *(const Matrix &other){
        Matrix res;
        for(int i=1; i<=sz; i++){
            for(int j=1; j<=sz; j++){
                for(int k=1; k<=sz; k++){
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
    for(int i=1; i<=sz; i++) res.a[i][i] = 1;
    while(pw){
        if(pw & 1){
            res = res*base;
        }
        base = base*base;
        pw /= 2;
    }
    return res;
}

int main(void){
    int n,m,K;
    cin >> n >> m >> K;
    sz = n;
    Matrix base;
    for(int i=1; i<=m; i++){
        int u,v; cin >> u >> v;
        base.a[u][v] = 1;
    }
    base = expo(base, K);

    ll ans = 0;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) ans = (ans+base.a[i][j])%mod;
    cout << ans << "\n";

    return 0;
}
