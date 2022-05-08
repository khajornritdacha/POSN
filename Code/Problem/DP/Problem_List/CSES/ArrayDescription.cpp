#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10, M=1e2+10;
int n,m,a[N],dp[N][M],mod=1e9+7,sum;
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    if(a[1] == 0){
        for(int j=1; j<=m; j++)
            dp[1][j] = 1;
    }else{
        dp[1][a[1]] = 1;
    }
    for(int i=2; i<=n; i++){
        if(a[i] != 0){
            for(int j=-1; j<=1; j++){
                dp[i][a[i]] += dp[i-1][a[i]+j]%mod;
            }
        }else{
            for(int k=1; k<=m; k++){
                for(int j=-1; j<=1; j++){
                    dp[i][k] += dp[i-1][k+j]%mod;
                }
            }
        }
    }
    for(int i=1; i<=m; i++)
        sum += dp[n][i];
    cout << sum%mod << "\n";
}
///dp[i][j] -> i = idx, j = present number
///https://cses.fi/problemset/task/1746/
