#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
int T=10000;
int n,w[110],sum,ans=2e9;
bool dp[110][20010];
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> w[i];
        sum+=w[i];
    }
    dp[0][T]=1;
    for(int i=1; i<=n; i++){
        for(int j=n/2; j>=1; j--){
            for(int k=20000; k>=w[i]; k--){
                dp[j][k] |= dp[j-1][k-w[i]];

                if(DEBUG && dp[j][k]){
                    cout << i << " " << j << " " << k-T << "\n";
                }

            }
        }
    }
    for(int k=20000; k>=0; k--){
        if(dp[n/2][k]){
            //cout << k-T << " ";
            int ano=k-T;
            ano=sum-ano;
            int now=k-T;
            ans=min(abs(now-ano),ans);
        }
    }
    cout << ans;
}
