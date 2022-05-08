#include<bits/stdc++.h>
using namespace std;
int n,dp[105][105];
pair<int,int> m[105];
int solve(int i, int j){
    if(dp[i][j]!=0)
        return dp[i][j];
    if(i==j)
        return 0;
    int mn=2e9;
    for(int k=i; k<j; k++){
        mn=min(mn,solve(i,k)+solve(k+1,j)+m[i].first*m[k].second*m[j].second);
    }
    return dp[i][j]=mn;
}
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        m[i]={x,y};
    }
    //cout << solve(1,n);
    for(int i=n; i>=1; i--){
        for(int j=i+1; j<=n; j++){
            int mn=2e9;
            for(int k=i; k<j; k++){
                mn=min(mn,dp[i][k]+dp[k+1][j]+m[i].first*m[k].second*m[j].second);
            }
            dp[i][j]=mn;
        }
    }
    cout << dp[1][n];
}
