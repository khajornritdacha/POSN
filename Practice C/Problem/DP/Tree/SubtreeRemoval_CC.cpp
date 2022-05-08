#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> dp;
vector<vector<ll>> vec;
int t,V,a[100010];
ll X;
ll dfs(int u, int p){
    ll ans = 0;
    for(int v : vec[u]){
        if(v==p) continue;
        dfs(v, u);
        ans += max(-X, dp[v]);
    }
    return dp[u] = ans+a[u];
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> V >> X;
        dp.resize(V+1, 0);
        vec.resize(V+1);
        for(int i=1; i<=V; i++){
            cin >> a[i];
        }
        for(int i=1; i<V; i++){
            int u,v;
            cin >> u >> v;
            vec[u].emplace_back(v);
            vec[v].emplace_back(u);
        }
        dfs(1, -1);
        cout << max(-X, dp[1]) << "\n";
        vec.clear();
        dp.clear();
    }
}
