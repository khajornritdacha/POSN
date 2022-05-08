#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

ll mod = 1e9+7,dp[N][2];

int main(void){
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= 1e6; i++){
        dp[i][0] = (dp[i-1][0]*4 + dp[i-1][1])%mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2)%mod;
    }

    int Q; cin >> Q;
    while(Q--){
        int n; cin >> n;
        cout << (dp[n][0]+dp[n][1])%mod << "\n";
    }
    return 0;
}
