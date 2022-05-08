#include <bits/stdc++.h>
using namespace std;

const int N = 110, MX = 1e5+10;
using lb = long double;
using ll = long long;

int n,K,a[N];
ll qs[MX],dp[N][MX],mod=1e9+7;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        qs[0] = dp[i-1][0];
        dp[i][0] = dp[i-1][0];
        for(int j = 1; j <= K; j++){
            qs[j] = (qs[j-1]+dp[i-1][j])%mod;
            dp[i][j] = qs[j];
            if(j-a[i]-1 >= 0)
                dp[i][j] = (dp[i][j]-qs[j-a[i]-1]+mod)%mod;
        }
    }
    cout << dp[n][K];
    return 0;
}
