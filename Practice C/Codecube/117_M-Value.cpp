#include<bits/stdc++.h>
using namespace std;
int n,k,t,w[1010],cnt;
bool dp[2][100010];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cnt++;
        int mx = 0;
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            cin >> w[i];
            w[i]%=k;
        }
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<k; j++){
               dp[i%2][(j+w[i])%k] |= dp[(i-1)%2][j];
            }
        }
        for(int i=0; i<k; i++)
            if(dp[n%2][i])
                mx = max(mx,i);
        cout <<"Case #"<< cnt << ": " << mx << " \n";
        memset(dp, 0, sizeof(dp));
    }
}
