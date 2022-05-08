#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10, LOG = 20;
using tu = tuple<int,int,int>;

//http://www.usaco.org/index.php?page=viewproblem2&cpid=842
//for every additional edge it contributes only range from u to lca(u, v) and v to lca(u, v)
//so, we add it when we are at u or v and then remove it at lca(u, v)
//use Small to Large merge to optimize time complexity

int dep[N], n, m, pa[N][LOG], ans[N];
vector<pair<int, int>> G[N];
vector<tu> add[N], rem[N];
set<tu> ss[N];

void dfs1(int u, int p){
    for(auto [v, idx] : G[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        pa[v][0] = u;
        dfs1(v, u);
    }
}

void dfs2(int u, int p){
    int bc = -1;
    for(auto [v, idx] : G[u]){
        if(v != p){
            dfs2(v, u); //dfs before compare maximum

            if(bc == -1 or ss[bc].size() < ss[v].size()) bc = v;

            if(!ss[v].empty()) //get ans
                ans[idx] = get<0>(*ss[v].begin());
        }
    }
    
    if(bc != -1) swap(ss[u], ss[bc]);
    for(auto [v, idx] : G[u]){
        if(v == p or v == bc) continue;
        for(auto it : ss[v]) ss[u].insert(it); //insert edges from small child
        ss[v].clear();
    }

    for(auto it : add[u]) ss[u].insert(it); //insert edges start at u
    for(auto it : rem[u]) ss[u].erase(it); //remove edges end at u
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = LOG-1; k >= 0; k--) if(dep[pa[u][k]] >= dep[v]) u = pa[u][k];
    if(u == v) return u;

    for(int k = LOG-1; k >= 0; k--) if(pa[u][k] != pa[v][k]) u = pa[u][k], v = pa[v][k];
    return pa[u][0];
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
    
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    dep[1] = 1;
    dfs1(1, -1);

    for(int k = 1; k < LOG; k++) for(int i = 1; i <= n; i++) pa[i][k] = pa[pa[i][k-1]][k-1];

    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        if(u > v) swap(u, v);

        int lc = lca(u, v);
        add[u].emplace_back(w, u, v);
        add[v].emplace_back(w, u, v);
        rem[lc].emplace_back(w, u, v);
    }

    dfs2(1, -1);

    for(int i = 1; i < n; i++){
        if(ans[i] == 0) ans[i] = -1;
        cout << ans[i] << "\n";
    }

    return 0;
}