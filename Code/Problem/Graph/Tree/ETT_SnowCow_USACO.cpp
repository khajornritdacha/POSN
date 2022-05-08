#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using pi = pair<int,int>;

int n, Q, ti, tin[N], tout[N];
long long lazy[4*N], seg[4*N];
vector<int> G[N];
set<pi> rco[N]; //range for each color

//http://www.usaco.org/index.php?page=viewproblem2&cpid=973

void dfs(int u, int p){
    tin[u] = ++ti;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    tout[u] = ti;
}

void pend(int l, int r, int node){
    seg[node] += 1ll*lazy[node]*(r-l+1);
    if(l != r){
        lazy[node<<1] += lazy[node];
        lazy[node<<1|1] += lazy[node];
    }
    lazy[node] = 0;
}

void up(int a, int b, int val, int l = 1, int r = n, int node = 1){
    pend(l, r, node);
    if(a > b or b < l or a > r) return;
    if(a <= l and r <= b){
        lazy[node] += val;
        pend(l, r, node);
        return;
    }
    int mid = (l+r)>>1;
    up(a, b, val, l, mid, node<<1), up(a, b, val, mid+1, r, node<<1|1);
    seg[node] = seg[node<<1]+seg[node<<1|1];
}

long long ask(int a, int b, int l = 1, int r = n, int node = 1){
    pend(l, r, node);
    if(a > b or b < l or a > r) return 0;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return ask(a, b, l, mid, node<<1)+ask(a, b, mid+1, r, node<<1|1);
}

void chk(int c){ //for debugging
    cout << "\nCHK\n";
    for(auto [x, y] : rco[c]) cout << x << " " << y << "\n";
    cout << "\n";
}

void preup(int u, int c){
    auto it = rco[c].upper_bound(pi(tin[u], INF));
    if(it != rco[c].begin()) it--;
    if((it->first) <= tin[u] and tout[u] <= (it->second)) return; //this subtree already has color c

    while(!rco[c].empty()){
        it = rco[c].upper_bound(pi(tin[u], INF));
        if(it == rco[c].end() or (it->first) > tout[u]) break;
        // cout << "REM : " << it->first << " " << it->second << "\n";
        up(it->first, it->second, -1); //remove existing color c from u's subtree
        rco[c].erase(it);
    }

    up(tin[u], tout[u], 1); //add color c into u's subtree
    rco[c].insert(pi(tin[u], tout[u]));

    // chk(c);

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);

    cin >> n >> Q;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, -1);

    while(Q--){
        int code; cin >> code;
        if(code == 1){
            int u, c; cin >> u >> c;
            preup(u, c);
        } else {
            int u; cin >> u;
            cout << ask(tin[u], tout[u]) << "\n";
        }
    }

    return 0;
}