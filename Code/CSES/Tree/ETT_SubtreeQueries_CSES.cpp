#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

//https://cses.fi/problemset/task/1137/
//Euler tour technique

int ti, n, Q, co[N], tin[N], tout[N];
vector<int> G[N];
long long fen[N];

void up(int idx, long long val){
    assert(idx > 0);
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

long long ask(int idx){
    long long res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

void dfs(int u, int p){
    tin[u] = ++ti;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, u);
    }
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
    for(int i = 1; i <= n; i++) up(tin[i], co[i]);

    while(Q--){
        int code; cin >> code;
        if(code == 1){ //up
            int u, cost; cin >> u >> cost;
            up(tin[u], cost-co[u]);
            co[u] = cost;
        } else { //ask
            int u; cin >> u;
            cout << ask(tout[u])-ask(tin[u]-1) << "\n";
        }
    }

    return 0;
}