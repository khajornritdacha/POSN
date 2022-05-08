#include<bits/stdc++.h>
using namespace std;
int a[10][10],dp[10][10];
int solve(int i, int j){
    if(i==8 && j==1)
        return dp[i][j] = 0;
    if(i>8 || j<=0)
        return 1e9;
    if(dp[i][j] != 1e9)
        return dp[i][j];
    return dp[i][j] = min({solve(i+1,j), solve(i+1,j-1), solve(i,j-1)})+a[i][j];
}
main(){
    freopen("king2.in","r",stdin);
    freopen("king2.out","w",stdout);
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cin >> a[i][j];
            dp[i][j] = 1e9;
        }
    }
    dp[8][1] = 0;
    for(int i=8; i>=1; i--){
        for(int j=1; j<=8; j++){
            dp[i][j] += a[i][j];
            dp[i-1][j] = min(dp[i-1][j], dp[i][j]);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
            dp[i-1][j+1] = min(dp[i-1][j+1], dp[i][j]);
        }
    }
    cout << dp[1][8] << "\n";
    /*for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }*/
}
