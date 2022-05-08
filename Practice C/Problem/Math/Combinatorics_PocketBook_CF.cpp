#include <bits/stdc++.h>
using namespace std;

const int N = 110;
using ll = long long;

///https://codeforces.com/problemset/problem/152/C
/// 6 Nov 2021

int n,m,in[N][N],mod=1e9+7;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;
            in[i][j] = c-'A';
        }
    }

    ll ans = 1;
    for(int j = 1; j <= m; j++){
        int cnt[30] = {}, ty = 0;
        for(int i = 1; i <= n; i++){
            if(++cnt[in[i][j]] == 1)
                ty++;
        }
        ans = (ans*ty)%mod;
    }
    cout << ans << "\n";
    return 0;
}
