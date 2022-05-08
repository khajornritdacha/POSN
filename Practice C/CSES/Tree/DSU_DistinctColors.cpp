#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int pa[N],ans[N],n,co[N];
set<int> ss[N];
vector<int> vec[N];
///https://cses.fi/problemset/task/1139
///join smaller to bigger one
int fi(int x){
    if(pa[x] == x) return x;
    return pa[x] = fi(pa[x]);
}

void uni(int u, int v){
    int hu = fi(u), hv = fi(v);
    if(hu == hv) return;
    pa[hv] = hu;
    for(int s : ss[hv])
        ss[hu].insert(s);
    return;
}

void dfs(int u, int p){
    int mx = u;
    for(int v : vec[u]){
        if(v == p) continue;
        dfs(v, u);
        if(ss[fi(v)].size() > ss[fi(mx)].size())
            mx = v;
    }

    //cout << "U : " << u << " " << mx << "\n";

    vec[u].emplace_back(u);
    for(int v : vec[u]){
        if(mx == v or v == p) continue;
        uni(mx, v);
    }
    ans[u] = ss[fi(mx)].size();
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> co[i];
        pa[i] = i;
        ss[i].insert(co[i]);
    }
    for(int i=1; i<n; i++){
        int u,v; cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    dfs(1, -1);
    for(int i=1; i<=n; i++){
        cout << ans[i] << " \n"[i==n];
    }
}
