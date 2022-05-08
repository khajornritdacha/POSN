#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
using ll = long long;

int n, m, K;
ll dp[N][N][2], mod = 1000000007 ;

void add(ll &A, ll x){
    A += x;
    while(A >= mod) A -= mod;
}

int main(void){
    cin >> n >> m >> K;
    dp[1][0][0] = dp[1][0][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int c : {0, 1}){
            dp[i][0][c] = dp[i-1][0][!c];
            //for(int j = 0; j <= K; j++) add(dp[i][0][c], dp[i-1][j][!c]);
            
            for(int j = 1; j <= K; j++){
                add(dp[i][j][c], dp[i-1][j-1][c]);
                add(dp[i][j][c], dp[i-1][j][!c]);
            }
        }
    }

    //assert(m == 1);

    ll ans = 0;
    for(int k = 0; k <= K; k++) add(ans, (dp[n][k][0] + dp[n][k][1]));
    cout << ans << "\n";

    return 0;
}