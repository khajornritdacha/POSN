#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n,m;
bool vi[N];
vector<int> order,G[N];

void topo(int u){
    if(vi[u]) return;
    vi[u] = true;
    for(int v : G[u]){
        topo(v);
    }
    order.emplace_back(u);
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(!vi[i])
            topo(i);
    }
    reverse(order.begin(), order.end());
    vector<int> dp(n+1);
    int mx = 0;
    for(int u : order){
        for(int v : G[u]){
            dp[v] = max(dp[v], dp[u]+1);
            mx = max(mx, dp[v]);
        }
    }
    cout << mx << "\n";
    return 0;
}
