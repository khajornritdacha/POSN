#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,K,dp[N][N],cnt,qs[N][N],qsr[N][N];
long long mod=1e9+7;
bool vi[N][N];
main(){
    cin >> n >> K;
    for(int i=n; i>=0; i--){
        for(int j=n; j>=0; j--){
            for(int r1=i+1; r1<=n; r1++){
                for(int r2=r1+1; r2<=n and r2-r1<=K; r2++){
                    dp[i][j] = (dp[i][j]+(n-j+qs[r2][n]-qs[r2][j])%mod+mod)%mod;
                }
            }
            for(int c1=j+1; c1<=n; c1++){
                for(int c2=c1+1; c2<=n and c2-c1<=K; c2++){
                    dp[i][j] = (dp[i][j]+n-i+(qsr[i+1][c2])%mod)%mod;
                }
            }
            qsr[i][j] = (dp[i][j]+qsr[i+1][j])%mod;
        }
        qs[i][0]=dp[i][0];
        for(int j=1; j<=n; j++){
            qs[i][j] = (dp[i][j]+qs[i][j-1])%mod;
        }
    }
    cout << dp[0][0];
}
