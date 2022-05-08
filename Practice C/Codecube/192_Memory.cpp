#include <bits/stdc++.h>
using namespace std;

const int N = 5010, INF = 1e9;

int n,m,K,A[N],B[N],dp[2][N],mn[N];

/*
Base case:
    dp(0, 0) = 0
    dp(i, 0) = 1
    dp(0, j) = j
Recurrence:
    dp(i, j) = dp(i-1, j-1) ; A[i] == B[j]
    dp(i, j) = min( dp(i-1, j-1)+1, dp(i, j-1)+1, dp(i-k, j)+1)
*/

int main(void){
    cin >> n >> m >> K;
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int j = 1; j <= m; j++) cin >> B[j];

    dp[0][0] = 0;
    for(int j = 1; j <= m; j++) dp[0][j] = mn[j] = j;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cur = i&1;
        dp[cur][0] = mn[0] = 1; ///Second type

        for(int j = 1; j <= m; j++){
            dp[cur][j] = INF;
            if(A[i] == B[j]) ///Same
                dp[cur][j] = dp[1-cur][j-1];

            dp[cur][j] = min({dp[cur][j], ///Current minimum
                             dp[1-cur][j-1] + 1, ///First
                             mn[j] + 1, ///Second
                             dp[cur][j-1] + 1}); ///Third type

            mn[j] = min(mn[j], dp[cur][j]); ///track current min for j-th column

            if(dp[cur][j] <= K)
                ans = max(ans, j);
        }
    }

    cout << ans << "\n";
    return 0;
}
