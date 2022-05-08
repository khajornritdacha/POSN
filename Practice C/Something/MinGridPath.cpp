#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;
int a[N][N],dp[N][N][5],n,m;


int solve(int i, int j, int k){
    if(i == 1 and j == 1 and k == 1)
        return a[1][1];
    if(i <= 0 or j <= 0)
        return 2e9;

    if(dp[i][j][k] != 2e9)
        return dp[i][j][k];

    if(k == 0)
        return dp[i][j][k] = min(solve(i-1, j, 2), solve(i, j-1, 2))+a[i][j];
    else if(k == 1)
        return dp[i][j][k] = min(solve(i-1, j, 0), solve(i, j-1, 0))+a[i][j];
    else if(k == 2)
        return dp[i][j][k] = min(solve(i-1, j, 1), solve(i, j-1, 1));
}

main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            for(int k=0; k<3; k++)
                dp[i][j][k] = 2e9;
        }
    }
    cout << solve(n, m, (n+m-1)%3) << "\n";
}
