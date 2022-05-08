#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using ll = long long;

ll pa[N][N],mod=1e9+7,lim=1e3;


int main(void){
    for(int i = 0; i <= lim; i++){
        pa[i][0] = 1;
        for(int j = 1; j <= i; j++){
            pa[i][j] = (pa[i-1][j]+pa[i-1][j-1])%mod;
        }
    }
    int Q; cin >> Q;
    while(Q--){
        int n,m; cin >> n >> m;
        cout << pa[n+m][n] << "\n";
    }
    return 0;
}
