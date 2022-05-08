#include<bits/stdc++.h>
using namespace std;
int t,dp[100][150];
main(){
    cin >> t;
    while(t--){
        int n,x,p;
        cin >> n >> x >> p;
        int sum=x-(n*p);
        for(int i=0; i<=sum; i++){
            dp[1][i]=1;
            dp[2][i]=i+1;
        }
        for(int i=3; i<=n; i++){
            for(int j=0; j<=sum; j++){
                for(int k=0; k<=j; k++){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
    cout << dp[n][sum] << "\n";
    for(int i=1; i<=n; i++) for(int j=0; j<=sum; j++) dp[i][j]=0;
    }
}
