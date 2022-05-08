#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    const int INF = 1e9+10;

    int n, m, Q; cin >> n >> m >> Q;
    vector<vector<int>> dis(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }

    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
    }

    for (int i = 0; i < Q; i++) {
        int a, b, k; cin >> a >> b >> k;
        cout << (dis[a][b] <= k ? "Yes" : "No") << "\n";
    }
}