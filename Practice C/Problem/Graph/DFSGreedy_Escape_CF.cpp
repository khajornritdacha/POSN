//https://codeforces.com/contest/1611/problem/E2
//greedily count the number of nodes that is nearest to the root
//answer will be -1 if there exists such a subtree that the time reached by friends is greater than that by root

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+10, N = 2e5+10;

int mn[N], dep[N], n, K, ans;
bool in[N], ok;
vector<int> G[N];

void dfs1(int u, int p){
    if(in[u]) mn[u] = 0;
    for(int v : G[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        mn[u] = min(mn[u], mn[v]+1);
    }
}

void dfs2(int u, int p){
    if(mn[u] <= dep[u]){
        ans++;
        return;
    }
    if(mn[u] == INF){
        ok = false;
        return;
    }

    for(int v : G[u]){
        if(v == p) continue;
        dfs2(v, u);
    }  
}

void TC(){
    ok = true;
    cin >> n >> K;
    
    dep[1] = 0;
    ans = 0;
    for(int i = 1; i <= n; i++){
        in[i] = false;
        mn[i] = INF;
        G[i].clear();
    }

    for(int i = 1; i <= K; i++){
        int u; cin >> u;
        in[u] = true;
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1);

    if(!ok) ans = -1;
    cout << ans << "\n";

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) TC();

    return 0;
}