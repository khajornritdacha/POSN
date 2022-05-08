#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,K;
    cin >> n >> K;
    vector<int> H(n+1), dp(n+1);
    for(int i = 1; i <= n; i++){
        cin >> H[i];
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = 2e9;
        for(int k = 1; k <= K and i-k >= 1; k++){
            dp[i] = min(dp[i], dp[i-k]+abs(H[i]-H[i-k]));
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
