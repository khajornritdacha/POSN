#include <bits/stdc++.h>
using namespace std;

//https://oj.uz/problem/view/NOI17_roadsideadverts

const int N = 5e4+10, LOG = 20;

int dis[N], dep[N], ta[LOG][N], V, Q;
vector<pair<int, int>> G[N];

void dfs(int u, int p){
    for(auto [v, w] : G[u]){
        if(v == p) continue;
        dis[v] = dis[u] + w;
        dep[v] = dep[u] + 1;
        ta[0][v] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = LOG-1; k >= 0; k--) if(dep[ta[k][u]] >= dep[v]) u = ta[k][u];
    if(u == v) return u;
    for(int k = LOG-1; k >= 0; k--) if(ta[k][u] != ta[k][v]) u = ta[k][u], v = ta[k][v];
    return ta[0][u];
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V;
    for(int i = 1; i < V; i++){
        int u, v, w; cin >> u >> v >> w;
        u++, v++;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dep[1] = 1;
    dfs(1, -1);

    for(int k = 1; k < LOG; k++) for(int i = 1; i <= V; i++) ta[k][i] = ta[k-1][ta[k-1][i]];

    cin >> Q;
    while(Q--){
        int arr[10] = {}, cur[10] = {};

        for(int i = 0; i < 5; i++) cin >> arr[i], arr[i]++;
        
        int LC = arr[0], ans = 0;
        for(int i = 1; i < 5; i++) LC = lca(LC, arr[i]); // LC := lca of five nodes

        for(int bit = 1; bit < 32; bit++){ //A | B | C | D | E = A + B + C + D + E - A&B - A&C - ....
            int cnt = 0, res = 0;
            for(int j = 0; j < 5; j++){
                if(bit&(1<<j)){
                    cur[cnt++] = j;
                }
            }

            if(cnt > 1){
                int lc = arr[cur[0]];
                for(int j = 1; j < cnt; j++){
                    lc = lca(lc, arr[cur[j]]);
                }                
                res = dis[lc] - dis[LC];
            } else {
                res = dis[arr[cur[0]]] - dis[LC];
            }

            if(cnt&1){
                ans += res;
            } else {
                ans -= res;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}