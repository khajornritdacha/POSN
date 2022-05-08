#include<bits/stdc++.h>
using namespace std;
using ll =long long;
ll ans;
int n,k,dp[50010][510];
vector<int> vec[50010];

void dfs(int u, int p){
    dp[u][0] = 1;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
        for(int i=0; i<k; i++){
            ans += (dp[u][i] * dp[v][k-i-1]);
        }
        for(int i=0; i<k; i++)
            dp[u][i+1] += dp[v][i];
    }
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    dfs(1,-1);
    cout << ans << "\n";
}
