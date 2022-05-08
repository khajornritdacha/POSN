#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5010;
using pi = pair<int,int>;

///https://codeforces.com/problemset/problem/983/B
///precal for each range
///ans is maximum in each range

unsigned int n,a[N],F[N][N],ans[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        F[i][i] = ans[i][i] = a[i];
    }

    for(int l = n-1; l >= 1; l--){
        for(int r = l+1; r <= n; r++){
            F[l][r] = F[l][r-1]^F[l+1][r];
            ans[l][r] = max({F[l][r], ans[l+1][r], ans[l][r-1]});
        }
    }

    int Q; cin >> Q;
    while(Q--){
        int l,r; cin >> l >> r;
        cout << ans[l][r] << "\n";
    }

    return 0;
}
