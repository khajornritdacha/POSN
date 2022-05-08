#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
int n,m,pa[N],wa[N],dep[N],ans[N];
set<int> ss;
vector<pi> vec[N];
vector<tu> edge(N);


void dfs(int u, int p){
    for(auto [v, w] : vec[u]){
        if(v == p) continue;
        pa[v] = u;
        wa[v] = w;
        dep[v] = dep[u]+1;
        dfs(v, u);
    }
}

int cal(int u, int v){
    int mx = 0;
    if(dep[u] < dep[v]) swap(u, v);
    while(dep[u] > dep[v]){
        mx = max(mx, wa[u]);
        u = pa[u];
    }
    while(u != v){
        mx = max({mx, wa[u], wa[v]});
        u = pa[u];
        v = pa[v];
    }
    return mx;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        if(i <= n-1){
            vec[u].emplace_back(v, w);
            vec[v].emplace_back(u, w);
        }else{
            edge[i] = {u, v, w};
            ss.insert(w);
        }
    }
    dfs(1, -1);

    bool ok = true;
    vector<pi> use;
    for(int i=n; i<=m; i++){
        auto [u, v, w] = edge[i];
        int mx = cal(u, v);
        //cout << "NOW : " << i << " " << mx << "\n";
        use.emplace_back(mx, i);
    }
    sort(use.begin(), use.end());
    for(auto [val, idx] : use){
        auto it = ss.upper_bound(val);
        if(it == ss.end()){ ok = false; break; }
        ans[idx] = *it;
        ss.erase(it);
    }

    cout << ok << "\n";
    if(ok){
        for(int i=n; i<=m; i++){
            cout << ans[i] << "\n";
        }
    }
}
