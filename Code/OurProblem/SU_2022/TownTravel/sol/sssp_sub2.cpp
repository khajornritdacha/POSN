#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> pi;


const int INF = 1e9+10;
const int MXN = 2010;

bool vi[MXN][MXN];
vector<pi> G[MXN];


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, Q; cin >> n >> m >> Q;
    vector<vector<int>> dis(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; i++) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        dis[i][i] = 0;
        pq.emplace(0, i);
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            
            if (vi[i][u]) continue;
            vi[i][u] = true;
            
            for (auto [v, w] : G[u]) {
                if (!vi[i][v] and max(dis[i][u], w) < dis[i][v]) {
                    dis[i][v] = max(dis[i][u], w);
                    pq.emplace(dis[i][v], v);
                }
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int a, b, k; cin >> a >> b >> k;
        cout << (dis[a][b] <= k ? "Yes" : "No") << "\n";
    }
}