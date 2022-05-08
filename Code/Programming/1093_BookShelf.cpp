#include<bits/stdc++.h>
using namespace std;
int n,a[2001],dp[2001][2001];
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        dp[0][i] = max(dp[0][i-1], dp[2][i-1]-a[i]);
        for(int j=1; j<=i; j++){
            dp[j][i] = max(dp[j-1][i-1]+a[i], dp[j+2][i-1]-a[i]);
        }
    }
    cout << dp[0][n] << "\n";
}
