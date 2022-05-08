#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

int n,from[N];
vector<pair<int,int>> G[N];
ll D[N],ans[N],mxs[N],mx2[N];

///Consider 3 cases : 1. From its child 2. From its siblings 3. From its parent
///https://atcoder.jp/contests/abc222/tasks/abc222_f

ll dfs1(int u, int p){
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        ll tmp = max(dfs1(v, u), D[v])+w;
        ans[u] = max(ans[u], tmp); ///Longest path from its child
        if(tmp > mxs[u]){
            swap(tmp, mxs[u]);
            from[u] = v;
        }
        if(tmp > mx2[u]){
            swap(tmp, mx2[u]);
        }
    }
    return ans[u];
}

void dfs2(int u, int p, ll fw, ll mxp){
    ll res = 0;
    res = max(mxp, D[p])+fw; ///Longest path from its parent
    if(from[p] == u) ///Longest path from siblings
        res = max(res, mx2[p]+fw);
    else
        res = max(res, mxs[p]+fw);
    ans[u] = max(ans[u], res);
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        dfs2(v, u, w, res);
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u,v,w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    for(int i = 1; i <= n; i++){
        cin >> D[i];
    }

    dfs1(1, -1);
    dfs2(1, -1, 0, 0);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
