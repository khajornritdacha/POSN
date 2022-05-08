#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;
int n,K,qs[N],dp[N][310],a[N];
///dp(i, k) = min( max(dp(j-1, k-1), sum[j...i]) ); 1<=j<=i
///dp(0, 0) = 0

main(){
    cin >> n >> K;
    memset(dp, 127, sizeof(dp));
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] = qs[i-1]+a[i];
    }
    dp[0][0] = 0;
    for(int k=1; k<=K; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                dp[i][k] = min(dp[i][k], max(dp[j-1][k-1], qs[i]-qs[j-1]));
            }
        }
    }
    cout << dp[n][K];
}
