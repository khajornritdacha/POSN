#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 2e5+10, LOG = 25;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int, int, int>;

///https://codeforces.com/problemset/problem/231/E

int disc[N],low[N],ti,scc_num,scc_id[N],dep[N],cnt_scc[N][LOG],n,m,pa[N][LOG];
ll pw[N],mod = 1e9+7;
bool inST[N],is_cycle[N];
vector<int> rG[N];
set<int> sG[N];
vector<pi> redge;
stack<int> st;

void SCC(int u, int p){
    disc[u] = low[u] = ++ti;
    inST[u] = true;
    st.push(u);
    for(int v : rG[u]){
        if(v == p) continue;
        if(!disc[v]){
            SCC(v, u);
            low[u] = min(low[u], low[v]);
        }else if(inST[v]){
            low[u] = min(low[u], disc[v]);
        }
    }

    if(!st.empty() and low[u] == disc[u]){
        scc_num++;
        int sz = 0;
        while(true){
            int now = st.top(); st.pop();
            scc_id[now] = scc_num;
            inST[now] = false;
            sz++;
            if(now == u) break;
        }

        if(sz > 1)
            is_cycle[scc_num] = true;
    }
}

void dfs(int u, int p){
    if(DEBUG) cout << "DFS : " << u << " " << p << "\n";
    for(int v : sG[u]){
        if(v == p) continue;
        dep[v] = dep[u]+1;
        pa[v][0] = u;
        cnt_scc[v][0] = is_cycle[v];
        dfs(v, u);
    }
}

ll lca(int u, int v){
    if(dep[v] > dep[u]){ swap(u, v); }
    int res = 0; ///number of cycle
    for(int k = LOG-1; k >= 0; k--){
        if(dep[pa[u][k]] >= dep[v]){
            res += cnt_scc[u][k];
            u = pa[u][k];
        }
    }

    //cout << u << " " << " " << v << " " << res << "\n";
    if(u == v) return res+is_cycle[v];

    for(int k = LOG-1; k >= 0; k--){
        if(pa[u][k] != pa[v][k]){
            res += cnt_scc[u][k]+cnt_scc[v][k];
            u = pa[u][k];
            v = pa[v][k];
        }
    }
    return res+cnt_scc[u][0]+cnt_scc[v][0]+is_cycle[pa[u][0]];
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        rG[u].emplace_back(v);
        rG[v].emplace_back(u);
        redge.emplace_back(u, v);
    }

    pw[0] = 1;
    for(int i = 1; i <= n; i++){
        pw[i] = (pw[i-1]*2)%mod;
    }

    SCC(1, -1);

    for(auto [u, v] : redge){
        if(scc_id[u] != scc_id[v]){
            sG[scc_id[u]].insert(scc_id[v]);
            sG[scc_id[v]].insert(scc_id[u]);
        }
    }

    dep[1] = 1;
    dfs(1, -1);

    for(int k = 1; k < LOG; k++){
        for(int i = 1; i <= scc_num; i++){
            pa[i][k] = pa[pa[i][k-1]][k-1];
            cnt_scc[i][k] = cnt_scc[i][k-1]+cnt_scc[pa[i][k-1]][k-1];
        }
    }

    if(DEBUG){
        cout << scc_num << "\n";
        for(int i = 1; i <= n; i++){
            cout << scc_id[i] << " \n"[i==n];
        }
    }

    int Q; cin >> Q;
    while(Q--){
        int u, v; cin >> u >> v;
        if(scc_id[u] == scc_id[v]){
            cout << 2 << "\n";
            continue;
        }
        int res = lca(scc_id[u], scc_id[v]);

        //cout << res << " " << del << "\n";

        cout << pw[res] << "\n";
    }
    return 0;
}
