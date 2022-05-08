//https://cses.fi/problemset/task/1138
//https://usaco.guide/gold/tree-euler?lang=cpp

#include <bits/stdc++.h>
using namespace std;

//Range update point query
//For every node u, update its value in range [tin[u], tout[u]]

const int N = 2e5+10;

int tin[N], tout[N], ti, n, Q, co[N];
long long fen[N];
vector<int> G[N];

void up(int idx, long long val){
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

long long ask(int idx){
    long long res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

void dfs(int u, int p){
    tin[u] = ++ti;
    for(int v : G[u]) if(v != p) dfs(v, u);
    tout[u] = ti;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> co[i];
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        up(tin[i], co[i]);
        up(tout[i]+1, -co[i]);
    }

    while(Q--){
        int code; cin >> code;
        if(code == 1){
            int u, val; cin >> u >> val;
            up(tin[u], val-co[u]);
            up(tout[u]+1, -val+co[u]);
            co[u] = val;
        } else {
            int u; cin >> u;
            cout << ask(tin[u]) << "\n";
        }
    }

    return 0;
}