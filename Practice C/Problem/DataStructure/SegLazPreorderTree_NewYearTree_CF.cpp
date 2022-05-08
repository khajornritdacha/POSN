#include <bits/stdc++.h>
#define DEBUG true
#define ll long long
using namespace std;

const int N = 4e5+10;

int n,Q,idx[N],af[N],sz[N],laz[4*N],ti,co[N];
ll seg[4*N];
vector<int> G[N];

///https://codeforces.com/contest/620/problem/E

void dfs(int u, int p){
    idx[u] = ++ti;
    af[ti] = u;
    sz[u] = 1;
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void build(int l = 1, int r = n, int node = 1){
    if(l == r){
        return void(seg[node] = (1ll<<co[af[l]]));
    }
    int mid = (l+r)>>1;
    build(l, mid, node<<1), build(mid+1, r, node<<1|1);
    seg[node] = seg[node<<1]|seg[node<<1|1];
    return;
}

void pend(int l, int r, int node){
    if(laz[node] == 0) return;
    seg[node] = 1ll<<laz[node];
    if(l != r){
        laz[node<<1] = laz[node<<1|1] = laz[node];
    }
    laz[node] = 0;
}

void up(int a, int b, int val, int l = 1, int r = n, int node = 1){
    pend(l, r, node);
    if(r < a or l > b) return;
    if(a <= l and r <= b){
        laz[node] = val;
        pend(l, r, node);
        return;
    }
    int mid = (l+r)>>1;
    up(a, b, val, l, mid, node<<1), up(a, b, val, mid+1, r, node<<1|1);
    seg[node] = seg[node<<1]|seg[node<<1|1];
    return;
}

ll ask(int a, int b, int l = 1, int r = n, int node = 1){
    pend(l, r, node);
    if(r < a or l > b) return 0;
    if(a <= l and r <= b) return seg[node];
    int mid = (l+r)>>1;
    return (ask(a, b, l, mid, node<<1) | ask(a, b, mid+1, r, node<<1|1));
}

void update(int u, int c){
    up(idx[u], idx[u]+sz[u]-1, c);
}

int query(int u){
    ll tmp = ask(idx[u], idx[u]+sz[u]-1);
    int cnt = 0;
    for(int i = 63; i >= 0; i--){
        //cout << ((tmp&(1ll << i)) ? 1 : 0);
        if(tmp&(1ll<<i)) cnt++;
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;

    for(int i = 1; i <= n; i++){
        cin >> co[i];
    }

    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, 0);
    build();

    while(Q--){
        int code;
        cin >> code;
        if(code == 1){
            int v,c;
            cin >> v >> c;
            update(v, c);
        }else{
            int v;
            cin >> v;
            cout << query(v) << "\n";
        }
    }
    return 0;
}
