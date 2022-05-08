#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<int> par;

int fi(int x) {
    return par[x] = (par[x] == x) ? x : fi(par[x]);
}

void uni(int u, int v) {
    u = fi(u), v = fi(v);
    par[v] = u;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;
    par.resize(N);
    
    vector<array<int, 2>> edge[2];
    vector<array<int, 3>> qq[2];
    
    for (int i = 0; i < N; i++) par[i] = i; 
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge[w-1].push_back({u, v});
    }

    for (int i = 0; i < Q; i++) {
        int a, b, k; cin >> a >> b >> k;
        qq[k-1].push_back({a, b, i});
    }

    vector<int> ans(Q);
    for (int i = 0; i < 2; i++) {
        for (auto [u, v] : edge[i]) uni(u, v);
        for (auto [a, b, idx] : qq[i]) {
            ans[idx] = (fi(a) == fi(b));
        }
    }

    for (int i = 0; i < Q; i++) cout << (ans[i] ? "Yes" : "No") << "\n";

    return 0;
}