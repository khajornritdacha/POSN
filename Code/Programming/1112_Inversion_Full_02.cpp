#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int n, K, mod = 2012, dp[N][N], qs[N];

int main(void){
    cin >> n >> K;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
        qs[0] = dp[i-1][0];
        for(int j = 1; j <= K; j++){
            qs[j] = (qs[j-1]+dp[i-1][j])%mod;
        }
        for(int j = 1; j <= K; j++){
            dp[i][j] = qs[j]-((j-i >= 0) ? qs[j-i] : 0);
        }
    }
    cout << dp[n][K];
    return 0;
}
