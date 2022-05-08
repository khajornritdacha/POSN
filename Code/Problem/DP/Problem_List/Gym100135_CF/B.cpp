#include<bits/stdc++.h>
using namespace std;
int n,a[1010],dp[1010];
char c[1010];
int solve(int i){
    if(i>n)
        return -1e9;
    if(i==n)
        return 0;
    if(dp[i]!=-1e9)
        return dp[i];
    if(c[i] == 'w')
        return dp[i] = -1e9;
    return dp[i] = max({solve(i+1), solve(i+3), solve(i+5)})+(c[i]=='"');
}
main(){
    freopen("lepus.in","r",stdin);
    freopen("lepus.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> c[i];
        dp[i] = -1e9;
    }
    solve(1);
    if(dp[1] < 0)
        dp[1] = -1;
    cout << dp[1] << "\n";
}
