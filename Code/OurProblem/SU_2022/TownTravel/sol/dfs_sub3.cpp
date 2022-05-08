#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> pi;


vector<int> cmp;
vector<vector<int>> G;

void dfs(int u, int cnt) {
    cmp[u] = cnt;
    for (int v : G[u]) if (!cmp[v]) dfs(v, cnt);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, Q; cin >> n >> m >> Q;
    
    G.resize(n);
    cmp.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (w == 1) {
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!cmp[i]) {
            dfs(i, ++cnt);
        }
    }

    for (int i = 0; i < Q; i++) {
        int a, b, k; cin >> a >> b >> k;
        if (k == 2 or cmp[a] == cmp[b]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}