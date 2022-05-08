#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int dp[2][N],mod=2012,n,K;
main(){
    cin >> n >> K;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        int cur = i%2, pre = (i-1+2)%2;
        for(int k=0; k<=K; k++){
            dp[cur][k] = 0;
            for(int j=0; j<i and k-j>=0; j++){
                dp[cur][k] = (dp[pre][k-j]+dp[cur][k])%mod;
            }
        }
    }
    cout << dp[n%2][K];
}
