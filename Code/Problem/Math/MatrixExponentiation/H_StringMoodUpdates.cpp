#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

int n,Q;
ll mod = 1e9+7;
char in[N];

struct Matrix{
    ll a[2][2] = {};
    Matrix operator*(const Matrix &other){
        Matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    res.a[i][j] += a[i][k]*other.a[k][j];
                    if(res.a[i][j] >= 8ll*mod*mod)
                        res.a[i][j] -= 8ll*mod*mod;
                }
                res.a[i][j] %= mod;
            }
        }
        return res;
    }

    void init(char ch){
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
        for(char it = 'A'; it <= 'Z'; it++){
            if(ch == '?' or ch == it){
                if(it == 'H'){
                    a[0][0]++;
                    a[1][0]++;
                }
                else if(it == 'S' or it == 'D'){
                    a[0][1]++;
                    a[1][1]++;
                }
                else if(it == 'A' or it == 'E' or it == 'I' or it == 'O' or it == 'U'){
                    a[0][1]++;
                    a[1][0]++;
                }else{
                    a[0][0]++;
                    a[1][1]++;
                }
            }
        }
    }
};

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> in[i];
    }
    int BASE = 1;
    while(BASE < n) BASE *= 2;

    vector<Matrix> seg(2*BASE);

    for(int i = 1; i <= n; i++){
        seg[BASE+i-1].init(in[i]);
    }
    for(int i = n+1; i <= BASE; i++){
        seg[BASE+i-1].init('Z'); ///Nothing change if we append Z to the end
    }
    for(int i = BASE-1; i >= 1; i--){
        seg[i] = seg[i<<1]*seg[i<<1|1];
    }
    cout << seg[1].a[0][0] << "\n";
    //pri();
    while(Q--){
        int idx;
        char ch;
        cin >> idx >> ch;
        in[idx] = ch;
        seg[BASE+idx-1].init(in[idx]);
        for(int i = (idx+BASE-1)/2; i >= 1; i /= 2){
            seg[i] = seg[i<<1]*seg[i<<1|1];
        }
        cout << seg[1].a[0][0] << "\n";
        //pri();
    }
    return 0;
}
