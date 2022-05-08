#include<bits/stdc++.h>
using namespace std;
int V,E,dp[10010];
vector<int> vec[10010];
bool visit[10010];
queue<int> qq;
void topo(int u){
    visit[u] = true;
    for(int v : vec[u]){
        if(!visit[v])
            topo(v);
    }
    qq.emplace(u);
}
main(){
    freopen("longpath.in","r",stdin);
    freopen("longpath.out","w",stdout);
    int mx = 0;
    cin >> V >> E;
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
    }
    for(int i=1; i<=V; i++){
        if(!visit[i])
            topo(i);
    }
    while(!qq.empty()){
        int u = qq.front();
        qq.pop();
        for(int v : vec[u]){
            dp[u] = max(dp[v]+1, dp[u]);
        }
    }
    for(int i=1; i<=V; i++){
        mx = max(mx, dp[i]);
    }
    cout << mx << "\n";
}
