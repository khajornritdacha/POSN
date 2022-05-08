#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 70;
using ll = long long;

ll a[20],c[20],n,K,P,Q,R;

int main(void){
    cin >> n >> K;
    vector<ll> dp(n+6);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    cin >> P >> Q >> R;

    dp[n] = P, dp[n+1] = Q, dp[n+2] = R, dp[n+3] = n*Q, dp[n+4] = n*R, dp[n+5] = n*n*R;
    for(int seq = n; seq <= K; seq++){
        cout << "N : " << seq << "\n";
        cout << dp[n] << " " << dp[n+3] << " " << dp[n+4] << " " << dp[n+5] << "\n";
        vector<ll> ndp(n+6);
        ndp[n] = dp[n]; ///p
        ndp[n+1] = dp[n+1]; ///q
        ndp[n+2] = dp[n+2]; ///r
        ndp[n+3] = dp[n+3]+dp[n+1]; ///q(i+1) = qi+q
        ndp[n+4] = dp[n+4]+dp[n+2]; ///r(i+1) = ri+r
        ndp[n+5] = dp[n+5]+2*dp[n+4]+dp[n+2]; ///r(i+1)^2 = ri^2+2ri+r

        ndp[n-1] = dp[n]+dp[n+3]+dp[n+5];
        for(int i=0; i<n; i++){
            ndp[n-1] += dp[i]*c[n-i];
        }
        for(int i=0; i<n-1; i++){
            ndp[i] = dp[i+1];
        }
        dp = ndp;
    }
    cout << dp[n-1] << "\n";

    return 0;
}
