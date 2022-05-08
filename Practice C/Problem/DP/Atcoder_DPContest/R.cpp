#include <bits/stdc++.h>
using namespace std;

const int N = 55;
using lb = long double;
using ll = long long;

int n;
ll K,mod = 1e9+7;

struct Matrix{
    ll a[N][N] = {};
    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i = 0; i <  n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
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
    for(int i = 0; i < n; i++) res.a[i][i] = 1;
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    Matrix base;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> base.a[i][j];
        }
    }
    ll ans = 0;
    Matrix tot = expo(base, K);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans = (ans+tot.a[i][j])%mod;
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << base.a[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << ans << "\n";
    return 0;
}
