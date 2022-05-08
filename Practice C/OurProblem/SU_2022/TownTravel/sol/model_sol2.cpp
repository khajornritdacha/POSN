#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

const int MXN = 1e5+10;

int n, m, Q;
int par[MXN];
vector<array<int, 3>> edges;
vector<array<int, 4>> qq;

int fi(int x) {
    return par[x] = (par[x] == x) ? x : fi(par[x]);
}

void uni(int u, int v) {
    u = fi(u), v = fi(v);
    par[v] = u;
}

int main(void) {
    cin >> n >> m >> Q;
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    for (int i = 0; i < Q; i++) {
        int a, b, k; cin >> a >> b >> k;
        qq.push_back({k, a, b, i});
    }

    sort(all(edges));
    sort(all(qq));

    vector<int> ans(Q);
    for (int i = 0, ptr = 0; i < Q; i++) {
        while (ptr < m and edges[ptr][0] <= qq[i][0]) {
            uni(edges[ptr][1], edges[ptr][2]);
            ptr++;
        }

        ans[qq[i][3]] = (fi(qq[i][1]) == fi(qq[i][2]));
    }

    for (int i = 0; i < Q; i++) cout << (ans[i] ? "Yes" : "No") << "\n";

}