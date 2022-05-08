#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
int K,n,dp[N][N];

///dp(K, N) = min( max( dp(K, N-j), dp(K-1, j-1) )+1 ); 1<=j<=N
///dp(K, 0) = 0
///dp(K, 1) = 1
///dp(1, N) = N
///O(K*n^2)
int solve(int k, int i){
    if(i == 0 or i == 1)
        return i;
    if(k == 1)
        return i;
    if(dp[k][i] != 1e9)
        return dp[k][i];
    for(int j=1; j<=i; j++){
        dp[k][i] = min(dp[k][i], max(solve(k, i-j), solve(k-1, j-1))+1);
    }
    return dp[k][i];
}
main(){
    cin >> K >> n;
    for(int i=0; i<=K; i++) for(int j=0; j<=n; j++) dp[i][j] = 1e9;

    cout << solve(K, n) << "\n";
}
