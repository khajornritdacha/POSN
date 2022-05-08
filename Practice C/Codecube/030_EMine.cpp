#include<bits/stdc++.h>
using namespace std;

const int N = 5e2+10;
int n,K,a[N][N],mx,dp[2][N][55];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        int cur = i%2, pre = cur^1;
        for(int j=1; j<=n; j++){
            dp[cur][j][0] = max(dp[pre][j][0], dp[cur][j-1][0]);
            for(int k=1; k<=K; k++){
                dp[cur][j][k] = max(dp[pre][j][k-1], dp[cur][j-1][k-1])+a[i][j];
                dp[cur][j][0] = max({dp[cur][j][0], dp[pre][j][k], dp[cur][j-1][k]});
                mx = max({mx, dp[cur][j][k], dp[cur][j][0]});
            }
        }
    }
    cout << mx;
}
