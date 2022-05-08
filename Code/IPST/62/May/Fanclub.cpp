#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, INF = 1e9;
using pi = pair<int,int>;

int n, A, B, Q, wa[N], pa[N], dep[N], qs[N], id[N], dp[N], order[N], sz;
vector<pi> G[N];
bool in[N];

//dp(i) -> the maximum value from i to its subtree which doesn't coincide with any nodes in path from A to B
//ans = max( dp(j) + qs(j) + dp(i) - qs(i) ); id[st] <= i < j <= id[ed]
//use segtree to compute

struct DATA{
    int ans, mn, mx;
};

DATA seg[4*N];

DATA merge(const DATA &L, const DATA &R){
    DATA res;
    res.ans = max({L.ans, R.ans, L.mn + R.mx});
    res.mn = max(L.mn, R.mn);
    res.mx = max(L.mx, R.mx);
    return res;
}

void up(int idx, int v1, int v2, int l = 1, int r = sz, int node = 1){
    if(l == r){
        seg[node] = {0, v1, v2};
        return;
    }

    int mid = (l+r)>>1;
    if(idx <= mid) up(idx, v1, v2, l, mid, node<<1);
    else up(idx, v1, v2, mid+1, r, node<<1|1);

    seg[node] = merge(seg[node<<1], seg[node<<1|1]);
    return;
}

DATA ask(int a, int b, int l = 1, int r = sz, int node = 1){
    if(a > b or b < l or r < a) return {0, -INF, -INF};
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return merge(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
}

void dfs1(int u, int p){
    for(auto [v, w]: G[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        wa[v] = w;
        pa[v] = u;

        dfs1(v, u);
    }
}

int dfs2(int u, int p){
    int res = 0;
    for(auto [v, w] : G[u]){
        if(v == p or in[v]) continue;
        res = max(res, dfs2(v, u) + w);
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q >> A >> B;
    for(int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dep[A] = 1;
    dfs1(A, -1);

    int cur = B, idx = dep[B];
    sz = dep[B];
    while(true){
        in[cur] = true;
        id[cur] = idx;
        order[idx] = cur;

        if(cur == A) break;
        cur = pa[cur];
        idx--;
    }

    for(int i = 1; i <= sz; i++){
        dp[i] = dfs2(order[i], -1);
        qs[i] = qs[i-1] + wa[order[i]];
        up(i, dp[i] - qs[i], dp[i] + qs[i]);
    }

    for(int i = 1; i <= Q; i++){
        int st, ed; cin >> st >> ed;
        if(id[st] > id[ed]) swap(st, ed);
        cout << ask(id[st], id[ed]).ans << "\n";
    }

    return 0;
}