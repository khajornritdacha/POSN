#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5+10;

typedef long long ll;

int N, M, Q;
bool vi[MXN];
vector<pair<int, int>> G[MXN];


inline void chk(ll x, ll a, ll b) {
    assert(a <= x and x <= b);
}

bool bfs(int st, int ed, ll lim) {
    for (int i = 0; i < N; i++) vi[i] = 0;
    
    queue<int> qq;
    qq.emplace(st);
    while (!qq.empty()) {
        int u = qq.front(); qq.pop();
        vi[u] = true;
        for (auto [v, w] : G[u]) {
            if (!vi[v] and w <= lim) {
                qq.emplace(v);
                vi[v] = true;
            }
        }
    }

    return vi[ed];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        ll k; 
        cin >> a >> b >> k;

        int res = bfs(a, b, k);
        cout << (res ? "Yes" : "No") << "\n";
    }

    return 0;
}