#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, seg[4*N], Q, ti, tin[N], tout[N], ans[N];
vector<int> G[N], mem[N];
vector<pair<int,int>> qq[N];

template<class T>
class Seg{
    vector<T> seg;
    T IV; //invalid or initial value
    T comb(T a, T b){ return a+b; } //combine function
    public:
    Seg(int n, T iv = 0){ IV = iv; seg.resize(4*n+10, iv); }

    void up(int idx, int val, int l = 1, int r = n, int node = 1){
        if(l == r){ return void(seg[node] = val); }
        int mid = (l+r)>>1;
        if(idx <= mid) up(idx, val, l, mid, node<<1);
        else up(idx, val, mid+1, r, node<<1|1);
        seg[node] = comb(seg[node<<1], seg[node<<1|1]);
    }

    int ask(int a, int b, int l = 1, int r = n, int node = 1){
        if(a > b or b < l or r < a) return IV;
        if(a <= l and r <= b) return seg[node];
        int mid = (l+r)>>1;
        return comb(ask(a, b, l, mid, node<<1), ask(a, b, mid+1, r, node<<1|1));
    }
};

void dfs(int u, int dep = 0){
    tin[u] = ++ti;
    mem[dep].emplace_back(u);
    for(int v : G[u]) dfs(v, dep+1);
    tout[u] = ti;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    Seg<int> seg(n, 0);
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        G[p].emplace_back(i);
    }
    cin >> Q;
    for(int i = 1; i <= Q; i++){
        int u, d; cin >> u >> d;
        qq[d].emplace_back(u, i);
    }

    dfs(1);

    for(int id = 0; id < n; id++){
        for(int u : mem[id]) seg.up(tin[u], 1);
         
        for(auto [U, idx] : qq[id]) ans[idx] = seg.ask(tin[U], tout[U]);
        
        for(int u : mem[id]) seg.up(tin[u], 0);
    }

    for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";   

    return 0;
}