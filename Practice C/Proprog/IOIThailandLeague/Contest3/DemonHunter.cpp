#include<bits/stdc++.h>
using namespace std;
int n,m,dp[(1<<11)][11],a[11][11],tmp[11][11];
bool vi[(1<<11)][11];
int solve(int bit, int lv){
    if(lv == n)
        return 0;
    if(vi[bit][lv])
        return dp[bit][lv];
    vi[bit][lv] = true;
    int tmp = solve(bit, lv+1);
    for(int i=0; i<m; i++){
        if(bit&(1<<i)) continue;
        tmp = max(tmp, solve(bit|(1<<i), lv+1)+a[lv][i]);
    }
    return dp[bit][lv] = tmp;
}
main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    cout << solve(0, 0);
}
