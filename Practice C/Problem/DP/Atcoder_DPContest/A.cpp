#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> H(n+1), dp(n+1);
    for(int i = 1; i <= n; i++){
        cin >> H[i];
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1]+abs(H[i]-H[i-1]);
        if(i > 2)
            dp[i] = min(dp[i], dp[i-2]+abs(H[i]-H[i-2]));
    }
    cout << dp[n] << "\n";
    return 0;
}
