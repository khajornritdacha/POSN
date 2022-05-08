#include <bits/stdc++.h>
using namespace std;

using lb = long double;
using ll = long long;

///https://codeforces.com/gym/102644/problem/A

struct Matrix{
    lb a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator *(const Matrix &other){
        Matrix res;
        for(int i : {0, 1}){
            for(int j : {0, 1}){
                for(int k : {0, 1}){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                }
            }
        }
        return res;
    }
};

Matrix expo(Matrix base, ll n){
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
    lb P;
    scanf("%lld %LF", &n, &P);
    //cout << n << " " << P << "\n";
    Matrix tot;
    tot.a[0][0] = tot.a[1][1] = 1.0-P;
    tot.a[0][1] = tot.a[1][0] = P;
    //cout << setprecision(10) << fixed << expo(tot, n).a[0][0] << "\n";
    printf("%.10LF\n", expo(tot, n).a[0][0]);
    return 0;
}
