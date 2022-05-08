#include<bits/stdc++.h>
using namespace std;
int n,W,weight[1010],val[1010];
int dp[100010];
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
            dp[j] = max(dp[j],dp[j-weight[i]]+val[i]);
        }
    }
    cout << dp[W];
}
/*
3 5
4 1 2
5 1 4
*/
