#include<bits/stdc++.h>
using namespace std;
int n,W,weight[1010];
bool dp[100010];
main(){
    ///Is sum equal to K possible?
    ///aka subset sum
    cin >> n >> W;
    for(int i=1; i<=n; i++){
        cin >> weight[i];
    }
    dp[0]=true;
    for(int i=1; i<=n; i++){
        for(int j=W; j>=weight[i]; j--){
            dp[j] |= dp[j-weight[i]];
        }
    }
    cout << dp[W];
}
