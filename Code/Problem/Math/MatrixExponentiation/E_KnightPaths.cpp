#include <bits/stdc++.h>
#define un unsigned int
using namespace std;

const int N = 65;

///No need for modulo because of unsigned int overflow

struct Matrix{
    vector<vector<un>> a = vector<vector<un>>(N, vector<un>(N));
    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<N; k++){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                }
            }
        }
        return res;
    }
};

Matrix expo(Matrix base, un pw){
    Matrix res;
    for(int i=0; i<N; i++) res.a[i][i] = 1;
    while(pw){
        if(pw&1){
            res = res*base;
        }
        base = base*base;
        pw /= 2;
    }
    return res;
}

bool inside(int r, int c){
    return (0 <= min(r, c) and max(r, c) < 8);
}

int main(void){
    un K;
    cin >> K;
    Matrix base;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            for(int dr : {-2,-1,1,2}){
                for(int dc : {-2,-1,1,2}){
                    if(abs(dr) == abs(dc)) continue;
                    int gr = i+dr, gc = j+dc;
                    if(inside(gr, gc)){
                        base.a[gr*8+gc][i*8+j] = 1;
                    }
                }
            }
            base.a[i*8+j][64] = 1;
        }
    }
    base.a[64][64] = 1;
    cout << expo(base, K+1).a[0][64] << "\n";
    return 0;
}
