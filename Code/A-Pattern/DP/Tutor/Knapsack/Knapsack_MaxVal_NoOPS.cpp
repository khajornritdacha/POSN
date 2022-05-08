#include<bits/stdc++.h>
using namespace std;
int n,W,weight[101],val[101];
int dp[101][100010];
main(){
    ///Max val
    cin >> n >> W;
    for(int i=1; i<=n; i++){
        cin >> weight[i];
    }
    for(int i=1; i<=n; i++){
        cin >> val[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=W; j>=weight[i]; j--){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+val[i]);
        }
    }
    cout << dp[n][W];
}
/*
3 5
4 1 2
5 1 4
*/
