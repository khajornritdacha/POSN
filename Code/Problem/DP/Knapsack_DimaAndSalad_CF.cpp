#include<bits/stdc++.h>
using namespace std;
int n,k,T=2e4,dp[2][40010],a[110],b[110];
main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++){
        cin >> b[i];
        b[i]*=k;
    }
    for(int i=0; i<=1; i++) for(int j=0; j<=4e4; j++) dp[i][j] = -1e9;
    dp[0][T] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1e4; j>=-1e4; j--){
            dp[i%2][T+j] = dp[(i-1)%2][T+j];
            dp[i%2][T+j] = max(dp[i%2][T+j], dp[(i-1)%2][T+j-(a[i]-b[i])]+a[i]);
        }
    }
    if(dp[n%2][T] == 0)
        dp[n%2][T] = -1;
    cout << dp[n%2][T];
}
///https://codeforces.com/contest/366/problem/C
