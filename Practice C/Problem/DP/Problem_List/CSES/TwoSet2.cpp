#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,dp[510][250010],want,mod=1e9+7;
main(){
    cin >> n;
    want = n*(n+1)/2;
    if(want % 2 != 0){
        cout << 0;
        return 0;
    }
    want/=2;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=want; j++){
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0){
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= mod;
            }
        }
    }

    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=want; j++){
            cout << dp[i][j] << " \n"[j==want];
        }
    }*/
    cout << dp[n-1][want];
}
///https://cses.fi/problemset/task/1093/
