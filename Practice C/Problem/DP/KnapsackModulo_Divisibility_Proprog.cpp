#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t,n,k,a[10010],now;
bool dp[10010][110];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            a[i] = ((a[i])%k + k)%k;
        }
        dp[1][a[1]] = 1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<k; j++){
                now = ((j+a[i])%k+k)%k;
                dp[i][now] |= dp[i-1][j];
                now = ((j-a[i])%k+k)%k;
                dp[i][now] |= dp[i-1][j];
            }
        }
        /*for(int i=0; i<k; i++){
            cout << "I: " << i << " " << dp[n][i] << "\n";
        }*/
        if(dp[n][0])
            cout << "Divisible\n";
        else
            cout << "Not divisible\n";
        memset(dp, 0, sizeof(dp));
    }
}
