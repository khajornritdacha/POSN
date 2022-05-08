#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, LOG = 20;

//https://cses.fi/problemset/task/1135

int dep[N], pa[N][LOG], n, Q;
vector<int> G[N];

void dfs(int u, int p){
    for(int v : G[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        pa[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = LOG-1; k >= 0; k--){
        if(dep[pa[u][k]] >= dep[v]) u = pa[u][k];
    }
    if(u == v) return u;
    for(int k = LOG-1; k >= 0; k--){
        if(pa[u][k] != pa[v][k]){
            u = pa[u][k], v = pa[v][k];
        }
    }
    return pa[u][0];
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dep[1] = 1;
    dfs(1, -1);

    for(int k = 1; k < LOG; k++){
        for(int i = 1; i <= n; i++){
            pa[i][k] = pa[pa[i][k-1]][k-1];
        }
    }

    while(Q--){
        int u, v; cin >> u >> v;
        cout << dep[u]+dep[v]-2*dep[lca(u, v)] << "\n";
    }

    return 0;
}