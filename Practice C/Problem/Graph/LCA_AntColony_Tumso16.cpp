#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e5+10, LOG = 25;

///https://beta.programming.in.th/tasks/tumso16_ant

int dep[N],n,Q,pa[N][LOG];
ll dis[N][LOG];
vector<pair<int,int>> G[N];

void dfs(int u, int p){
    //cout << u << " " << p << "\n";
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        dep[v] = dep[u]+1;
        dis[v][0] = w;
        pa[v][0] = u;
        dfs(v, u);
    }
}

ll lca(int u, int v){
    if(dep[v] > dep[u]) swap(u, v);
    ll res = 0;
    for(int k = LOG-1; k >= 0; k--){
        if(dep[pa[u][k]] >= dep[v]){
            res += dis[u][k];
            u = pa[u][k];
        }
    }
    //cout << "CUR : " << u << " " << v << "\n";
    if(u == v) return res;
    for(int k = LOG-1; k >= 0; k--){
        if(pa[u][k] != pa[v][k]){
            res += dis[u][k]+dis[v][k];
            u = pa[u][k];
            v = pa[v][k];
        }
    }
    return res+dis[u][0]+dis[v][0];
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        int v,w; cin >> v >> w;
        v++;
        G[i].emplace_back(v, w);
        G[v].emplace_back(i, w);
    }

    dep[1] = 1;
    dfs(1, -1);

    for(int k = 1; k < LOG; k++){
        for(int i = 1; i <= n; i++){
            pa[i][k] = pa[pa[i][k-1]][k-1];
            dis[i][k] = dis[i][k-1]+dis[pa[i][k-1]][k-1];
            //cout << dis[i][k] << " ";
        }
        //cout << "\n";
    }

    cin >> Q;
    while(Q--){
        int u,v; cin >> u >> v;
        u++, v++;
        cout << lca(u, v) << "\n";
    }
    return 0;
}
