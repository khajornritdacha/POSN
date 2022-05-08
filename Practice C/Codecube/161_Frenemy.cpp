#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n;
long long dp[N][N][4],mod = 1e9+7,ans;
char a[N][N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    dp[1][1][0] = dp[n][1][1] = dp[1][n][2] = dp[n][n][3] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j] == '0')
                continue;
            dp[i][j][0] += dp[i-1][j][0]+dp[i][j-1][0];
            dp[i][j][0] %= mod;
        }
    }
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++){
            if(a[i][j] == '0') continue;
            dp[i][j][1] += dp[i+1][j][1]+dp[i][j-1][1];
            dp[i][j][1] %= mod;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=n; j>=1; j--){
            if(a[i][j] == '0') continue;
            dp[i][j][2] += dp[i-1][j][2]+dp[i][j+1][2];
            dp[i][j][2] %= mod;
        }
    }
    for(int i=n; i>=1; i--){
        for(int j=n; j>=1; j--){
            if(a[i][j] == '0') continue;
            dp[i][j][3] += dp[i+1][j][3]+dp[i][j+1][3];
            dp[i][j][3] %= mod;
        }
    }
    long long tmp;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j] == '0') continue;
            tmp = (dp[i-1][j][0]*dp[i][j-1][1])%mod;
            tmp = (tmp*dp[i][j+1][2])%mod;
            tmp = (tmp*dp[i+1][j][3])%mod;
            ans = (ans+tmp)%mod;
            tmp = (dp[i][j-1][0]*dp[i+1][j][1])%mod;
            tmp = (tmp*dp[i-1][j][2])%mod;
            tmp = (tmp*dp[i][j+1][3])%mod;
            ans = (ans+tmp)%mod;
        }
    }
    cout << ans;
}
