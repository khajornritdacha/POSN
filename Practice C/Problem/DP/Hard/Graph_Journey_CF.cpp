#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int t,n,dp[N][2],ans[N];
vector<int> vec[N][2];
int solve(int u, bool b, int p){
    if(dp[u][b] != 0)
        return dp[u][b];
    dp[u][b] = 1;
    for(int v : vec[u][b]){
        if(v==p) continue;
        dp[u][b] += solve(v, !b, u);
    }
    return dp[u][b];
}
void dfs(int u, int b, int p){
    for(int v : vec[u][b]){
        if(v==p) continue;
        dp[v][!b] = dp[u][b];
        dfs(v, !b, u);
    }
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            char c;
            cin >> c;
            if(c=='L'){
                vec[i][0].emplace_back(i-1);
                vec[i-1][1].emplace_back(i);
            }else{
                vec[i-1][0].emplace_back(i);
                vec[i][1].emplace_back(i-1);
            }
        }
        for(int u=0; u<=n; u++){
            if(dp[u][0] == 0){
                solve(u, 0, -1);
                dfs(u, 0, -1);
            }
            cout << dp[u][0] << " \n"[u==n];
        }
        for(int i=0; i<=n; i++){
            dp[i][0] = dp[i][1] = 0;
            vec[i][0].clear();
            vec[i][1].clear();
        }
    }
}
///https://codeforces.com/problemset/problem/1476/D
