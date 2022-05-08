#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int dp[2][N],mod=2012,n,K,qs[2][N];
int gs(int cur, int r, int l){
    if(l<0)
        return qs[cur][r]%mod;
    return ((qs[cur][r]-qs[cur][l])%mod+mod)%mod;
}
///define dp(i, k) = permutation from 1 to i with k cost left
///dp(i, k) = dp(i, k-j) j<=min(i-1, k)
///opt mem and time by mod and quick sum
main(){
    cin >> n >> K;
    qs[0][0] = 1;
    for(int i=1; i<=K; i++)
        qs[0][i] = qs[0][i-1];
    for(int i=1; i<=n; i++){
        int cur = i%2, pre = (i-1)%2;
        dp[cur][0] = qs[cur][0] = qs[pre][0];
        for(int k=1; k<=K; k++){
            dp[cur][k] = gs(pre, k, k-min(i-1,k)-1);
            qs[cur][k] = (qs[cur][k-1]+dp[cur][k])%mod;
        }
    }
    cout << dp[n%2][K];
}
