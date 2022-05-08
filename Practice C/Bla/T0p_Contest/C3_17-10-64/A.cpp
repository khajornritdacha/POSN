#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e3+10;

///https://www.hackerrank.com/challenges/lego-blocks/problem

bool vi[N][N];
ll F[N][N],dp[N][N], mod = 1e9+7;

ll solve(int n, int m){
    if(n <= 0) return 0;
    if(n == 1) return (m <= 4) ? 1 : 0;
    if(m == 1) return 1;
    if(vi[n][m]) return dp[n][m];
    vi[n][m] = true;
    ll res = F[n][m];
    for(int i = 1; i < m; i++){
        res -= F[n][i]*solve(n, m-i);
        res %= mod;
        res += mod;
        res %= mod;
    }
    return dp[n][m] = res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    F[1][0] = 1;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 4 and i-j >= 0; j++){
            F[1][i] += F[1][i-j];
            F[1][i] %= mod;
        }
    }
    for(int i = 2; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            F[i][j] = F[1][j]*F[i-1][j];
            F[i][j] %= mod;
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        int n,m; cin >> n >> m;
        cout << solve(n, m) << "\n";
    }
    return 0;
}
