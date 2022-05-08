#include<bits/stdc++.h>
using namespace std;
int t,n,g,ans,p[1010],w[1010],b[110],mx;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> p[i] >> w[i];
        }
        cin >> g;
        for(int i=1; i<=g; i++){
            cin >> b[i];
        }
        for(int i=1; i<=g; i++){
            int dp[b[i]+5];
            mx=0;
            memset(dp,0,sizeof(dp));
            for(int i2=1; i2<=n; i2++){
                for(int j=b[i]; j>=w[i2]; j--){
                    dp[j]=max(dp[j],dp[j-w[i2]]+p[i2]);
                    mx=max(dp[j],mx);
                }
            }
            ans+=mx;
        }
        cout << ans << "\n";
        ans=0;
        memset(p,0,sizeof(p));
        memset(w,0,sizeof(w));
        memset(b,0,sizeof(b));
    }
}
