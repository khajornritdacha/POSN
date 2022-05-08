#include<bits/stdc++.h>
using namespace std;

const int N = 2e2+5;
int n,m,L,K,mod=2011,a[N][N],dp[N][N][105],ans;

main(){
    cin >> n >> m >> L >> K;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    dp[0][L][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<=K; k++){
                if(i+a[i][j] < n){
                    if(j+a[i][j] < m){
                        dp[i+a[i][j]][j+a[i][j]][k] += dp[i][j][k];
                        dp[i+a[i][j]][j+a[i][j]][k] %= mod;
                    }
                    if(j-a[i][j] >= 0){
                        dp[i+a[i][j]][j-a[i][j]][k] += dp[i][j][k];
                        dp[i+a[i][j]][j-a[i][j]][k] %= mod;
                    }
                    dp[i+a[i][j]][j][k+1] += dp[i][j][k];
                    dp[i+a[i][j]][j][k+1] %= mod;
                }
            }
        }
    }


    for(int j=0; j<m; j++){
        for(int k=0; k<=K; k++){
            ans += dp[n-1][j][k];
            ans %= mod;
        }
    }

    cout << ans;
}
