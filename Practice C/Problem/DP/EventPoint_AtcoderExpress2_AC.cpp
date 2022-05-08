#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 510;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<ll, int, int>;

int n,m,Q,qs[N][N];

///https://atcoder.jp/contests/abc106/tasks/abc106_d

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> Q;
    for(int i = 1; i <= m; i++){
        int l, r; cin >> l >> r;
        qs[l][r]++;
    }

    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j++){
            qs[i][j] += qs[i+1][j]+qs[i][j-1]-qs[i+1][j-1];
        }
    }

    for(int i = 1; i <= Q; i++){
        int l, r; cin >> l >> r;
        cout << qs[l][r] << "\n";
    }
    return 0;
}
