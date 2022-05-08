#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
int V,E,disc[N],low[N],ti,cnt;
vector<pi> ans;
vector<int> vec[N];
///If graph contains bridge it always impossible to direct edge so that it becomes strongly connected.
///Can be solved easily by directing every forward edge to its child and every back edge to its parent
///https://codeforces.com/blog/entry/68138

bool dfs(int u, int p){
    cnt++;
    disc[u] = low[u] = ti++;
    for(int v : vec[u]){
        if(v == p) continue;
        if(disc[v] == -1 or disc[v] < disc[u]) ///disc[v] == -1 for forward edge and disc[v] < disc[u] for back edge
            ans.emplace_back(u, v);
        if(disc[v] != -1){
            low[u] = min(low[u], disc[v]);
        }else{
            if(dfs(v, u))
                return true;
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]){
                //cout << "Bridge : " << v << " " << u << "\n";
                return true;
            }
        }
    }
    return false;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(disc, -1, sizeof(disc));
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }

    bool res = dfs(1, -1);
    if(res or cnt != V){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(auto [u, v] : ans)
        cout << u << " " << v << "\n";
}
