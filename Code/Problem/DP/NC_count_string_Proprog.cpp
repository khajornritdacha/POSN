#include<bits/stdc++.h>
using namespace std;
int lim,cnt,ans,dp[27][5000][27],n,s;
main(){
    while(true){
        cnt++;
        ans=0;
        cin >> n >> s;
        if(n==0&&s==0)
            return 0;
        if(n>26||s<n){ cout << "Case " << cnt << ": 0\n"; continue; }
        lim=(27)*(13);
        if(s>lim){ cout << "Case " << cnt << ": 0\n"; continue; }
        for(int j=1; j<27; j++){
            dp[1][j][j]=1;
        }
        for(int i=2; i<=n; i++){
            for(int j=1; j<=lim; j++){
                for(int k=1; k<27; k++){
                    for(int l=1; l<k; l++){
                        dp[i][j][k]+=dp[i-1][j-k][l];
                    }
                }
            }
        }
        for(int i=1; i<27; i++) ans+=dp[n][s][i];
        cout << "Case " << cnt << ": " << ans << "\n";
        memset(dp,0,sizeof(dp));
    }
}
