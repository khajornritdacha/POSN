#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 2e4+10;
int len,n,m,a[N],dp[N][2],p[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> len >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i][0] = -1e18;
    }
    for(int i=1; i<=m; i++){
        cin >> p[i];
    }

    for(int k=1; k<=m-1; k++){
        int cur = k%2, pre = (k-1)%2;
        int mx = dp[k-1][pre]-p[k]*a[k-1];
        dp[k-1][cur] = -1e18;
        for(int i=k; i<=n; i++){
            dp[i][cur] = mx+p[k]*a[i];
            mx = max(mx, dp[i][pre]-p[k]*a[i]);
        }

        if(DEBUG){
            cout << "NOW : " << k << "\n";
            for(int i=1; i<=n; i++){
                cout << dp[i][cur] << " ";
            }
            cout << "\n";
        }
    }

    int ans = -1e18;
    for(int i=m-1; i<=n; i++){
        ans = max(ans, dp[i][(m-1)%2]+p[m]*(len-a[i]));
    }
    cout << ans;
}
