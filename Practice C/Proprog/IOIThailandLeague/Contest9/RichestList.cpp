#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int dp[N],a[N],n,mx;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i] = max(dp[i-1]+a[i], a[i]);
        mx = max(mx, dp[i]);
    }
    cout << mx;
}
