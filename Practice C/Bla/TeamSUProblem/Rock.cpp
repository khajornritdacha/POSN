#include<bits/stdc++.h>
using namespace std;
long long dp[110][110],a[110];
int n;
long long solve(int i, int j){
    if(i>j)
        return 0;
    if(dp[i][j]!=0)
        return dp[i][j];
    if((i+j)%2)
        return dp[i][j]=max(a[i]+solve(i+1,j),a[j]+solve(i,j-1));
    else
        return dp[i][j]=max(solve(i+1,j),solve(i,j-1));
}
main(){
    cin >> n;
    for(int i=1; i<=2*n; i++){
        cin >> a[i];
    }
    solve(1,2*n);
    cout << dp[1][2*n];
}
