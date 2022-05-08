#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int n,R,K,a[405],ans;
pi dp[405][405];
pi operator+(const pi a, const pi b){
    if(a.second+b.second>K)
        return pi(a.first+b.first+1,a.second+b.second-K);
    return pi(a.first+b.first,a.second+b.second);
}
main(){
    cin >> R >> K;
    while(R--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i > j)
                    dp[i][j]={0,0};
                else if(i==j)
                    dp[i][j]={1,0};
                else
                    dp[i][j]={1e9,0};
        for(int i=n; i>=1; i--){
            for(int j=i+1; j<=n; j++){
                dp[i][j]=min(dp[i][j],dp[i+1][j]+pi(1,0));
                for(int k=i+1; k<=j; k++){
                    if(a[i]==a[k])
                        dp[i][j]=min(dp[i][j],pi(dp[i+1][k-1].first,1)+dp[k][j]);
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << dp[i][j].first << " ";
            }
            cout << "\n";
        }
        ans=max(ans,dp[1][n].first);
    }
    cout << ans;
}
