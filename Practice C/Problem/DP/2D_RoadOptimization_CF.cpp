#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1625/C

const int N = 510, INF = 1e9+10;

int n, L, K, d[N], arr[N], dp[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L >> K;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    n++;
    d[n] = L;

    for(int k = 0; k <= K; k++) for(int i = 0; i <= n; i++) dp[i][k] = INF;
    dp[1][0] = 0;

    for(int i = 2; i <= n; i++){
        for(int k = 0; k <= K; k++){
            dp[i][k] = dp[i-1][k] + (d[i]-d[i-1])*arr[i-1];
            for(int j = 1; j <= k and i-j-1 >= 1; j++){
                if(dp[i-j-1][k-j] >= INF) continue;
                dp[i][k] = min(dp[i][k], dp[i-j-1][k-j] + (d[i]-d[i-j-1])*arr[i-j-1]);
            }
        }
    }

    int ans = INF;
    for(int k = 0; k <= K; k++) ans = min(ans, dp[n][k]);
    cout << ans << "\n";

    return 0;
}