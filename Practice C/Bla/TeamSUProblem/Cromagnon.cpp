#include<bits/stdc++.h>
using namespace std;
const int MOD=2009;
int K,n,a[25][25],dp[110][110][25],ipt[110];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            cin >> a[i][j];
        }
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> ipt[i];
        dp[i][i][ipt[i]]++;
    }
    for(int i=n; i>=1; i--){
        for(int j=i+1; j<=n; j++){
            for(int k=i; k<j; k++){
                for(int o1=0; o1<K; o1++){
                    for(int o2=0; o2<K; o2++){
                        dp[i][j][a[o1][o2]]+=(dp[i][k][o1]*dp[k+1][j][o2]);
                        if(dp[i][j][a[o1][o2]]>2009)
                            dp[i][j][a[o1][o2]]%=MOD;
                    }
                }
            }
        }
    }
    if(n<=30){
        for(int i=0; i<K; i++){
            if(dp[1][n][i]>2009)
                dp[1][n][i]%=MOD;
            cout << dp[1][n][i] << "\n";
        }
    }else{
        for(int i=0; i<K; i++){
            if(dp[1][n][i]>=2009)
                dp[1][n][i]%=MOD;
            cout << dp[1][n][i] << "\n";
        }
    }
}
