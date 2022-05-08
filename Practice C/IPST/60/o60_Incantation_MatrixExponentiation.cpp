#include <bits/stdc++.h>
using namespace std;

const int N = 130;
using ll = long long;

int K,C[N];

///I can do it by myself :D
///dp(i, bit) = max( dp(i-1, bit/2)+C(bit), dp(i-1, bit/2+(1<<(K-1)))+C(bit) )
///Change operation of matrix from + and * to max and +

struct Matrix{
    ll a[N][N] = {};
    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i=0; i<(1<<K); i++){
            for(int j=0; j<(1<<K); j++){
                for(int k=0; k<(1<<K); k++){
                    res.a[i][j] = max(res.a[i][j], a[i][k]+other.a[k][j]);
                }
            }
        }
        return res;
    }
    void print(){
        for(int i=0; i<(1<<K); i++){
            for(int j=0; j<(1<<K); j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

Matrix expo(Matrix base, ll n){
    Matrix res;
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n >> K;
    for(int i=0; i<(1<<K); i++){
        cin >> C[i];
    }

    Matrix tot;
    for(int i=0; i<(1<<K); i++){
        tot.a[(i>>1)][i] = tot.a[(i>>1)|(1<<(K-1))][i] = C[i];
    }
    Matrix ans = expo(tot, n-K+1);

    ll res = 0;
    for(int i=0; i<(1<<K); i++) for(int j=0; j<(1<<K); j++) res = max(res, ans.a[i][j]);
    cout << res << "\n";

    return 0;
}
