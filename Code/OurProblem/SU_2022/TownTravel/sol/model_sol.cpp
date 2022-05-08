#include <bits/stdc++.h>
using namespace std;


#define all(x) x.begin(), x.end()


typedef tuple<int, int, int> tu3;
typedef tuple<int, int, int, int> tu4;

int N, M, Q;
vector<int> par;
vector<tu3> edges;
vector<tu4> qq;

int fi(int x) {
    return par[x] = (par[x] == x) ? x : fi(par[x]);
}

void uni(int u, int v) {
    u = fi(u), v = fi(v);
    par[v] = u;
}

bool same(int u, int v) {
    return (fi(u) == fi(v));
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;
    par.resize(N);
    for (int i = 0; i < N; i++) par[i] = i;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    for (int i = 0; i < Q; i++) {
        int u, v, w; cin >> u >> v >> w;
        qq.emplace_back(w, u, v, i);
    }

    sort(all(edges));
    sort(all(qq));

    vector<int> ans(Q);
    for (int i = 0, ptr = 0; i < Q; i++) {
        auto [k, u, v, idx] = qq[i];
        while (ptr < M and get<0>(edges[ptr]) <= k) {
            uni(get<1>(edges[ptr]), get<2>(edges[ptr]));
            ptr++;
        }

        ans[idx] = same(u, v);
    }

    for (int i = 0; i < Q; i++) cout << (ans[i] ? "Yes" : "No") << "\n";

    return 0;
}