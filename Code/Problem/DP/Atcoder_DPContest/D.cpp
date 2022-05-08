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
    vector<ll> dp(W+1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
