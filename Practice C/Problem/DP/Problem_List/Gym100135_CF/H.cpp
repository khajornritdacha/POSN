#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
int n,qs[2020][2020],dp[2020][2020],sum;
main(){
    freopen("peacefulsets.in","r",stdin);
    freopen("peacefulsets.out","w",stdout);
    cin >> n;
    qs[0][0] = 1;
    for(int i=1; i<=n; i++)
        qs[0][i] = qs[0][i-1];
    for(int i=1; i<=n; i++){
        for(int j=i; j>=1; j--){
            dp[i][j] += qs[i-j][j/2];
        }
        for(int j=1; j<=n; j++){
            qs[i][j] = qs[i][j-1]+dp[i][j];
        }
    }

    if(DEBUG){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }
    long long sum = 0;
    for(int i=0; i<=n; i++)
        sum += dp[n][i];
    cout << sum << "\n";
}
