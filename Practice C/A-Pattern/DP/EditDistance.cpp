#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[1005][1005];
main(){
    cin >> a >> b;
    int n=a.size();
    int m=b.size();
    for(int i=0;i<=n;i++){
        dp[0][i] = i;
    }
    for(int j=0;j<=m;j++){
        dp[j][0] = j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[n][m];
}
