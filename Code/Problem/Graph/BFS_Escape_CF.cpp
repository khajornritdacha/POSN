//https://codeforces.com/problemset/problem/1611/E1
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;

void TC(){
    int n, K; cin >> n >> K;
    vector<int> dis(n+5, INF), dis2(n+5, INF);
    queue<int> qq;
    vector<vector<int>> G(n+5);

    for(int i = 0; i <= n; i++) dis[i] = INF;
    for(int i = 1; i <= K; i++){
        int u; cin >> u;
        qq.emplace(u);
        dis[u] = 0;
    }
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    while(!qq.empty()){
        int u = qq.front(); qq.pop();
        for(int v : G[u]){
            if(dis[u] + 1 < dis[v]){
                dis[v] = dis[u]+1;
                qq.emplace(v);
            }
        }
    }

    bool ok = false;
    qq.emplace(1);
    dis2[1] = 0;
    while(!qq.empty()){
        int u = qq.front(); qq.pop();
        if(G[u].size() == 1 and u != 1){
            ok = true;
            break;
        }
        for(int v : G[u]){
            if(dis2[u] + 1 < dis[v] and dis2[u] + 1 < dis2[v]){
                dis2[v] = dis2[u] + 1;
                qq.emplace(v);
            }
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) TC();

    return 0;
}