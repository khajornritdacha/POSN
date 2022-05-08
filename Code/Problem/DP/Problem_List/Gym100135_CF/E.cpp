#include<bits/stdc++.h>
using namespace std;
int n,a[110][110],mx=-1e9,dp[110][110];
main(){
    //freopen("slalom.in","r",stdin);
    //freopen("slalom.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dp[i][j] = -1e9;
    dp[1][1] = a[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+a[i][j];
        }
    }
    for(int i=1; i<=n; i++)
        mx = max(mx, dp[n][i]);
    cout << mx << "\n";
}
