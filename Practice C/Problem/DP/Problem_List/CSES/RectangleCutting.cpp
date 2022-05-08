#include<bits/stdc++.h>
using namespace std;
int a,b,dp[510][510];
int solve(int i, int j){
    if(i == j)
        return 0;
    else if(dp[i][j] != 0)
        return dp[i][j];
    if(i > j)
        dp[i][j] = 1 + solve(i-j, j);
    else
        dp[i][j] = 1 + solve(i, j-i);
    return dp[i][j];
}
main(){
    cin >> a >> b;
    cout << solve(a, b);
}
///https://cses.fi/problemset/task/1744/
