#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6+10;
int n,k,a;
ll qs[maxn],dp[maxn],mx=-1e18;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a;
        qs[i] = qs[i-1]+a;
        dp[i] = max((ll)a, dp[i-1]+a);
    }
    for(int i=k; i<=n; i++){
        mx = max({mx, qs[i]-qs[i-k]+dp[i-k], qs[i]-qs[i-k]});
        //cout << mx << " ";
    }
    cout << mx << "\n";
}
