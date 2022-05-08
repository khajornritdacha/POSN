#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
int ans,cou,E,V,visit[N];
vector<pair<int,int>> vec[N];
bool cyc[N];
void dfs(int u, int p){
    if(visit[u] == 2)
        return;
    if(visit[u] == 1){
        cyc[u] = true;
        return;
    }
    visit[u] = 1;
    for(auto [v,w] : vec[u]){
        if(v==p || visit[v] == 2) continue;
        dfs(v,u);
        if(cyc[v]){
            cyc[u] = !cyc[u];
            cou+=w;
        }
    }
    visit[u] = 2;
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> E >> V;
    for(int i=1; i<=E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v,w);
        vec[v].emplace_back(u,w);
        ans+=w;
    }
    ans*=2;
    dfs(0, -1);
    cout << ans-cou << "\n";
}
