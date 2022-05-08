#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
const int N = 1e5+10;
ll ans[N],dp[N];
int V,E,st,pa[N];
vector<pi> vec[N];
vector<int> incycle;
bool cyc[N],visit[N];
void cycle(int u, int p){
    if(visit[u]){
        cyc[u] = true;
        int tmp = p;
        while(tmp != u){
            cyc[tmp] = true;
            tmp = pa[tmp];
        }
        return;
    }
    visit[u] = true;
    for(auto [v,i] : vec[u]){
        if(v==p) continue;
        pa[v] = u;
        cycle(v,u);
    }
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
    for(int i=1; i<=V; i++){
        if(cyc[i]){
            dfs(i, -1);
        }
    }
    for(int i=1; i<=E; i++){
        cout << ans[i] << " \n"[i==E];
    }
}
