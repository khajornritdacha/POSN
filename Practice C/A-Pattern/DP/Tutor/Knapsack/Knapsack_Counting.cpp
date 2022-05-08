#include<bits/stdc++.h>
using namespace std;
int n,W,weight[1010];
int dp[100010];
main(){
    ///Counting numbers of ways to make sum equal to K
    cin >> n >> W;
    for(int i=1; i<=n; i++){
        cin >> weight[i];
    }
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=W; j>=weight[i]; j--){
            dp[j] += dp[j-weight[i]];
        }
    }
    cout << dp[W];
}
