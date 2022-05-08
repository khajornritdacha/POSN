#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e5+10;
int dp[mxn],V;
vector<pair<int,int>> vec[mxn];
int dfs(int u, int p){
    if(dp[u]!=0)
        return dp[u];
    for(auto [v,w] : vec[u]){
        if(v==p) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v]+w);
    }
    return dp[u];
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V;
    for(int i=1; i<V; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
    }
    cout << dfs(1,-1);
}
