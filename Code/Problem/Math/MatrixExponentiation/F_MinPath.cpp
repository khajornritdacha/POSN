#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

using ll = long long;
const int N = 110;

int sz;

struct Matrix{

    ll a[N][N] = {};

    Matrix(){
        for(int i=0; i<sz; i++) for(int j=0; j<sz; j++) a[i][j] = 2e18;
    }

    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                for(int k=0; k<sz; k++){
                    if(a[i][k] == 2e18 or other.a[k][j] == 2e18) continue;
                    res.a[i][j] = min(res.a[i][j], a[i][k]+other.a[k][j]);
                }
            }
        }
        return res;
    }
};

Matrix expo(Matrix base, ll pw){
    Matrix res;
    for(int i=0; i<sz; i++) for(int j=0; j<sz; j++) res.a[i][j] = 0;
    while(pw){
        if(pw&1){
            res = res*base;
        }
        base = base*base;
        pw /= 2;
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,K;
    cin >> n >> m >> K;
    sz = n;
    Matrix base;
    //for(int i=0; i<sz; i++) for(int j=0; j<sz; j++) cout << base.a[i][j] << " ";
    for(int i=1; i<=m; i++){
        int u,v,w; cin >> u >> v >> w;
        u--, v--;
        base.a[u][v] = w;
    }
    base = expo(base, K);

    ll ans = 2e18;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) ans = min(ans, base.a[i][j]);
    if(ans == 2e18){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << ans << "\n";
    }

    if(DEBUG){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << base.a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
