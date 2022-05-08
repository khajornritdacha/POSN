#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[1010],mx;
bool dp[4110];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        mx = 0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        dp[0] = 1;
        for(int i=1; i<=n; i++){
                for(int j=4100; j>=0; j--){
                dp[j^a[i]] |= dp[j];
            }
        }
        for(int i=0; i<=4100; i++){
            //cout << "I: " << i << " " << dp[i] << " " << (i^k) << "\n";
            if(dp[i])
                mx = max(mx, (i^k));
        }
        cout << mx << "\n";
        memset(dp, 0, sizeof(dp));
    }
}
