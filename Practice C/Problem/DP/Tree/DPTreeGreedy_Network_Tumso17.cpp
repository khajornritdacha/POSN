#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int ans,n,S,dp[N];
vector<int> G[N];

///https://beta.programming.in.th/tasks/tumso17_network

void dfs(int u, int p){
    vector<int> order;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, u);
        order.emplace_back(dp[v]);
    }
    sort(order.rbegin(), order.rend());
    for(int i = 0; i < order.size(); i++){
        dp[u] = max(dp[u], order[i]+i+1); ///Choose to spread data to childs with maximum dp first will yield an optimal value
    }
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> S;
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(S, -1);
    cout << dp[S] << "\n";
    return 0;
}
