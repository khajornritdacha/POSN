#include<bits/stdc++.h>
using namespace std;
int n,a[110],dp[110];
int solve(int i){
    if(i<=0)
        return 0;
    if(dp[i]!=0)
        return dp[i];
    return dp[i] = max(solve(i-1),solve(i-2))+a[i];
}
main(){
    freopen("ladder.in","r",stdin);
    freopen("ladder.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    cout << solve(n);
}
