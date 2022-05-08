#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using lb = long double;
using ll = long long;

int n;
ll dp[N][2],mod=1e9+7;
vector<int> G[N];

void dfs(int u, int p){
    dp[u][0] = dp[u][1] = 1;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] *= (dp[v][0]+dp[v][1])%mod;
        dp[u][0] %= mod;
        dp[u][1] *= dp[v][0];
        dp[u][1] %= mod;
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1, -1);
    cout << (dp[1][0]+dp[1][1])%mod << "\n";
    /*for(int i = 1; i <= n; i++){
        cout << dp[i][0] << " " << dp[i][1] << "\n";
    }*/
    return 0;
}
