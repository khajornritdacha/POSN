#include<bits/stdc++.h>
using namespace std;
int n,m,dp[100][100][2];
main(){
    while(1){
        cin >> n >> m;
        if(n<0&&m<0) return 0;
        dp[1][1][1]=1;
        dp[1][0][0]=1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j][0]=dp[i-1][j][1]+dp[i-1][j][0];
                dp[i][j][1]=dp[i-1][j-1][1]+dp[i-1][j][0];
            }
        }
        cout << dp[n][m][0]+dp[n][m][1] << "\n";
        memset(dp,0,sizeof(dp));
    }
}
