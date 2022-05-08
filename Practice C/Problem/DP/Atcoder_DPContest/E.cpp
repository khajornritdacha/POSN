#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,W;
    cin >> n >> W;
    vector<ll> w(n+1), v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    vector<ll> dp(100000+1, 1e18);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 100000; j >= v[i]; j--){
            dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    int ans = 0;
    for(int j = 0; j <= 100000; j++){
        if(dp[j] <= W) ans = j;
    }
    cout << ans << "\n";
    return 0;
}
