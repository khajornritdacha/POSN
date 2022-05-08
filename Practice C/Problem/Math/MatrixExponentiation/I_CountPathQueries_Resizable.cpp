#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9+7;


struct Matrix{
    vector<vector<ll>> a;
    Matrix(int n = 200, int m = 200){
        a = vector<vector<ll>> (n, vector<ll>(m)); ///set every element to 0 by default
    }
    Matrix operator*(const Matrix &other){
        Matrix res(a.size(), other.a[0].size());
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < other.a[0].size(); j++){
                for(int k = 0; k < other.a.size(); k++){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                    if(res.a[i][j] >= 8ll*mod*mod){
                        res.a[i][j] -= 8ll*mod*mod;
                    }
                }
                res.a[i][j] %= mod;
            }
        }
        return res;
    }
};

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,Q;
    cin >> n  >> m >> Q;

    Matrix mat[30];
    for(int i = 0; i < 30; i++){
        mat[i] = Matrix(n, n);
    }
    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        mat[0].a[u-1][v-1] = 1;
        //cout << mat[0].a[u-1][v-1] << "\n";
    }
    for(int i = 1; (1<<i) <= 1e9; i++){
        //cout << "SZ : " << mat[i-1].a.size() << " " << mat[i-1].a[0].size() << "\n";
        mat[i] = (mat[i-1])*(mat[i-1]);
        //cout << "I : " << i << "\n";
    }

    while(Q--){
        int u,v,K; cin >> u >> v >> K;
        Matrix res(1, n);
        res.a[0][u-1] = 1;
        for(int i = 0; K; K /= 2, i++){
            if(K&1){
                res = res*mat[i];
                //cout << "I : " << i << "\n";
            }
        }
        cout << res.a[0][v-1] << "\n";
    }
    return 0;
}
