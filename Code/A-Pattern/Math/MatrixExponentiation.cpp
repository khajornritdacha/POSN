#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod = 1e9+7;

///Fibonacci by Errichto
///https://codeforces.com/gym/102644/problem/C

struct Matrix{
    ll a[2][2] = {{0, 0}, {0,0}};
    Matrix operator *(const Matrix &other){
        Matrix res;
        for(int i : {0, 1}){
            for(int j : {0, 1}){
                for(int k : {0, 1}){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

Matrix expo_power(Matrix base, ll n){
    Matrix res;
    for(int i=0; i<2; i++) res.a[i][i] = 1;
    while(n){
        if(n&1){
            res = res*base;
        }
        base = base*base;
        n /= 2;
    }
    return res;
}

int main(void){
    ll n;
    cin >> n;
    Matrix tot;
    tot.a[0][0] = 0;
    tot.a[0][1] = 1;
    tot.a[1][0] = 1;
    tot.a[1][1] = 1;
    Matrix ans = expo_power(tot, n);
    cout << ans.a[1][0] << "\n"; ///a*a[0][0] + b*a[1][0] but a = 0, b = 1

    /*a = 0, b = 1;
    for(int i=2; i<=n+1; i++){
        new_a = a[0][0]*a + a[1][0]*b; /// f(n)
        new_b = a[0][1]*a + a[1][1]*b; /// f(n+1)
    }*/

    return 0;
}
