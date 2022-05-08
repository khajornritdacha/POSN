#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,dp[10010];
const int MOD = 909091;
main(){
    cin >> n;
    dp[0]=dp[1]=1;
    for(int i=2; i<=n; i++){
        int tmp = 0;
        for(int j=0; j<i; j++){
            tmp += dp[j]*dp[i-j-1];
            tmp %= MOD;
        }
        dp[i]=tmp%MOD;
    }
    cout << dp[n]%MOD;
}
