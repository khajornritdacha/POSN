#include<bits/stdc++.h>
using namespace std;
int r,c,dp[55][55];
int solve(int i, int j){
    if(i<=0 || j<=0)
        return 0;
    if(dp[i][j] != -1e9)
        return dp[i][j];
    return dp[i][j] = solve(i-2,j-1)+solve(i-1,j-2);
}
main(){
    freopen("knight.in","r",stdin);
    freopen("knight.out","w",stdout);
    cin >> r >> c;
    for(int i=1; i<=r; i++) for(int j=1; j<=c; j++) dp[i][j] = -1e9;
    dp[1][1] = 1;
    cout << solve(r,c) << "\n";
}
