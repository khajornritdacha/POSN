#include<bits/stdc++.h>
using namespace std;
const int mxn = 3e5+10;
int V,E,dp[mxn][30],ans;
char cha[mxn];
vector<int> visit;
vector<vector<int>> vec;
queue<int> qq;
bool cycle(int u){
    if(visit[u] == 1)
        return true;
    if(visit[u] == 2)
        return false;
    visit[u] = 1;
    for(int v : vec[u]){
        if(cycle(v))
            return true;
    }
    visit[u] = 2;
    return false;
}
void topo(int u){
    visit[u] = true;
    for(int v : vec[u]){
        if(!visit[v])
            topo(v);
    }
    qq.push(u);
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E;
    visit.resize(V+1);
    vec.resize(V+1);
    for(int i=1; i<=V; i++){
        cin >> cha[i];
    }
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
    }
    for(int i=1; i<=V; i++){
        if(visit[i] == 0){
            if(cycle(i)){
                cout << "-1\n";
                return 0;
            }
        }
    }
    visit.clear();
    visit.resize(V+1, 0);
    for(int i=1; i<=V; i++){
        if(!visit[i]){
            topo(i);
        }
    }
    ///Must do topo sort first!!!
    while(!qq.empty()){
        int u = qq.front();
        qq.pop();
        //cout << u << " ";
        for(int v : vec[u]){
            for(int c=0; c<=25; c++){
                dp[u][c] = max(dp[u][c], dp[v][c]);
            }
        }
        dp[u][cha[u]-'a']++;
    }
    for(int i=1; i<=V; i++){
        for(int c=0; c<=25; c++){
            ans = max(ans, dp[i][c]);
        }
    }
    cout << ans << "\n";
}
