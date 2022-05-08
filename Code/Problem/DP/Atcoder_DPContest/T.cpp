#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,mod = 1e9+7;
    cin >> n;
    char in[n+5];
    for(int i = 2; i <= n; i++) cin >> in[i];
    ll dp[n+5][n+5], qs[n+5] = {};
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            qs[j] = (qs[j-1]+dp[i-1][j])%mod;
        }
        for(int j = 1; j <= i; j++){
            if(in[i] == '<') dp[i][j] = qs[j-1];
            else dp[i][j] = (qs[i-1]-qs[j-1]+mod)%mod;
        }
    }
    ll ans = 0;
    for(int j = 1; j <= n; j++) ans = (ans+dp[n][j])%mod;
    cout << ans << "\n";
    return 0;
}
