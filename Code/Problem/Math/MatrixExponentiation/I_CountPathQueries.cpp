#include <bits/stdc++.h>
using namespace std;

const int N = 205;
using ll = long long;
ll mod = 1e9+7;


struct Matrix{
    ll a[N][N] = {};
    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

int main(void){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,Q;
    cin >> n  >> m >> Q;

    //cout << n << " " << m << " " << Q << "\n";
    Matrix base;
    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        base.a[u-1][v-1] = 1;
        //cout << mat[0].a[u-1][v-1] << "\n";
    }

    vector<Matrix> mat{base};
    for(int i = 1; (1<<i) <= 1e9; i++){
        //cout << "SZ : " << mat[i-1].a.size() << " " << mat[i-1].a[0].size() << "\n";
        //cout << "I : " << i << "\n";
        mat.push_back(mat.back()*mat.back());
    }

    while(Q--){
        int u,v,K; cin >> u >> v >> K;
        vector<ll> dp(n);
        //cout << "U : " << u << "\n";
        dp[u-1] = 1;
        for(int i = 0; K; K /= 2, i++){
            if(K&1){
                vector<ll> ndp(n);
                for(int j = 0; j < n; j++){
                    for(int k = 0; k < n; k++){
                        ndp[j] = (ndp[j]+dp[k]*mat[i].a[k][j])%mod;
                    }
                }
                dp = ndp;
            }
        }
        cout << dp[v-1] << "\n";
    }
    return 0;
}
