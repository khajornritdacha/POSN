#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
const int N = 1e5+10;
ll ans[N],dp[N];
int V,E,st,pa[N],visit[N];
vector<pi> vec[N];
vector<int> incycle;
bool cyc[N];
void cycle(int u, int p){
    if(visit[u] == 2)
        return;
    if(visit[u] == 1){
        cyc[u] = true;
        st = u;
        return;
    }
    visit[u] = 1;
    for(auto [v,i] : vec[u]){
        if(v==p || visit[v] == 2) continue;
        pa[v] = u;
        cycle(v,u);
        if(cyc[v]){
            cyc[u] = !cyc[u];
        }
    }
    visit[u] = 2;
    return;
}
void dfs(int u, int p){
    dp[u] = 1;
    for(auto [v,i] : vec[u]){
        if(v==p) continue;
        if(cyc[v]) continue;
        dfs(v,u);
        ans[i] = (ll)dp[v]*(V-dp[v]);
        dp[u] += dp[v];
    }
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v,i);
        vec[v].emplace_back(u,i);
    }
    cycle(1, -1);
    cyc[st] = true;
    /*for(int i=1; i<=V; i++){
        cout << cyc[i] << " \n"[i==V];
    }*/
    for(int i=1; i<=V; i++){
        if(cyc[i]){
            dfs(i, -1);
        }
    }
    for(int i=1; i<=E; i++){
        cout << ans[i] << " \n"[i==E];
    }
}
