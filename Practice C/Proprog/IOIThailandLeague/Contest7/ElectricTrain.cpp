#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,K,dp[N],a[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i] = 1e9;
    }
    dp[n+1] = 1e9;
    for(int i=1; i<=n+1; i++){
        //cout << "NOW : " << i << " ->\n";
        for(int j=1; j <= K and j <= i; j++){
            //cout << j << " " << i-j << " " << dp[i-j] << " " << j*j << " " << a[i] << "\n";
            dp[i] = min(dp[i-j]+(j)*(j)+a[i], dp[i]);
        }
        //cout << "DP : " << dp[i] << "\n";
    }
    cout << dp[n+1];
}
