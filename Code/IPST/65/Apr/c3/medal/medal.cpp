#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LOG = 25;
const int MXN = 1e5+10;

int dep[MXN], pa[MXN][LOG];
vector<ll> sum;
vector<int> cost;
vector<vector<int>> G;

void dfs(int u, int p) {
    sum[u] += cost[u];
    for (int v : G[u]) if (v != p) {
        sum[v] = sum[u];
        dep[v] = dep[u] + 1;
        pa[v][0] = u;
        dfs(v, u);
    }
}

void initialize(int N, int Q, std::vector<int> W, std::vector<std::pair<int,int> > R)
{
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        auto [u, v] = R[i];
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    cost = W;
    sum.resize(N);

    dfs(0, -1);
    
    for (int k = 1; k < LOG; k++) for (int i = 0; i < N; i++) pa[i][k] = pa[pa[i][k-1]][k-1];

    return;
}

int LCA(int u, int v) {
    if (dep[v] > dep[u]) swap(u, v);
    for (int k = LOG-1; k >= 0; k--) {
        if (dep[pa[u][k]] >= dep[v]) {
            u = pa[u][k];
        }
    }
    if (u == v) return u;
    for (int k = LOG-1; k >= 0; k--) { 
        if (pa[u][k] != pa[v][k]) {
            u = pa[u][k];
            v = pa[v][k];
        }
    }
    return pa[u][0];
}

long long query(int A, int B, int X)
{
    assert (X == 0);
    int lca = LCA(A, B);
    ll res = sum[A] + sum[B] - 2*sum[lca] + cost[lca];
    return res;
}
